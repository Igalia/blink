/*
 * Copyright (C) 2006 Apple Computer, Inc.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1.  Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer. 
 * 2.  Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution. 
 * 3.  Neither the name of Apple Computer, Inc. ("Apple") nor the names of
 *     its contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission. 
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE AND ITS CONTRIBUTORS "AS IS" AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL APPLE OR ITS CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#import "config.h"
#import "WebFormState.h"

#import "DOMElementInternal.h"
#import "Element.h"
#import "FrameMac.h"
#import "WebCoreFrameBridge.h"

namespace WebCore {

PassRefPtr<FormState> FormState::create(PassRefPtr<Element> form, const HashMap<String, String>& values, PassRefPtr<Frame> sourceFrame)
{
    return new FormState(form, values, sourceFrame);
}

PassRefPtr<FormState> FormState::create(DOMElement *form, NSDictionary *values, WebCoreFrameBridge *sourceFrame)
{
    return new FormState(form, values, sourceFrame);
}

FormState::FormState(PassRefPtr<Element> form, const HashMap<String, String>& values, PassRefPtr<Frame> sourceFrame)
    : m_form(form)
    , m_values(values)
    , m_sourceFrame(sourceFrame)
{
}

FormState::FormState(DOMElement *form, NSDictionary *values, WebCoreFrameBridge *sourceFrame)
    : m_form([form _element])
    , m_sourceFrame([sourceFrame impl])
{
    NSEnumerator *keyEnumerator = [values keyEnumerator];
    while (NSString *key = [keyEnumerator nextObject])
        m_values.set(key, [values objectForKey:key]);
}

NSDictionary *FormState::valuesAsNSDictionary() const
{
    NSMutableDictionary *dictionary = [NSMutableDictionary dictionaryWithCapacity:m_values.size()];
    HashMap<String, String>::const_iterator end = m_values.end();
    for (HashMap<String, String>::const_iterator it = m_values.begin(); it != end; ++it)
        [dictionary setObject:it->second forKey:it->first];
    return dictionary;
}

}
