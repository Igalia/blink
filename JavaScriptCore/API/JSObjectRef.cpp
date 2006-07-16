// -*- mode: c++; c-basic-offset: 4 -*-
/*
 * Copyright (C) 2006 Apple Computer, Inc.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE COMPUTER, INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE COMPUTER, INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. 
 */

#include "APICast.h"
#include "JSValueRef.h"
#include "JSObjectRef.h"
#include "JSCallbackConstructor.h"
#include "JSCallbackFunction.h"
#include "JSCallbackObject.h"
#include "JSClassRef.h"

#include "identifier.h"
#include "function.h"
#include "nodes.h"
#include "internal.h"
#include "object.h"
#include "reference_list.h"

using namespace KJS;

JSClassRef JSClassCreate(JSClassDefinition* definition)
{
    JSClassRef jsClass = new __JSClass(definition);
    return JSClassRetain(jsClass);
}

JSClassRef JSClassRetain(JSClassRef jsClass)
{
    ++jsClass->refCount;
    return jsClass;
}

void JSClassRelease(JSClassRef jsClass)
{
    if (--jsClass->refCount == 0)
        delete jsClass;
}

JSObjectRef JSObjectMake(JSContextRef context, JSClassRef jsClass, JSValueRef prototype)
{
    JSLock lock;

    ExecState* exec = toJS(context);
    JSValue* jsPrototype = toJS(prototype);

    if (!prototype)
        jsPrototype = exec->lexicalInterpreter()->builtinObjectPrototype();

    if (!jsClass)
        return toRef(new JSObject(jsPrototype)); // slightly more efficient
    else
        return toRef(new JSCallbackObject(context, jsClass, jsPrototype));
}

JSObjectRef JSObjectMakeFunction(JSContextRef context, JSObjectCallAsFunctionCallback callAsFunction)
{
    JSLock lock;
    ExecState* exec = toJS(context);
    return toRef(new JSCallbackFunction(exec, callAsFunction));
}

JSObjectRef JSObjectMakeConstructor(JSContextRef context, JSObjectCallAsConstructorCallback callAsConstructor)
{
    JSLock lock;
    ExecState* exec = toJS(context);
    return toRef(new JSCallbackConstructor(exec, callAsConstructor));
}

JSObjectRef JSObjectMakeFunctionWithBody(JSContextRef context, JSStringRef body, JSStringRef sourceURL, int startingLineNumber, JSValueRef* exception)
{
    JSLock lock;
    
    ExecState* exec = toJS(context);
    UString::Rep* bodyRep = toJS(body);
    UString jsSourceURL = UString(toJS(sourceURL));

    if (!bodyRep)
        bodyRep = &UString::Rep::null;
    
    int sid;
    int errLine;
    UString errMsg;
    RefPtr<FunctionBodyNode> bodyNode = Parser::parse(jsSourceURL, startingLineNumber, bodyRep->data(), bodyRep->size(), &sid, &errLine, &errMsg);
    if (!bodyNode) {
        if (exception)
            *exception = toRef(Error::create(exec, SyntaxError, errMsg, errLine, sid, jsSourceURL));
        return 0;
    }

    ScopeChain scopeChain;
    scopeChain.push(exec->dynamicInterpreter()->globalObject());
    return toRef(static_cast<JSObject*>(new DeclaredFunctionImp(exec, "anonymous", bodyNode.get(), scopeChain)));
}

JSValueRef JSObjectGetPrototype(JSObjectRef object)
{
    JSObject* jsObject = toJS(object);
    return toRef(jsObject->prototype());
}

void JSObjectSetPrototype(JSObjectRef object, JSValueRef value)
{
    JSObject* jsObject = toJS(object);
    JSValue* jsValue = toJS(value);

    jsObject->setPrototype(jsValue);
}

bool JSObjectHasProperty(JSContextRef context, JSObjectRef object, JSStringRef propertyName)
{
    JSLock lock;
    ExecState* exec = toJS(context);
    JSObject* jsObject = toJS(object);
    UString::Rep* nameRep = toJS(propertyName);
    
    return jsObject->hasProperty(exec, Identifier(nameRep));
}

JSValueRef JSObjectGetProperty(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    JSLock lock;
    ExecState* exec = toJS(context);
    JSObject* jsObject = toJS(object);
    UString::Rep* nameRep = toJS(propertyName);

    JSValue* jsValue = jsObject->get(exec, Identifier(nameRep));
    if (jsValue->isUndefined())
        jsValue = 0;
    if (exec->hadException()) {
        if (exception)
            *exception = toRef(exec->exception());
        exec->clearException();
    }
    return toRef(jsValue);
}

void JSObjectSetProperty(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef value, JSPropertyAttributes attributes, JSValueRef* exception)
{
    JSLock lock;
    ExecState* exec = toJS(context);
    JSObject* jsObject = toJS(object);
    UString::Rep* nameRep = toJS(propertyName);
    JSValue* jsValue = toJS(value);
    
    jsObject->put(exec, Identifier(nameRep), jsValue, attributes);
    if (exec->hadException()) {
        if (exception)
            *exception = toRef(exec->exception());
        exec->clearException();
    }
}

JSValueRef JSObjectGetPropertyAtIndex(JSContextRef context, JSObjectRef object, unsigned propertyIndex)
{
    JSLock lock;
    ExecState* exec = toJS(context);
    JSObject* jsObject = toJS(object);

    JSValue* jsValue = jsObject->get(exec, propertyIndex);
    if (jsValue->isUndefined())
        return 0;
    return toRef(jsValue);
}


