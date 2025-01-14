/*
 * Copyright (C) 2013 Google Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *     * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *     * Neither the name of Google Inc. nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

// This file has been auto-generated by code_generator_v8.pm. DO NOT MODIFY!

#include "config.h"
#include "V8TestInterfaceCheckSecurity.h"

#include "RuntimeEnabledFeatures.h"
#include "bindings/v8/BindingSecurity.h"
#include "bindings/v8/ExceptionMessages.h"
#include "bindings/v8/ExceptionState.h"
#include "bindings/v8/V8DOMConfiguration.h"
#include "core/dom/ContextFeatures.h"
#include "core/dom/Document.h"
#include "platform/TraceEvent.h"

namespace WebCore {

static void initializeScriptWrappableForInterface(TestInterfaceCheckSecurity* object)
{
    if (ScriptWrappable::wrapperCanBeStoredInObject(object))
        ScriptWrappable::setTypeInfoInObject(object, &V8TestInterfaceCheckSecurity::wrapperTypeInfo);
    else
        ASSERT_NOT_REACHED();
}

} // namespace WebCore

// In ScriptWrappable::init, the use of a local function declaration has an issue on Windows:
// the local declaration does not pick up the surrounding namespace. Therefore, we provide this function
// in the global namespace.
// (More info on the MSVC bug here: http://connect.microsoft.com/VisualStudio/feedback/details/664619/the-namespace-of-local-function-declarations-in-c)
void webCoreInitializeScriptWrappableForInterface(WebCore::TestInterfaceCheckSecurity* object)
{
    WebCore::initializeScriptWrappableForInterface(object);
}

namespace WebCore {
const WrapperTypeInfo V8TestInterfaceCheckSecurity::wrapperTypeInfo = { gin::kEmbedderBlink, V8TestInterfaceCheckSecurity::domTemplate, V8TestInterfaceCheckSecurity::derefObject, 0, 0, 0, V8TestInterfaceCheckSecurity::installPerContextEnabledMethods, 0, WrapperTypeObjectPrototype };

namespace TestInterfaceCheckSecurityV8Internal {

template <typename T> void V8_USE(T) { }

static void longAttributeAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TestInterfaceCheckSecurity* imp = V8TestInterfaceCheckSecurity::toNative(info.Holder());
    v8SetReturnValueInt(info, imp->longAttribute());
}

static void longAttributeAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    TestInterfaceCheckSecurityV8Internal::longAttributeAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "Execution");
}

static void doNotCheckSecurityLongAttributeAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TestInterfaceCheckSecurity* imp = V8TestInterfaceCheckSecurity::toNative(info.Holder());
    v8SetReturnValueInt(info, imp->doNotCheckSecurityLongAttribute());
}

static void doNotCheckSecurityLongAttributeAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    TestInterfaceCheckSecurityV8Internal::doNotCheckSecurityLongAttributeAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "Execution");
}

static void doNotCheckSecurityLongAttributeAttributeSetter(v8::Local<v8::Value> jsValue, const v8::PropertyCallbackInfo<void>& info)
{
    TestInterfaceCheckSecurity* imp = V8TestInterfaceCheckSecurity::toNative(info.Holder());
    V8TRYCATCH_VOID(int, cppValue, toInt32(jsValue));
    imp->setDoNotCheckSecurityLongAttribute(cppValue);
}

static void doNotCheckSecurityLongAttributeAttributeSetterCallback(v8::Local<v8::String>, v8::Local<v8::Value> jsValue, const v8::PropertyCallbackInfo<void>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMSetter");
    TestInterfaceCheckSecurityV8Internal::doNotCheckSecurityLongAttributeAttributeSetter(jsValue, info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "Execution");
}

static void doNotCheckSecurityReadonlyLongAttributeAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TestInterfaceCheckSecurity* imp = V8TestInterfaceCheckSecurity::toNative(info.Holder());
    v8SetReturnValueInt(info, imp->doNotCheckSecurityReadonlyLongAttribute());
}

static void doNotCheckSecurityReadonlyLongAttributeAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    TestInterfaceCheckSecurityV8Internal::doNotCheckSecurityReadonlyLongAttributeAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "Execution");
}

static void doNotCheckSecurityOnSetterLongAttributeAttributeGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TestInterfaceCheckSecurity* imp = V8TestInterfaceCheckSecurity::toNative(info.Holder());
    v8SetReturnValueInt(info, imp->doNotCheckSecurityOnSetterLongAttribute());
}

static void doNotCheckSecurityOnSetterLongAttributeAttributeGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    TestInterfaceCheckSecurityV8Internal::doNotCheckSecurityOnSetterLongAttributeAttributeGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "Execution");
}

static void doNotCheckSecurityOnSetterLongAttributeAttributeSetter(v8::Local<v8::Value> jsValue, const v8::PropertyCallbackInfo<void>& info)
{
    TestInterfaceCheckSecurity* imp = V8TestInterfaceCheckSecurity::toNative(info.Holder());
    V8TRYCATCH_VOID(int, cppValue, toInt32(jsValue));
    imp->setDoNotCheckSecurityOnSetterLongAttribute(cppValue);
}

static void doNotCheckSecurityOnSetterLongAttributeAttributeSetterCallback(v8::Local<v8::String>, v8::Local<v8::Value> jsValue, const v8::PropertyCallbackInfo<void>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMSetter");
    TestInterfaceCheckSecurityV8Internal::doNotCheckSecurityOnSetterLongAttributeAttributeSetter(jsValue, info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "Execution");
}

bool indexedSecurityCheck(v8::Local<v8::Object> host, uint32_t index, v8::AccessType type, v8::Local<v8::Value>)
{
    TestInterfaceCheckSecurity* imp =  V8TestInterfaceCheckSecurity::toNative(host);
    return BindingSecurity::shouldAllowAccessToFrame(imp->frame(), DoNotReportSecurityError);
}

bool namedSecurityCheck(v8::Local<v8::Object> host, v8::Local<v8::Value> key, v8::AccessType type, v8::Local<v8::Value>)
{
    TestInterfaceCheckSecurity* imp =  V8TestInterfaceCheckSecurity::toNative(host);
    return BindingSecurity::shouldAllowAccessToFrame(imp->frame(), DoNotReportSecurityError);
}

static void voidMethodMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    ExceptionState exceptionState(ExceptionState::ExecutionContext, "voidMethod", "TestInterfaceCheckSecurity", info.Holder(), info.GetIsolate());
    TestInterfaceCheckSecurity* imp = V8TestInterfaceCheckSecurity::toNative(info.Holder());
    if (!BindingSecurity::shouldAllowAccessToFrame(imp->frame(), exceptionState)) {
        exceptionState.throwIfNeeded();
        return;
    }
    imp->voidMethod();
}

static void voidMethodMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMMethod");
    TestInterfaceCheckSecurityV8Internal::voidMethodMethod(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "Execution");
}

static void doNotCheckSecurityVoidMethodMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TestInterfaceCheckSecurity* imp = V8TestInterfaceCheckSecurity::toNative(info.Holder());
    imp->doNotCheckSecurityVoidMethod();
}

static void doNotCheckSecurityVoidMethodMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMMethod");
    TestInterfaceCheckSecurityV8Internal::doNotCheckSecurityVoidMethodMethod(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "Execution");
}

static void doNotCheckSecurityVoidMethodOriginSafeMethodGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    // This is only for getting a unique pointer which we can pass to privateTemplate.
    static int privateTemplateUniqueKey;
    WrapperWorldType currentWorldType = worldType(info.GetIsolate());
    V8PerIsolateData* data = V8PerIsolateData::from(info.GetIsolate());
    v8::Handle<v8::FunctionTemplate> privateTemplate = data->privateTemplate(currentWorldType, &privateTemplateUniqueKey, TestInterfaceCheckSecurityV8Internal::doNotCheckSecurityVoidMethodMethodCallback, v8Undefined(), v8::Signature::New(info.GetIsolate(), V8PerIsolateData::from(info.GetIsolate())->rawDOMTemplate(&V8TestInterfaceCheckSecurity::wrapperTypeInfo, currentWorldType)), 0);

    v8::Handle<v8::Object> holder = info.This()->FindInstanceInPrototypeChain(V8TestInterfaceCheckSecurity::domTemplate(info.GetIsolate(), currentWorldType));
    if (holder.IsEmpty()) {
        // This is only reachable via |object.__proto__.func|, in which case it
        // has already passed the same origin security check
        v8SetReturnValue(info, privateTemplate->GetFunction());
        return;
    }
    TestInterfaceCheckSecurity* imp = V8TestInterfaceCheckSecurity::toNative(holder);
    if (!BindingSecurity::shouldAllowAccessToFrame(imp->frame(), DoNotReportSecurityError)) {
        static int sharedTemplateUniqueKey;
        v8::Handle<v8::FunctionTemplate> sharedTemplate = data->privateTemplate(currentWorldType, &sharedTemplateUniqueKey, TestInterfaceCheckSecurityV8Internal::doNotCheckSecurityVoidMethodMethodCallback, v8Undefined(), v8::Signature::New(info.GetIsolate(), V8PerIsolateData::from(info.GetIsolate())->rawDOMTemplate(&V8TestInterfaceCheckSecurity::wrapperTypeInfo, currentWorldType)), 0);
        v8SetReturnValue(info, sharedTemplate->GetFunction());
        return;
    }

    v8::Local<v8::Value> hiddenValue = info.This()->GetHiddenValue(v8::String::NewFromUtf8(info.GetIsolate(), "doNotCheckSecurityVoidMethod", v8::String::kInternalizedString));
    if (!hiddenValue.IsEmpty()) {
        v8SetReturnValue(info, hiddenValue);
        return;
    }

    v8SetReturnValue(info, privateTemplate->GetFunction());
}

static void doNotCheckSecurityVoidMethodOriginSafeMethodGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    TestInterfaceCheckSecurityV8Internal::doNotCheckSecurityVoidMethodOriginSafeMethodGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "Execution");
}

static void doNotCheckSecurityPerWorldBindingsVoidMethodMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TestInterfaceCheckSecurity* imp = V8TestInterfaceCheckSecurity::toNative(info.Holder());
    imp->doNotCheckSecurityPerWorldBindingsVoidMethod();
}

static void doNotCheckSecurityPerWorldBindingsVoidMethodMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMMethod");
    TestInterfaceCheckSecurityV8Internal::doNotCheckSecurityPerWorldBindingsVoidMethodMethod(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "Execution");
}

static void doNotCheckSecurityPerWorldBindingsVoidMethodOriginSafeMethodGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    // This is only for getting a unique pointer which we can pass to privateTemplate.
    static int privateTemplateUniqueKey;
    WrapperWorldType currentWorldType = worldType(info.GetIsolate());
    V8PerIsolateData* data = V8PerIsolateData::from(info.GetIsolate());
    v8::Handle<v8::FunctionTemplate> privateTemplate = data->privateTemplate(currentWorldType, &privateTemplateUniqueKey, TestInterfaceCheckSecurityV8Internal::doNotCheckSecurityPerWorldBindingsVoidMethodMethodCallback, v8Undefined(), v8::Signature::New(info.GetIsolate(), V8PerIsolateData::from(info.GetIsolate())->rawDOMTemplate(&V8TestInterfaceCheckSecurity::wrapperTypeInfo, currentWorldType)), 0);

    v8::Handle<v8::Object> holder = info.This()->FindInstanceInPrototypeChain(V8TestInterfaceCheckSecurity::domTemplate(info.GetIsolate(), currentWorldType));
    if (holder.IsEmpty()) {
        // This is only reachable via |object.__proto__.func|, in which case it
        // has already passed the same origin security check
        v8SetReturnValue(info, privateTemplate->GetFunction());
        return;
    }
    TestInterfaceCheckSecurity* imp = V8TestInterfaceCheckSecurity::toNative(holder);
    if (!BindingSecurity::shouldAllowAccessToFrame(imp->frame(), DoNotReportSecurityError)) {
        static int sharedTemplateUniqueKey;
        v8::Handle<v8::FunctionTemplate> sharedTemplate = data->privateTemplate(currentWorldType, &sharedTemplateUniqueKey, TestInterfaceCheckSecurityV8Internal::doNotCheckSecurityPerWorldBindingsVoidMethodMethodCallback, v8Undefined(), v8::Signature::New(info.GetIsolate(), V8PerIsolateData::from(info.GetIsolate())->rawDOMTemplate(&V8TestInterfaceCheckSecurity::wrapperTypeInfo, currentWorldType)), 0);
        v8SetReturnValue(info, sharedTemplate->GetFunction());
        return;
    }

    v8::Local<v8::Value> hiddenValue = info.This()->GetHiddenValue(v8::String::NewFromUtf8(info.GetIsolate(), "doNotCheckSecurityPerWorldBindingsVoidMethod", v8::String::kInternalizedString));
    if (!hiddenValue.IsEmpty()) {
        v8SetReturnValue(info, hiddenValue);
        return;
    }

    v8SetReturnValue(info, privateTemplate->GetFunction());
}

static void doNotCheckSecurityPerWorldBindingsVoidMethodOriginSafeMethodGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    TestInterfaceCheckSecurityV8Internal::doNotCheckSecurityPerWorldBindingsVoidMethodOriginSafeMethodGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "Execution");
}

static void doNotCheckSecurityPerWorldBindingsVoidMethodMethodForMainWorld(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TestInterfaceCheckSecurity* imp = V8TestInterfaceCheckSecurity::toNative(info.Holder());
    imp->doNotCheckSecurityPerWorldBindingsVoidMethod();
}

static void doNotCheckSecurityPerWorldBindingsVoidMethodMethodCallbackForMainWorld(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMMethod");
    TestInterfaceCheckSecurityV8Internal::doNotCheckSecurityPerWorldBindingsVoidMethodMethodForMainWorld(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "Execution");
}

static void doNotCheckSecurityPerWorldBindingsVoidMethodOriginSafeMethodGetterForMainWorld(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    // This is only for getting a unique pointer which we can pass to privateTemplate.
    static int privateTemplateUniqueKey;
    WrapperWorldType currentWorldType = worldType(info.GetIsolate());
    V8PerIsolateData* data = V8PerIsolateData::from(info.GetIsolate());
    v8::Handle<v8::FunctionTemplate> privateTemplate = data->privateTemplate(currentWorldType, &privateTemplateUniqueKey, TestInterfaceCheckSecurityV8Internal::doNotCheckSecurityPerWorldBindingsVoidMethodMethodCallbackForMainWorld, v8Undefined(), v8::Signature::New(info.GetIsolate(), V8PerIsolateData::from(info.GetIsolate())->rawDOMTemplate(&V8TestInterfaceCheckSecurity::wrapperTypeInfo, currentWorldType)), 0);

    v8::Handle<v8::Object> holder = info.This()->FindInstanceInPrototypeChain(V8TestInterfaceCheckSecurity::domTemplate(info.GetIsolate(), currentWorldType));
    if (holder.IsEmpty()) {
        // This is only reachable via |object.__proto__.func|, in which case it
        // has already passed the same origin security check
        v8SetReturnValue(info, privateTemplate->GetFunction());
        return;
    }
    TestInterfaceCheckSecurity* imp = V8TestInterfaceCheckSecurity::toNative(holder);
    if (!BindingSecurity::shouldAllowAccessToFrame(imp->frame(), DoNotReportSecurityError)) {
        static int sharedTemplateUniqueKey;
        v8::Handle<v8::FunctionTemplate> sharedTemplate = data->privateTemplate(currentWorldType, &sharedTemplateUniqueKey, TestInterfaceCheckSecurityV8Internal::doNotCheckSecurityPerWorldBindingsVoidMethodMethodCallbackForMainWorld, v8Undefined(), v8::Signature::New(info.GetIsolate(), V8PerIsolateData::from(info.GetIsolate())->rawDOMTemplate(&V8TestInterfaceCheckSecurity::wrapperTypeInfo, currentWorldType)), 0);
        v8SetReturnValue(info, sharedTemplate->GetFunction());
        return;
    }

    v8::Local<v8::Value> hiddenValue = info.This()->GetHiddenValue(v8::String::NewFromUtf8(info.GetIsolate(), "doNotCheckSecurityPerWorldBindingsVoidMethod", v8::String::kInternalizedString));
    if (!hiddenValue.IsEmpty()) {
        v8SetReturnValue(info, hiddenValue);
        return;
    }

    v8SetReturnValue(info, privateTemplate->GetFunction());
}

static void doNotCheckSecurityPerWorldBindingsVoidMethodOriginSafeMethodGetterCallbackForMainWorld(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    TestInterfaceCheckSecurityV8Internal::doNotCheckSecurityPerWorldBindingsVoidMethodOriginSafeMethodGetterForMainWorld(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "Execution");
}

static void doNotCheckSecurityReadOnlyVoidMethodMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TestInterfaceCheckSecurity* imp = V8TestInterfaceCheckSecurity::toNative(info.Holder());
    imp->doNotCheckSecurityReadOnlyVoidMethod();
}

static void doNotCheckSecurityReadOnlyVoidMethodMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMMethod");
    TestInterfaceCheckSecurityV8Internal::doNotCheckSecurityReadOnlyVoidMethodMethod(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "Execution");
}

static void doNotCheckSecurityReadOnlyVoidMethodOriginSafeMethodGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    // This is only for getting a unique pointer which we can pass to privateTemplate.
    static int privateTemplateUniqueKey;
    WrapperWorldType currentWorldType = worldType(info.GetIsolate());
    V8PerIsolateData* data = V8PerIsolateData::from(info.GetIsolate());
    v8::Handle<v8::FunctionTemplate> privateTemplate = data->privateTemplate(currentWorldType, &privateTemplateUniqueKey, TestInterfaceCheckSecurityV8Internal::doNotCheckSecurityReadOnlyVoidMethodMethodCallback, v8Undefined(), v8::Signature::New(info.GetIsolate(), V8PerIsolateData::from(info.GetIsolate())->rawDOMTemplate(&V8TestInterfaceCheckSecurity::wrapperTypeInfo, currentWorldType)), 0);

    v8::Handle<v8::Object> holder = info.This()->FindInstanceInPrototypeChain(V8TestInterfaceCheckSecurity::domTemplate(info.GetIsolate(), currentWorldType));
    if (holder.IsEmpty()) {
        // This is only reachable via |object.__proto__.func|, in which case it
        // has already passed the same origin security check
        v8SetReturnValue(info, privateTemplate->GetFunction());
        return;
    }
    TestInterfaceCheckSecurity* imp = V8TestInterfaceCheckSecurity::toNative(holder);
    if (!BindingSecurity::shouldAllowAccessToFrame(imp->frame(), DoNotReportSecurityError)) {
        static int sharedTemplateUniqueKey;
        v8::Handle<v8::FunctionTemplate> sharedTemplate = data->privateTemplate(currentWorldType, &sharedTemplateUniqueKey, TestInterfaceCheckSecurityV8Internal::doNotCheckSecurityReadOnlyVoidMethodMethodCallback, v8Undefined(), v8::Signature::New(info.GetIsolate(), V8PerIsolateData::from(info.GetIsolate())->rawDOMTemplate(&V8TestInterfaceCheckSecurity::wrapperTypeInfo, currentWorldType)), 0);
        v8SetReturnValue(info, sharedTemplate->GetFunction());
        return;
    }

    v8::Local<v8::Value> hiddenValue = info.This()->GetHiddenValue(v8::String::NewFromUtf8(info.GetIsolate(), "doNotCheckSecurityReadOnlyVoidMethod", v8::String::kInternalizedString));
    if (!hiddenValue.IsEmpty()) {
        v8SetReturnValue(info, hiddenValue);
        return;
    }

    v8SetReturnValue(info, privateTemplate->GetFunction());
}

static void doNotCheckSecurityReadOnlyVoidMethodOriginSafeMethodGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    TestInterfaceCheckSecurityV8Internal::doNotCheckSecurityReadOnlyVoidMethodOriginSafeMethodGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "Execution");
}

static void doNotCheckSecurityUnforgeableVoidMethodMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TestInterfaceCheckSecurity* imp = V8TestInterfaceCheckSecurity::toNative(info.Holder());
    imp->doNotCheckSecurityUnforgeableVoidMethod();
}

static void doNotCheckSecurityUnforgeableVoidMethodMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMMethod");
    TestInterfaceCheckSecurityV8Internal::doNotCheckSecurityUnforgeableVoidMethodMethod(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "Execution");
}

static void doNotCheckSecurityUnforgeableVoidMethodOriginSafeMethodGetter(const v8::PropertyCallbackInfo<v8::Value>& info)
{
    // This is only for getting a unique pointer which we can pass to privateTemplate.
    static int privateTemplateUniqueKey;
    WrapperWorldType currentWorldType = worldType(info.GetIsolate());
    V8PerIsolateData* data = V8PerIsolateData::from(info.GetIsolate());
    v8::Handle<v8::FunctionTemplate> privateTemplate = data->privateTemplate(currentWorldType, &privateTemplateUniqueKey, TestInterfaceCheckSecurityV8Internal::doNotCheckSecurityUnforgeableVoidMethodMethodCallback, v8Undefined(), v8::Signature::New(info.GetIsolate(), V8PerIsolateData::from(info.GetIsolate())->rawDOMTemplate(&V8TestInterfaceCheckSecurity::wrapperTypeInfo, currentWorldType)), 0);

    v8::Handle<v8::Object> holder = info.This()->FindInstanceInPrototypeChain(V8TestInterfaceCheckSecurity::domTemplate(info.GetIsolate(), currentWorldType));
    if (holder.IsEmpty()) {
        // This is only reachable via |object.__proto__.func|, in which case it
        // has already passed the same origin security check
        v8SetReturnValue(info, privateTemplate->GetFunction());
        return;
    }
    TestInterfaceCheckSecurity* imp = V8TestInterfaceCheckSecurity::toNative(holder);
    if (!BindingSecurity::shouldAllowAccessToFrame(imp->frame(), DoNotReportSecurityError)) {
        static int sharedTemplateUniqueKey;
        v8::Handle<v8::FunctionTemplate> sharedTemplate = data->privateTemplate(currentWorldType, &sharedTemplateUniqueKey, TestInterfaceCheckSecurityV8Internal::doNotCheckSecurityUnforgeableVoidMethodMethodCallback, v8Undefined(), v8::Signature::New(info.GetIsolate(), V8PerIsolateData::from(info.GetIsolate())->rawDOMTemplate(&V8TestInterfaceCheckSecurity::wrapperTypeInfo, currentWorldType)), 0);
        v8SetReturnValue(info, sharedTemplate->GetFunction());
        return;
    }

    v8::Local<v8::Value> hiddenValue = info.This()->GetHiddenValue(v8::String::NewFromUtf8(info.GetIsolate(), "doNotCheckSecurityUnforgeableVoidMethod", v8::String::kInternalizedString));
    if (!hiddenValue.IsEmpty()) {
        v8SetReturnValue(info, hiddenValue);
        return;
    }

    v8SetReturnValue(info, privateTemplate->GetFunction());
}

static void doNotCheckSecurityUnforgeableVoidMethodOriginSafeMethodGetterCallback(v8::Local<v8::String>, const v8::PropertyCallbackInfo<v8::Value>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMGetter");
    TestInterfaceCheckSecurityV8Internal::doNotCheckSecurityUnforgeableVoidMethodOriginSafeMethodGetter(info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "Execution");
}

static void TestInterfaceCheckSecurityOriginSafeMethodSetter(v8::Local<v8::String> name, v8::Local<v8::Value> jsValue, const v8::PropertyCallbackInfo<void>& info)
{
    v8::Handle<v8::Object> holder = info.This()->FindInstanceInPrototypeChain(V8TestInterfaceCheckSecurity::domTemplate(info.GetIsolate(), worldType(info.GetIsolate())));
    if (holder.IsEmpty())
        return;
    TestInterfaceCheckSecurity* imp = V8TestInterfaceCheckSecurity::toNative(holder);
    v8::String::Utf8Value attributeName(name);
    ExceptionState exceptionState(ExceptionState::SetterContext, *attributeName, "TestInterfaceCheckSecurity", info.Holder(), info.GetIsolate());
    if (!BindingSecurity::shouldAllowAccessToFrame(imp->frame(), exceptionState)) {
        exceptionState.throwIfNeeded();
        return;
    }

    info.This()->SetHiddenValue(name, jsValue);
}

static void TestInterfaceCheckSecurityOriginSafeMethodSetterCallback(v8::Local<v8::String> name, v8::Local<v8::Value> jsValue, const v8::PropertyCallbackInfo<void>& info)
{
    TRACE_EVENT_SET_SAMPLING_STATE("Blink", "DOMSetter");
    TestInterfaceCheckSecurityV8Internal::TestInterfaceCheckSecurityOriginSafeMethodSetter(name, jsValue, info);
    TRACE_EVENT_SET_SAMPLING_STATE("V8", "Execution");
}

} // namespace TestInterfaceCheckSecurityV8Internal

static const V8DOMConfiguration::AttributeConfiguration V8TestInterfaceCheckSecurityAttributes[] = {
    {"longAttribute", TestInterfaceCheckSecurityV8Internal::longAttributeAttributeGetterCallback, 0, 0, 0, 0, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
    {"doNotCheckSecurityLongAttribute", TestInterfaceCheckSecurityV8Internal::doNotCheckSecurityLongAttributeAttributeGetterCallback, TestInterfaceCheckSecurityV8Internal::doNotCheckSecurityLongAttributeAttributeSetterCallback, 0, 0, 0, static_cast<v8::AccessControl>(v8::ALL_CAN_READ | v8::ALL_CAN_WRITE), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
    {"doNotCheckSecurityReadonlyLongAttribute", TestInterfaceCheckSecurityV8Internal::doNotCheckSecurityReadonlyLongAttributeAttributeGetterCallback, 0, 0, 0, 0, static_cast<v8::AccessControl>(v8::ALL_CAN_READ), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
    {"doNotCheckSecurityOnSetterLongAttribute", TestInterfaceCheckSecurityV8Internal::doNotCheckSecurityOnSetterLongAttributeAttributeGetterCallback, TestInterfaceCheckSecurityV8Internal::doNotCheckSecurityOnSetterLongAttributeAttributeSetterCallback, 0, 0, 0, static_cast<v8::AccessControl>(v8::ALL_CAN_WRITE), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
};

static const V8DOMConfiguration::MethodConfiguration V8TestInterfaceCheckSecurityMethods[] = {
    {"voidMethod", TestInterfaceCheckSecurityV8Internal::voidMethodMethodCallback, 0, 0},
};

static v8::Handle<v8::FunctionTemplate> ConfigureV8TestInterfaceCheckSecurityTemplate(v8::Handle<v8::FunctionTemplate> functionTemplate, v8::Isolate* isolate, WrapperWorldType currentWorldType)
{
    functionTemplate->ReadOnlyPrototype();

    v8::Local<v8::Signature> defaultSignature;
    defaultSignature = V8DOMConfiguration::installDOMClassTemplate(functionTemplate, "TestInterfaceCheckSecurity", v8::Local<v8::FunctionTemplate>(), V8TestInterfaceCheckSecurity::internalFieldCount,
        V8TestInterfaceCheckSecurityAttributes, WTF_ARRAY_LENGTH(V8TestInterfaceCheckSecurityAttributes),
        0, 0,
        V8TestInterfaceCheckSecurityMethods, WTF_ARRAY_LENGTH(V8TestInterfaceCheckSecurityMethods),
        isolate, currentWorldType);
    v8::Local<v8::ObjectTemplate> ALLOW_UNUSED instanceTemplate = functionTemplate->InstanceTemplate();
    v8::Local<v8::ObjectTemplate> ALLOW_UNUSED prototypeTemplate = functionTemplate->PrototypeTemplate();
    instanceTemplate->SetAccessCheckCallbacks(TestInterfaceCheckSecurityV8Internal::namedSecurityCheck, TestInterfaceCheckSecurityV8Internal::indexedSecurityCheck, v8::External::New(isolate, const_cast<WrapperTypeInfo*>(&V8TestInterfaceCheckSecurity::wrapperTypeInfo)));
    prototypeTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "doNotCheckSecurityVoidMethod", v8::String::kInternalizedString), TestInterfaceCheckSecurityV8Internal::doNotCheckSecurityVoidMethodOriginSafeMethodGetterCallback, TestInterfaceCheckSecurityV8Internal::TestInterfaceCheckSecurityOriginSafeMethodSetterCallback, v8Undefined(), v8::ALL_CAN_READ, static_cast<v8::PropertyAttribute>(v8::DontDelete));
    if (currentWorldType == MainWorld) {
        prototypeTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "doNotCheckSecurityPerWorldBindingsVoidMethod", v8::String::kInternalizedString), TestInterfaceCheckSecurityV8Internal::doNotCheckSecurityPerWorldBindingsVoidMethodOriginSafeMethodGetterCallbackForMainWorld, TestInterfaceCheckSecurityV8Internal::TestInterfaceCheckSecurityOriginSafeMethodSetterCallback, v8Undefined(), v8::ALL_CAN_READ, static_cast<v8::PropertyAttribute>(v8::DontDelete));
    } else {
        prototypeTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "doNotCheckSecurityPerWorldBindingsVoidMethod", v8::String::kInternalizedString), TestInterfaceCheckSecurityV8Internal::doNotCheckSecurityPerWorldBindingsVoidMethodOriginSafeMethodGetterCallback, TestInterfaceCheckSecurityV8Internal::TestInterfaceCheckSecurityOriginSafeMethodSetterCallback, v8Undefined(), v8::ALL_CAN_READ, static_cast<v8::PropertyAttribute>(v8::DontDelete));
    }
    prototypeTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "doNotCheckSecurityReadOnlyVoidMethod", v8::String::kInternalizedString), TestInterfaceCheckSecurityV8Internal::doNotCheckSecurityReadOnlyVoidMethodOriginSafeMethodGetterCallback, 0, v8Undefined(), v8::ALL_CAN_READ, static_cast<v8::PropertyAttribute>(v8::DontDelete | v8::ReadOnly));
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "doNotCheckSecurityUnforgeableVoidMethod", v8::String::kInternalizedString), TestInterfaceCheckSecurityV8Internal::doNotCheckSecurityUnforgeableVoidMethodOriginSafeMethodGetterCallback, TestInterfaceCheckSecurityV8Internal::TestInterfaceCheckSecurityOriginSafeMethodSetterCallback, v8Undefined(), v8::ALL_CAN_READ, static_cast<v8::PropertyAttribute>(v8::DontDelete));

    // Custom toString template
    functionTemplate->Set(v8::String::NewFromUtf8(isolate, "toString", v8::String::kInternalizedString), V8PerIsolateData::current()->toStringTemplate());
    return functionTemplate;
}

v8::Handle<v8::FunctionTemplate> V8TestInterfaceCheckSecurity::domTemplate(v8::Isolate* isolate, WrapperWorldType currentWorldType)
{
    V8PerIsolateData* data = V8PerIsolateData::from(isolate);
    V8PerIsolateData::TemplateMap::iterator result = data->templateMap(currentWorldType).find(&wrapperTypeInfo);
    if (result != data->templateMap(currentWorldType).end())
        return result->value.newLocal(isolate);

    TRACE_EVENT_SCOPED_SAMPLING_STATE("Blink", "BuildDOMTemplate");
    v8::EscapableHandleScope handleScope(isolate);
    v8::Local<v8::FunctionTemplate> templ =
        ConfigureV8TestInterfaceCheckSecurityTemplate(data->rawDOMTemplate(&wrapperTypeInfo, currentWorldType), isolate, currentWorldType);
    data->templateMap(currentWorldType).add(&wrapperTypeInfo, UnsafePersistent<v8::FunctionTemplate>(isolate, templ));
    return handleScope.Escape(templ);
}

bool V8TestInterfaceCheckSecurity::hasInstance(v8::Handle<v8::Value> jsValue, v8::Isolate* isolate, WrapperWorldType currentWorldType)
{
    return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, jsValue, currentWorldType);
}

bool V8TestInterfaceCheckSecurity::hasInstanceInAnyWorld(v8::Handle<v8::Value> jsValue, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, jsValue, MainWorld)
        || V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, jsValue, IsolatedWorld)
        || V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, jsValue, WorkerWorld);
}

v8::Handle<v8::Object> V8TestInterfaceCheckSecurity::createWrapper(PassRefPtr<TestInterfaceCheckSecurity> impl, v8::Handle<v8::Object> creationContext, v8::Isolate* isolate)
{
    ASSERT(impl);
    ASSERT(!DOMDataStore::containsWrapper<V8TestInterfaceCheckSecurity>(impl.get(), isolate));
    if (ScriptWrappable::wrapperCanBeStoredInObject(impl.get())) {
        const WrapperTypeInfo* actualInfo = ScriptWrappable::getTypeInfoFromObject(impl.get());
        // Might be a XXXConstructor::wrapperTypeInfo instead of an XXX::wrapperTypeInfo. These will both have
        // the same object de-ref functions, though, so use that as the basis of the check.
        RELEASE_ASSERT_WITH_SECURITY_IMPLICATION(actualInfo->derefObjectFunction == wrapperTypeInfo.derefObjectFunction);
    }

    v8::Handle<v8::Object> wrapper = V8DOMWrapper::createWrapper(creationContext, &wrapperTypeInfo, toInternalPointer(impl.get()), isolate);
    if (UNLIKELY(wrapper.IsEmpty()))
        return wrapper;

    installPerContextEnabledProperties(wrapper, impl.get(), isolate);
    V8DOMWrapper::associateObjectWithWrapper<V8TestInterfaceCheckSecurity>(impl, &wrapperTypeInfo, wrapper, isolate, WrapperConfiguration::Independent);
    return wrapper;
}

void V8TestInterfaceCheckSecurity::derefObject(void* object)
{
    fromInternalPointer(object)->deref();
}

template<>
v8::Handle<v8::Value> toV8NoInline(TestInterfaceCheckSecurity* impl, v8::Handle<v8::Object> creationContext, v8::Isolate* isolate)
{
    return toV8(impl, creationContext, isolate);
}

} // namespace WebCore
