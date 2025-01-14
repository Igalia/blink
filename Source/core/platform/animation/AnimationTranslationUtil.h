/*
 * Copyright (C) 2010 Google Inc. All rights reserved.
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

#ifndef AnimationTranslationUtil_h
#define AnimationTranslationUtil_h

#include "platform/graphics/filters/FilterOperations.h"
#include "platform/transforms/TransformOperations.h"
#include "public/platform/WebTransformOperations.h"
#include "wtf/PassOwnPtr.h"

namespace blink {
class WebAnimation;
}

namespace WebCore {

class KeyframeValueList;
class CSSAnimationData;
class FloatSize;


// Translates WebCore animation data into a WebAnimation. If we are unable
// to perform this translation, we return nullptr. This can happen if
//   - a steps timing function is used,
//   - a property other than AnimatedPropertyWebkitTransform, or AnimatedPropertyOpacity is animated, or
//   - a transform animation involves a non-invertable transform.
PassOwnPtr<blink::WebAnimation> createWebAnimation(const KeyframeValueList&, const CSSAnimationData*, int animationId, double timeOffset, const FloatSize& boxSize);

void toWebTransformOperations(const TransformOperations& inOperations, const FloatSize& boxSize, blink::WebTransformOperations* outOperations);

bool toWebFilterOperations(const FilterOperations& inOperations, blink::WebFilterOperations* outOperations);
} // namespace WebCore

#endif // AnimationTranslationUtil_h
