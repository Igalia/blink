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

#include "config.h"
#include "V8BlobCustomHelpers.h"

#include "V8Blob.h"
#include "bindings/v8/Dictionary.h"
#include "bindings/v8/V8Binding.h"
#include "bindings/v8/V8Utilities.h"
#include "bindings/v8/custom/V8ArrayBufferCustom.h"
#include "bindings/v8/custom/V8ArrayBufferViewCustom.h"
#include "core/fileapi/BlobBuilder.h"
#include "wtf/DateMath.h"

namespace WebCore {

namespace V8BlobCustomHelpers {

ParsedProperties::ParsedProperties(bool hasFileProperties)
    : m_endings("transparent")
    , m_hasFileProperties(hasFileProperties)
#ifndef NDEBUG
    , m_hasLastModified(false)
#endif // NDEBUG
{
}

void ParsedProperties::setLastModified(double lastModified)
{
    ASSERT(m_hasFileProperties);
    ASSERT(!m_hasLastModified);
    m_lastModified = lastModified;
#ifndef NDEBUG
    m_hasLastModified = true;
#endif // NDEBUG
}

void ParsedProperties::setDefaultLastModified()
{
    setLastModified(currentTime());
}

bool ParsedProperties::parseBlobPropertyBag(v8::Local<v8::Value> propertyBag, const char* blobClassName, v8::Isolate* isolate)
{
    ASSERT(m_endings == "transparent");

    V8TRYCATCH_RETURN(Dictionary, dictionary, Dictionary(propertyBag, isolate), false);

    V8TRYCATCH_RETURN(bool, containsEndings, dictionary.get("endings", m_endings), false);
    if (containsEndings) {
        if (m_endings != "transparent" && m_endings != "native") {
            throwTypeError(ExceptionMessages::failedToConstruct(blobClassName, "The \"endings\" property must be either \"transparent\" or \"native\"."), isolate);
            return false;
        }
    }

    V8TRYCATCH_RETURN(bool, containsType, dictionary.get("type", m_contentType), false);
    if (containsType) {
        if (!m_contentType.containsOnlyASCII()) {
            throwError(v8SyntaxError, ExceptionMessages::failedToConstruct(blobClassName, "The \"type\" property must consist of ASCII characters."), isolate);
            return false;
        }
        m_contentType = m_contentType.lower();
    }

    if (!m_hasFileProperties)
        return true;

    v8::Local<v8::Value> lastModified;
    V8TRYCATCH_RETURN(bool, containsLastModified, dictionary.get("lastModified", lastModified), false);
    if (containsLastModified) {
        V8TRYCATCH_RETURN(long long, lastModifiedInt, toInt64(lastModified), false);
        setLastModified(static_cast<double>(lastModifiedInt) / msPerSecond);
    } else {
        setDefaultLastModified();
    }

    return true;
}

bool processBlobParts(v8::Local<v8::Object> blobParts, uint32_t blobPartsLength, const String& endings, BlobBuilder& blobBuilder, v8::Isolate* isolate)
{
    ASSERT(endings == "transparent" || endings == "native");

    for (uint32_t i = 0; i < blobPartsLength; ++i) {
        v8::Local<v8::Value> item = blobParts->Get(v8::Uint32::New(i, isolate));
        if (item.IsEmpty())
            return false;

        if (V8ArrayBuffer::hasInstance(item, isolate, worldType(isolate))) {
            ArrayBuffer* arrayBuffer = V8ArrayBuffer::toNative(v8::Handle<v8::Object>::Cast(item));
            ASSERT(arrayBuffer);
            blobBuilder.append(arrayBuffer);
        } else if (V8ArrayBufferView::hasInstance(item, isolate, worldType(isolate))) {
            ArrayBufferView* arrayBufferView = V8ArrayBufferView::toNative(v8::Handle<v8::Object>::Cast(item));
            ASSERT(arrayBufferView);
            blobBuilder.append(arrayBufferView);
        } else if (V8Blob::hasInstance(item, isolate, worldType(isolate))) {
            Blob* blob = V8Blob::toNative(v8::Handle<v8::Object>::Cast(item));
            ASSERT(blob);
            blobBuilder.append(blob);
        } else {
            V8TRYCATCH_FOR_V8STRINGRESOURCE_RETURN(V8StringResource<>, stringValue, item, false);
            blobBuilder.append(stringValue, endings);
        }
    }
    return true;
}

} // namespace V8BlobCustomHelpers

} // namespace WebCore
