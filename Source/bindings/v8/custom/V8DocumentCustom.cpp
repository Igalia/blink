/*
 * Copyright (C) 2007-2009 Google Inc. All rights reserved.
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

#include "config.h"
#include "V8Document.h"

#include "V8CanvasRenderingContext2D.h"
#include "V8DOMImplementation.h"
#include "V8Node.h"
#include "V8Touch.h"
#include "V8TouchList.h"
#include "V8WebGLRenderingContext.h"
#include "V8XPathNSResolver.h"
#include "V8XPathResult.h"
#include "bindings/v8/ExceptionState.h"
#include "bindings/v8/ScriptController.h"
#include "bindings/v8/V8Binding.h"
#include "bindings/v8/V8DOMWrapper.h"
#include "bindings/v8/custom/V8CustomXPathNSResolver.h"
#include "core/dom/Document.h"
#include "core/dom/ExceptionCode.h"
#include "core/dom/Node.h"
#include "core/dom/TouchList.h"
#include "core/html/canvas/CanvasRenderingContext.h"
#include "core/frame/Frame.h"
#include "core/xml/DocumentXPathEvaluator.h"
#include "core/xml/XPathNSResolver.h"
#include "core/xml/XPathResult.h"
#include "wtf/RefPtr.h"

namespace WebCore {

void V8Document::evaluateMethodCustom(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    RefPtr<Document> document = V8Document::toNative(info.Holder());
    ExceptionState exceptionState(ExceptionState::ExecutionContext, "evaluate", "Document", info.Holder(), info.GetIsolate());
    V8TRYCATCH_FOR_V8STRINGRESOURCE_VOID(V8StringResource<>, expression, info[0]);
    RefPtr<Node> contextNode;
    if (V8Node::hasInstance(info[1], info.GetIsolate(), worldType(info.GetIsolate())))
        contextNode = V8Node::toNative(v8::Handle<v8::Object>::Cast(info[1]));

    RefPtr<XPathNSResolver> resolver = toXPathNSResolver(info[2], info.GetIsolate());
    if (!resolver && !info[2]->IsNull() && !info[2]->IsUndefined()) {
        setDOMException(TypeMismatchError, info.GetIsolate());
        return;
    }

    int type = toInt32(info[3]);
    RefPtr<XPathResult> inResult;
    if (V8XPathResult::hasInstance(info[4], info.GetIsolate(), worldType(info.GetIsolate())))
        inResult = V8XPathResult::toNative(v8::Handle<v8::Object>::Cast(info[4]));

    V8TRYCATCH_VOID(RefPtr<XPathResult>, result, DocumentXPathEvaluator::evaluate(document.get(), expression, contextNode.get(), resolver.release(), type, inResult.get(), exceptionState));
    if (exceptionState.throwIfNeeded())
        return;

    v8SetReturnValueFast(info, result.release(), document.get());
}

} // namespace WebCore
