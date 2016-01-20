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

#include <QApplication>
#include <QPainter>
#include <QPushButton>
#include <QStyleFactory>
#include <QStyleOption>

using namespace EyeOs;

Style::Style()
    : QProxyStyle(QStyleFactory::create("plastique"))
{
    setObjectName("eyeOS");
}

void Style::polish(QApplication *app)
{
    QFont font("Sans");
    font.setPixelSize(16);
    app->setFont(font);
}

void EyeOs::Style::polish(QPalette &palette)
{
    palette.setColor(QPalette::Disabled, QPalette::WindowText, QColor("#777777"));
    palette.setColor(QPalette::Disabled, QPalette::Button, QColor("#E7E9EE"));
//    palette.setColor(QPalette::Disabled, QPalette::Light, QColor());
//    palette.setColor(QPalette::Disabled, QPalette::Midlight, QColor());
//    palette.setColor(QPalette::Disabled, QPalette::Dark, QColor());
//    palette.setColor(QPalette::Disabled, QPalette::Mid, QColor());
    palette.setColor(QPalette::Disabled, QPalette::Text, QColor("#777777"));
    palette.setColor(QPalette::Disabled, QPalette::BrightText, QColor("#777777"));
    palette.setColor(QPalette::Disabled, QPalette::ButtonText, QColor("#777777"));
    palette.setColor(QPalette::Disabled, QPalette::Base, QColor("#FFFFFF"));
    palette.setColor(QPalette::Disabled, QPalette::Window, QColor("#FFFFFF"));
//    palette.setColor(QPalette::Disabled, QPalette::Shadow, QColor());
    palette.setColor(QPalette::Disabled, QPalette::Highlight, QColor("#A5E6F6"));
    palette.setColor(QPalette::Disabled, QPalette::HighlightedText, QColor("#777777"));
//    palette.setColor(QPalette::Disabled, QPalette::Link, QColor());
//    palette.setColor(QPalette::Disabled, QPalette::LinkVisited, QColor());
    palette.setColor(QPalette::Disabled, QPalette::AlternateBase, QColor("#F5F6F7"));
//    palette.setColor(QPalette::Disabled, QPalette::ToolTipBase, QColor());
//    palette.setColor(QPalette::Disabled, QPalette::ToolTipText, QColor());

    palette.setColor(QPalette::Inactive, QPalette::WindowText, QColor("#000000"));
    palette.setColor(QPalette::Inactive, QPalette::Button, QColor("#E7E9EE"));
//    palette.setColor(QPalette::Inactive, QPalette::Light, QColor());
//    palette.setColor(QPalette::Inactive, QPalette::Midlight, QColor());
//    palette.setColor(QPalette::Inactive, QPalette::Dark, QColor());
//    palette.setColor(QPalette::Inactive, QPalette::Mid, QColor());
    palette.setColor(QPalette::Inactive, QPalette::Text, QColor("#000000"));
    palette.setColor(QPalette::Inactive, QPalette::BrightText, QColor("#000000"));
    palette.setColor(QPalette::Inactive, QPalette::ButtonText, QColor("#000000"));
    palette.setColor(QPalette::Inactive, QPalette::Base, QColor("#FFFFFF"));
    palette.setColor(QPalette::Inactive, QPalette::Window, QColor("#FFFFFF"));
//    palette.setColor(QPalette::Inactive, QPalette::Shadow, QColor());
    palette.setColor(QPalette::Inactive, QPalette::Highlight, QColor("#A5E6F6"));
    palette.setColor(QPalette::Inactive, QPalette::HighlightedText, QColor("#FFFFFF"));
//    palette.setColor(QPalette::Inactive, QPalette::Link, QColor());
//    palette.setColor(QPalette::Inactive, QPalette::LinkVisited, QColor());
    palette.setColor(QPalette::Inactive, QPalette::AlternateBase, QColor("#F5F6F7"));
//    palette.setColor(QPalette::Inactive, QPalette::ToolTipBase, QColor());
//    palette.setColor(QPalette::Inactive, QPalette::ToolTipText, QColor());

    palette.setColor(QPalette::Active, QPalette::WindowText, QColor("#000000"));
    palette.setColor(QPalette::Active, QPalette::Button, QColor("#E7E9EE"));
//    palette.setColor(QPalette::Active, QPalette::Light, QColor());
//    palette.setColor(QPalette::Active, QPalette::Midlight, QColor());
//    palette.setColor(QPalette::Active, QPalette::Dark, QColor());
//    palette.setColor(QPalette::Active, QPalette::Mid, QColor());
    palette.setColor(QPalette::Active, QPalette::Text, QColor("#000000"));
    palette.setColor(QPalette::Active, QPalette::BrightText, QColor("#000000"));
    palette.setColor(QPalette::Active, QPalette::ButtonText, QColor("#000000"));
    palette.setColor(QPalette::Active, QPalette::Base, QColor("#FFFFFF"));
    palette.setColor(QPalette::Active, QPalette::Window, QColor("#FFFFFF"));
//    palette.setColor(QPalette::Active, QPalette::Shadow, QColor());
    palette.setColor(QPalette::Active, QPalette::Highlight, QColor("#4BC8E7"));
    palette.setColor(QPalette::Active, QPalette::HighlightedText, QColor("#FFFFFF"));
//    palette.setColor(QPalette::Active, QPalette::Link, QColor());
//    palette.setColor(QPalette::Active, QPalette::LinkVisited, QColor());
    palette.setColor(QPalette::Active, QPalette::AlternateBase, QColor("#F5F6F7"));
//    palette.setColor(QPalette::Active, QPalette::ToolTipBase, QColor());
//    palette.setColor(QPalette::Active, QPalette::ToolTipText, QColor());
}

