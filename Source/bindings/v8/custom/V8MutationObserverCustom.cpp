/*
 * Copyright (C) 2011 Google Inc. All rights reserved.
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
#include "V8MutationObserver.h"

#include "bindings/v8/ExceptionMessages.h"
#include "bindings/v8/V8Binding.h"
#include "bindings/v8/V8DOMWrapper.h"
#include "bindings/v8/V8MutationCallback.h"
#include "bindings/v8/V8Utilities.h"
#include "core/dom/MutationObserver.h"

namespace WebCore {

void V8MutationObserver::constructorCustom(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    if (info.Length() < 1) {
        throwTypeError(ExceptionMessages::failedToConstruct("MutationObserver", ExceptionMessages::notEnoughArguments(1, info.Length())), info.GetIsolate());
        return;
    }

    v8::Local<v8::Value> arg = info[0];
    if (!arg->IsFunction()) {
        throwTypeError("Callback argument must be a function", info.GetIsolate());
        return;
    }

    ExecutionContext* context = getExecutionContext();
    v8::Handle<v8::Object> wrapper = info.Holder();

    OwnPtr<MutationCallback> callback = V8MutationCallback::create(v8::Handle<v8::Function>::Cast(arg), context, wrapper, info.GetIsolate());
    RefPtr<MutationObserver> observer = MutationObserver::create(callback.release());

    V8DOMWrapper::associateObjectWithWrapper<V8MutationObserver>(observer.release(), &wrapperTypeInfo, wrapper, info.GetIsolate(), WrapperConfiguration::Dependent);
    info.GetReturnValue().Set(wrapper);
}

} // namespace WebCore
