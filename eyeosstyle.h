/* This file is part of the eyeOS style

   Copyright (C) 2016 eyeOS S.L.U., a Telefonica company, sales@eyeos.com

   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public License as
   published by the Free Software Foundation; either version 2 of
   the License or (at your option) version 3 or any later version
   accepted by the membership of KDE e.V. (or its successor approved
   by the membership of KDE e.V.), which shall act as a proxy
   defined in Section 14 of version 3 of the license.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301,
   USA.
*/

#ifndef EYEOS_STYLE_H
#define EYEOS_STYLE_H

#include <QProxyStyle>

class QToolButton;

namespace EyeOs {

class Style : public QProxyStyle
{
    Q_OBJECT
public:
    explicit Style();

    using QProxyStyle::polish;
    void polish(QApplication *app);
    void polish(QPalette &palette);

    void drawPrimitive(PrimitiveElement pe, const QStyleOption *opt, QPainter *p, const QWidget *w) const;
    void drawControl(ControlElement control, const QStyleOption *opt, QPainter *p, const QWidget *w) const;
    int pixelMetric(PixelMetric metric, const QStyleOption *option, const QWidget *widget) const;
    int styleHint(StyleHint hint, const QStyleOption *opt, const QWidget *widget, QStyleHintReturn *returnData) const;

private:
    int tabSpacing() const;
    int frameWidth() const;
    int activeLineWidth() const;

    void drawFrame(const QStyleOption *opt, QPainter *p) const;
    void drawTabBackground(const QStyleOption *opt, QPainter *p) const;
    void drawPushButtonBackground(const QStyleOption *opt, QPainter *p) const;
    void drawToolButtonBackground(const QStyleOption *opt, QPainter *p, const QToolButton *button) const;
};

}

#endif
