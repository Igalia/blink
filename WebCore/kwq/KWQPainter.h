/*
 * Copyright (C) 2003 Apple Computer, Inc.  All rights reserved.
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

#ifndef QPAINTER_H_
#define QPAINTER_H_

#include "KWQFontMetrics.h"
#include "KWQNamespace.h"

#include <ApplicationServices/ApplicationServices.h>

class QBrush;
class QFont;
class QPaintDevice;
class QPixmap;
class QPen;
class QPointArray;
class QWidget;
class QPainterPrivate;
class QString;

class QPainter : public Qt {
public:
    typedef enum { RTL, LTR } TextDirection;
    typedef enum { STRETCH, ROUND, REPEAT } TileRule;

    QPainter();
    QPainter(bool forPrinting);
    ~QPainter();

    QPaintDevice *device() const;
    
    const QFont& font() const;
    void setFont(const QFont&);
    QFontMetrics fontMetrics() const;
    
    const QPen& pen() const;
    void setPen(const QPen&);
    void setPen(PenStyle);
    void setPen(QRgb);
    
    const QBrush& QPainter::brush() const;
    void setBrush(const QBrush&);
    void setBrush(BrushStyle);
    void setBrush(QRgb);

    QRect xForm(const QRect& r) const { return r; }

    void save();
    void restore();
    
    void drawRect(int, int, int, int);
    void drawLine(int, int, int, int);
    void drawEllipse(int, int, int, int);
    void drawArc(int, int, int, int, int, int);
    void drawConvexPolygon(const QPointArray&);

    void fillRect(int, int, int, int, const QBrush&);
    void fillRect(const QRect&, const QBrush&);

    void drawPixmap(const QPoint&, const QPixmap&);
    void drawPixmap(const QPoint&, const QPixmap&, const QRect&);
    void drawPixmap(const QPoint&, const QPixmap&, const QRect&, const QString&);
    void drawPixmap(int x, int y, const QPixmap&,
                    int sx=0, int sy=0, int sw=-1, int sh=-1, int compositeOperator=-1, CGContextRef context = 0);
    void drawPixmap(int x, int y, int w, int h, const QPixmap&,
                    int sx=0, int sy=0, int sw=-1, int sh=-1, int compositeOperator=-1, CGContextRef context = 0);
    void drawFloatPixmap(float x, float y, float w, float h, const QPixmap&,
                         float sx=0, float sy=0, float sw=-1, float sh=-1, int compositeOperator=-1, CGContextRef context = 0);
    void drawTiledPixmap(int, int, int, int, const QPixmap&, int sx=0, int sy=0, CGContextRef context = 0);
    void drawScaledAndTiledPixmap(int, int, int, int, const QPixmap&, int, int, int, int,
                                  TileRule hRule = STRETCH, TileRule vRule = STRETCH,
                                  CGContextRef context = 0);

    void addClip(const QRect&);
    void addRoundedRectClip(const QRect& rect, const QSize& topLeft, const QSize& topRight,
                            const QSize& bottomLeft, const QSize& bottomRight);

    RasterOp rasterOp() const;
    void setRasterOp(RasterOp);

    void drawText(int x, int y, int tabWidth, int xpos, int, int, int alignmentFlags, const QString&);
    void drawHighlightForText(int x, int y, int h, int tabWidth, int xpos,
                  const QChar *, int length, int from, int to, int toAdd,
                  const QColor& backgroundColor, QPainter::TextDirection d, bool visuallyOrdered,
                  int letterSpacing, int wordSpacing, bool smallCaps);
    void drawText(int x, int y, int tabWidth, int xpos, const QChar *, int length, int from, int to, int toAdd,
                  const QColor& backgroundColor, QPainter::TextDirection d, bool visuallyOrdered,
                  int letterSpacing, int wordSpacing, bool smallCaps);
    void drawLineForText(int x, int y, int yOffset, int width);
    void drawLineForMisspelling(int x, int y, int width);
    int misspellingLineThickness() const;

    QColor selectedTextBackgroundColor() const;
    void setUsesInactiveTextBackgroundColor(bool u) { _usesInactiveTextBackgroundColor = u; }
    
    bool paintingDisabled() const;
    void setPaintingDisabled(bool);
    
    bool updatingControlTints() const { return _updatingControlTints; }
    void setUpdatingControlTints(bool b) { setPaintingDisabled(b); _updatingControlTints = b; }

    void beginTransparencyLayer(float opacity);
    void endTransparencyLayer();

    void setShadow(int x, int y, int blur, const QColor& color);
    void clearShadow();

    void initFocusRing(int width, int offset);
    void initFocusRing(int width, int offset, const QColor& color);
    void addFocusRingRect(int x, int y, int width, int height);
    void drawFocusRing();
    
    CGContextRef currentContext();
    
    static int compositeOperatorFromString(const QString& aString);
    static int getCompositeOperation(CGContextRef context);
    static void setCompositeOperation(CGContextRef context, const QString& operation);
    static void setCompositeOperation(CGContextRef context, int operation);

private:
    // no copying or assignment
    QPainter(const QPainter&);
    QPainter& operator=(const QPainter&);

    void setFillColor(const QBrush&);
    void setFillColorFromCurrentBrush();
    void setStrokeColorAndLineWidthFromCurrentPen();
    void setFillColorFromCurrentPen();

    void updateTextRenderer();

    QPainterPrivate *data;
    bool _isForPrinting;
    bool _usesInactiveTextBackgroundColor;
    bool _updatingControlTints;
};

#endif
