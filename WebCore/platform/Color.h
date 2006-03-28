/*
 * Copyright (C) 2003-6 Apple Computer, Inc.  All rights reserved.
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

#ifndef COLOR_H_
#define COLOR_H_

class DeprecatedString;

#if __APPLE__
#ifdef __OBJC__
@class NSColor;
#else
class NSColor;
#endif

typedef struct CGColor *CGColorRef;
#endif

namespace WebCore {

class String;

typedef unsigned int RGBA32;                      // RGBA quadruplet

RGBA32 makeRGB(int r, int g, int b);
RGBA32 makeRGBA(int r, int g, int b, int a);

class Color {
public:
    Color() : color(0), valid(false) { }
    Color(RGBA32 col) : color(col), valid(true) { }
    Color(int r, int g, int b) : color(makeRGB(r, g, b)), valid(true) { }
    Color(int r, int g, int b, int a) : color(makeRGBA(r, g, b, a)), valid(true) { }
    explicit Color(const DeprecatedString&);
    explicit Color(const char *);
    
    String name() const;
    void setNamedColor(const DeprecatedString&);

    bool isValid() const { return valid; }

    int red() const { return (color >> 16) & 0xFF; }
    int green() const { return (color >> 8) & 0xFF; }
    int blue() const { return color & 0xFF; }
    int alpha() const { return (color >> 24) & 0xFF; }
    RGBA32 rgb() const { return color & 0xFFFFFFFF; } // Preserve the alpha.
    void setRgb(int r, int g, int b) { color = makeRGB(r, g, b); valid = true; }
    void setRgb(int rgb) { color = rgb; valid = true; /* Alpha may be set. Preserve it. */ }
    void getRgbaF(float *, float *, float *, float *) const;

    void hsv(int *, int *, int *) const;
    void setHsv(int h, int s, int v);

    Color light(int f = 150) const;
    Color dark(int f = 200) const;

    friend bool operator==(const Color &a, const Color &b);
    friend bool operator!=(const Color &a, const Color &b);

    static const RGBA32 black = 0xFF000000;
    static const RGBA32 white = 0xFFFFFFFF;
    static const RGBA32 darkGray = 0xFF808080;
    static const RGBA32 gray = 0xFFA0A0A0;
    static const RGBA32 lightGray = 0xFFC0C0C0;
    static const RGBA32 transparent = 0x00000000;
    
private:
    RGBA32 color;
    bool valid : 1;
};

inline bool operator==(const Color &a, const Color &b)
{
    return a.color == b.color && a.valid == b.valid;
}

inline bool operator!=(const Color &a, const Color &b)
{
    return a.color != b.color || a.valid != b.valid;
}

#if __APPLE__
NSColor *nsColor(const Color &);
CGColorRef cgColor(const Color &);
#endif

}

// FIXME: Remove usings when the rest of KWQ has been converted.
using WebCore::RGBA32;
using WebCore::Color;

#endif