void JSObjectSetPropertyAtIndex(JSContextRef context, JSObjectRef object, unsigned propertyIndex, JSValueRef value)
{
    JSLock lock;
    ExecState* exec = toJS(context);
    JSObject* jsObject = toJS(object);
    JSValue* jsValue = toJS(value);
    
    jsObject->put(exec, propertyIndex, jsValue);
}

bool JSObjectDeleteProperty(JSContextRef context, JSObjectRef object, JSStringRef propertyName, JSValueRef* exception)
{
    JSLock lock;
    ExecState* exec = toJS(context);
    JSObject* jsObject = toJS(object);
    UString::Rep* nameRep = toJS(propertyName);

    bool result = jsObject->deleteProperty(exec, Identifier(nameRep));
    if (exec->hadException()) {
        if (exception)
            *exception = toRef(exec->exception());
        exec->clearException();
    }
    return result;
}

void* JSObjectGetPrivate(JSObjectRef object)
{
    JSObject* jsObject = toJS(object);
    
    if (jsObject->inherits(&JSCallbackObject::info))
        return static_cast<JSCallbackObject*>(jsObject)->getPrivate();
    
    if (jsObject->inherits(&JSCallbackFunction::info))
        return static_cast<JSCallbackFunction*>(jsObject)->getPrivate();
    
    if (jsObject->inherits(&JSCallbackConstructor::info))
        return static_cast<JSCallbackConstructor*>(jsObject)->getPrivate();
    
    return 0;
}

bool JSObjectSetPrivate(JSObjectRef object, void* data)
{
    JSObject* jsObject = toJS(object);
    
    if (jsObject->inherits(&JSCallbackObject::info)) {
        static_cast<JSCallbackObject*>(jsObject)->setPrivate(data);
        return true;
    }
        
    if (jsObject->inherits(&JSCallbackFunction::info)) {
        static_cast<JSCallbackFunction*>(jsObject)->setPrivate(data);
        return true;
    }
        
    if (jsObject->inherits(&JSCallbackConstructor::info)) {
        static_cast<JSCallbackConstructor*>(jsObject)->setPrivate(data);
        return true;
    }
    
    return false;
}

bool JSObjectIsFunction(JSObjectRef object)
{
    JSObject* jsObject = toJS(object);
    return jsObject->implementsCall();
}

JSValueRef JSObjectCallAsFunction(JSContextRef context, JSObjectRef object, JSObjectRef thisObject, size_t argumentCount, JSValueRef arguments[], JSValueRef* exception)
{
    JSLock lock;
    ExecState* exec = toJS(context);
    JSObject* jsObject = toJS(object);
    JSObject* jsThisObject = toJS(thisObject);

    if (!jsThisObject)
        jsThisObject = exec->dynamicInterpreter()->globalObject();
    
    List argList;
    for (size_t i = 0; i < argumentCount; i++)
        argList.append(toJS(arguments[i]));

    JSValueRef result = toRef(jsObject->call(exec, jsThisObject, argList)); // returns NULL if object->implementsCall() is false
    if (exec->hadException()) {
        if (exception)
            *exception = toRef(exec->exception());
        exec->clearException();
        result = 0;
    }
    return result;
}

bool JSObjectIsConstructor(JSObjectRef object)
{
    JSObject* jsObject = toJS(object);
    return jsObject->implementsConstruct();
}

JSObjectRef JSObjectCallAsConstructor(JSContextRef context, JSObjectRef object, size_t argumentCount, JSValueRef arguments[], JSValueRef* exception)
{
    JSLock lock;
    ExecState* exec = toJS(context);
    JSObject* jsObject = toJS(object);
    
    List argList;
    for (size_t i = 0; i < argumentCount; i++)
        argList.append(toJS(arguments[i]));
    
    JSObjectRef result = toRef(jsObject->construct(exec, argList)); // returns NULL if object->implementsCall() is false
    if (exec->hadException()) {
        if (exception)
            *exception = toRef(exec->exception());
        exec->clearException();
        result = 0;
    }
    return result;
}

struct __JSPropertyEnumerator
{
    __JSPropertyEnumerator() : refCount(0), iterator(list.end())
    {
    }
    
    unsigned refCount;
    ReferenceList list;
    ReferenceListIterator iterator;
};

JSPropertyEnumeratorRef JSObjectCreatePropertyEnumerator(JSObjectRef object)
{
    JSLock lock;
    JSObject* jsObject = toJS(object);
    
    JSPropertyEnumeratorRef enumerator = new __JSPropertyEnumerator();
    jsObject->getPropertyList(enumerator->list);
    enumerator->iterator = enumerator->list.begin();
    
    return JSPropertyEnumeratorRetain(enumerator);
}

JSStringRef JSPropertyEnumeratorGetNextName(JSPropertyEnumeratorRef enumerator)
{
    ReferenceListIterator& iterator = enumerator->iterator;
    if (iterator != enumerator->list.end()) {
        JSStringRef result = toRef(iterator->getPropertyName().ustring().rep());
        iterator++;
        return result;
    }
    return 0;
}

JSPropertyEnumeratorRef JSPropertyEnumeratorRetain(JSPropertyEnumeratorRef enumerator)
{
    ++enumerator->refCount;
    return enumerator;
}

void JSPropertyEnumeratorRelease(JSPropertyEnumeratorRef enumerator)
{
    if (--enumerator->refCount == 0)
        delete enumerator;
}

void JSPropertyListAdd(JSPropertyListRef propertyList, JSObjectRef thisObject, JSStringRef propertyName)
{
    JSLock lock;
    ReferenceList* jsPropertyList = toJS(propertyList);
    JSObject* jsObject = toJS(thisObject);
    UString::Rep* rep = toJS(propertyName);
    
    jsPropertyList->append(Reference(jsObject, Identifier(rep)));
}