void EyeOs::Style::drawPrimitive(QStyle::PrimitiveElement pe, const QStyleOption *opt, QPainter *p, const QWidget *w) const
{
    switch (pe) {
    case PE_PanelButtonCommand:
    case PE_PanelButtonBevel:
    case PE_PanelButtonTool:
    case PE_FrameButtonTool:
    case PE_FrameDefaultButton:
        p->fillRect(opt->rect, buttonBackgroundColor(opt));
        break;
    default:
        QProxyStyle::drawPrimitive(pe, opt, p, w);
        break;
    }
}

void EyeOs::Style::drawControl(QStyle::ControlElement control, const QStyleOption *opt, QPainter *p, const QWidget *w) const
{
    switch (control) {
    case CE_PushButtonLabel: {
        QStyleOptionButton button = *qstyleoption_cast<const QStyleOptionButton*>(opt);
        if (!button.text.isEmpty())
            button.icon = QIcon();
        QProxyStyle::drawControl(control, &button, p, w);
        break;
    }
    default:
        QProxyStyle::drawControl(control, opt, p, w);
        break;
    }
}

int EyeOs::Style::pixelMetric(QStyle::PixelMetric metric, const QStyleOption *option, const QWidget *widget) const
{
    switch (metric) {
    default:
        return QProxyStyle::pixelMetric(metric, option, widget);
    }
}

int EyeOs::Style::styleHint(QStyle::StyleHint hint, const QStyleOption *opt, const QWidget *widget, QStyleHintReturn *returnData) const
{
    switch (hint) {
    default:
        return QProxyStyle::styleHint(hint, opt, widget, returnData);
    }
}

QColor Style::buttonBackgroundColor(const QStyleOption *opt) const
{
    const bool enabled = opt->state & QStyle::State_Enabled;
    const bool mouseOver = opt->state & QStyle::State_MouseOver;
    const bool hasFocus = opt->state & QStyle::State_HasFocus;

    return !enabled ? opt->palette.color(QPalette::Button)
         : (mouseOver && !hasFocus) ? opt->palette.color(QPalette::Inactive, QPalette::Highlight)
         : hasFocus ? opt->palette.color(QPalette::Active, QPalette::Highlight)
         : opt->palette.color(QPalette::Button);
}
