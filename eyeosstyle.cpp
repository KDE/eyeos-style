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

#include "eyeosstyle.h"

using namespace EyeOs;

Style::Style()
    : KStyle()
{
    setObjectName("eyeOS");
}

void EyeOs::Style::drawPrimitive(QStyle::PrimitiveElement pe, const QStyleOption *opt, QPainter *p, const QWidget *w) const
{
    switch (pe) {
    default:
        KStyle::drawPrimitive(pe, opt, p, w);
        break;
    }
}

void EyeOs::Style::drawControl(QStyle::ControlElement control, const QStyleOption *opt, QPainter *p, const QWidget *w) const
{
    switch (control) {
    default:
        KStyle::drawControl(control, opt, p, w);
        break;
    }
}

int EyeOs::Style::pixelMetric(QStyle::PixelMetric metric, const QStyleOption *option, const QWidget *widget) const
{
    switch (metric) {
    default:
        return KStyle::pixelMetric(metric, option, widget);
    }
}

int EyeOs::Style::styleHint(QStyle::StyleHint hint, const QStyleOption *opt, const QWidget *widget, QStyleHintReturn *returnData) const
{
    switch (hint) {
    default:
        return KStyle::styleHint(hint, opt, widget, returnData);
    }
}
