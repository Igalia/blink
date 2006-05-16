/*
 * This file is part of the internal font implementation.  It should not be included by anyone other than
 * FontMac.cpp, FontWin.cpp and Font.cpp.
 *
 * Copyright (C) 2006 Apple Computer, Inc.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 *
 */

#ifndef FontPlatformData_H
#define FontPlatformData_H

#include "StringImpl.h"

// FIXME: This file should probably be split and moved into platform-specific subdirectories.  There's nothing
// "cross-platform" about it.

#ifdef __APPLE__

#ifdef __OBJC__
@class NSFont;
#else
class NSFont;
#endif

namespace WebCore {

struct FontPlatformData {
    FontPlatformData(NSFont* f = 0, bool b = false, bool o = false)
    :font(f), syntheticBold(b), syntheticOblique(o)
    {}

    NSFont *font;
    bool syntheticBold;
    bool syntheticOblique;
    
    unsigned hash() const
    { 
        unsigned hashCodes[2] = { (unsigned)font, syntheticBold << 1 | syntheticOblique };
        return StringImpl::computeHash(reinterpret_cast<UChar*>(hashCodes), 2 * sizeof(unsigned) / sizeof(UChar));
    }

    bool operator==(const FontPlatformData& other) const
    { 
        return font == other.font && syntheticBold == other.syntheticBold && syntheticOblique == other.syntheticOblique;
    }
};

}

#else

#include <wtf/Noncopyable.h>

#if WIN32
typedef struct HFONT__ *HFONT;
typedef struct _cairo_scaled_font cairo_scaled_font_t;
typedef struct _cairo_font_face cairo_font_face_t;
#endif

namespace WebCore {

class FontDescription;

class FontPlatformData : Noncopyable
{
public:
#if WIN32
    FontPlatformData(HFONT font, const FontDescription& fontDescription);
#endif
    ~FontPlatformData();

#if WIN32
    HFONT hfont() const { return m_font; }
    cairo_scaled_font_t* scaledFont() const { return m_scaledFont; }
#endif

private:
#if WIN32
    HFONT m_font;
    cairo_font_face_t* m_fontFace;
    cairo_scaled_font_t* m_scaledFont;
#endif
};

}

#endif

#endif
