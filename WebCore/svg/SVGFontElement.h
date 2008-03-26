/*
   Copyright (C) 2007 Eric Seidel <eric@webkit.org>
   Copyright (C) 2007 Nikolas Zimmermann <zimmermann@kde.org>

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Library General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Library General Public License
   along with this library; see the file COPYING.LIB.  If not, write to
   the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.
 */

#ifndef SVGFontElement_h
#define SVGFontElement_h

#if ENABLE(SVG_FONTS)
#include "SVGExternalResourcesRequired.h"
#include "SVGGlyphElement.h"
#include "SVGGlyphMap.h"
#include "SVGStyledElement.h"

namespace WebCore {

    class SVGMissingGlyphElement;    
    class SVGFontElement : public SVGStyledElement
                         , public SVGExternalResourcesRequired {
    public:
        SVGFontElement(const QualifiedName&, Document*);
        virtual ~SVGFontElement();

        virtual bool rendererIsNeeded(RenderStyle*) { return false; }    
        virtual const SVGElement* contextElement() const { return this; }

        void addGlyphToCache(SVGGlyphElement*);
        void removeGlyphFromCache(SVGGlyphElement*);

        void getGlyphIdentifiersForString(const String&, Vector<SVGGlyphIdentifier>&) const;

        SVGMissingGlyphElement* firstMissingGlyphElement() const;

    private:
        void ensureGlyphCache() const;

        mutable SVGGlyphMap m_glyphMap;
        mutable bool m_isGlyphCacheValid;
    };

} // namespace WebCore

#endif // ENABLE(SVG_FONTS)
#endif

// vim:ts=4:noet
