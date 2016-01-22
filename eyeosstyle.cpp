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
#include <QCheckBox>
#include <QComboBox>
#include <QPainter>
#include <QPushButton>
#include <QRadioButton>
#include <QStyleFactory>
#include <QStyleOption>
#include <QToolButton>

#include <KActionMenu>

using namespace EyeOs;

class PainterStateSaver
{
public:
    PainterStateSaver(QPainter *painter)
        : m_painter(painter)
    {
        m_pen = m_painter->pen();
        m_brush = m_painter->brush();
        m_antialiasing = m_painter->renderHints() & QPainter::Antialiasing;
    }

    ~PainterStateSaver()
    {
        m_painter->setPen(m_pen);
        m_painter->setBrush(m_brush);
        m_painter->setRenderHint(QPainter::Antialiasing, m_antialiasing);
    }

private:
    QPainter *m_painter;
    QPen m_pen;
    QBrush m_brush;
    bool m_antialiasing;
};

#define SAVE_PAINTER(p) \
    PainterStateSaver _painter_state_saver(p); \
    Q_UNUSED(_painter_state_saver);

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
    palette.setColor(QPalette::Disabled, QPalette::Light, QColor("#E7E9EE"));
//    palette.setColor(QPalette::Disabled, QPalette::Midlight, QColor());
//    palette.setColor(QPalette::Disabled, QPalette::Dark, QColor());
    palette.setColor(QPalette::Disabled, QPalette::Mid, QColor("#C8CDD8"));
    palette.setColor(QPalette::Disabled, QPalette::Text, QColor("#777777"));
    palette.setColor(QPalette::Disabled, QPalette::BrightText, QColor("#777777"));
    palette.setColor(QPalette::Disabled, QPalette::ButtonText, QColor("#777777"));
    palette.setColor(QPalette::Disabled, QPalette::Base, QColor("#FFFFFF"));
    palette.setColor(QPalette::Disabled, QPalette::Window, QColor("#FFFFFF"));
    palette.setColor(QPalette::Disabled, QPalette::Shadow, QColor("#858FA9"));
    palette.setColor(QPalette::Disabled, QPalette::Highlight, QColor("#A5E6F6"));
    palette.setColor(QPalette::Disabled, QPalette::HighlightedText, QColor("#777777"));
//    palette.setColor(QPalette::Disabled, QPalette::Link, QColor());
//    palette.setColor(QPalette::Disabled, QPalette::LinkVisited, QColor());
    palette.setColor(QPalette::Disabled, QPalette::AlternateBase, QColor("#F5F6F7"));
//    palette.setColor(QPalette::Disabled, QPalette::ToolTipBase, QColor());
//    palette.setColor(QPalette::Disabled, QPalette::ToolTipText, QColor());

    palette.setColor(QPalette::Inactive, QPalette::WindowText, QColor("#000000"));
    palette.setColor(QPalette::Inactive, QPalette::Button, QColor("#E7E9EE"));
    palette.setColor(QPalette::Inactive, QPalette::Light, QColor("#E7E9EE"));
//    palette.setColor(QPalette::Inactive, QPalette::Midlight, QColor());
//    palette.setColor(QPalette::Inactive, QPalette::Dark, QColor());
    palette.setColor(QPalette::Inactive, QPalette::Mid, QColor("#C8CDD8"));
    palette.setColor(QPalette::Inactive, QPalette::Text, QColor("#000000"));
    palette.setColor(QPalette::Inactive, QPalette::BrightText, QColor("#000000"));
    palette.setColor(QPalette::Inactive, QPalette::ButtonText, QColor("#000000"));
    palette.setColor(QPalette::Inactive, QPalette::Base, QColor("#FFFFFF"));
    palette.setColor(QPalette::Inactive, QPalette::Window, QColor("#FFFFFF"));
    palette.setColor(QPalette::Inactive, QPalette::Shadow, QColor("#858FA9"));
    palette.setColor(QPalette::Inactive, QPalette::Highlight, QColor("#A5E6F6"));
    palette.setColor(QPalette::Inactive, QPalette::HighlightedText, QColor("#FFFFFF"));
//    palette.setColor(QPalette::Inactive, QPalette::Link, QColor());
//    palette.setColor(QPalette::Inactive, QPalette::LinkVisited, QColor());
    palette.setColor(QPalette::Inactive, QPalette::AlternateBase, QColor("#F5F6F7"));
//    palette.setColor(QPalette::Inactive, QPalette::ToolTipBase, QColor());
//    palette.setColor(QPalette::Inactive, QPalette::ToolTipText, QColor());

    palette.setColor(QPalette::Active, QPalette::WindowText, QColor("#000000"));
    palette.setColor(QPalette::Active, QPalette::Button, QColor("#E7E9EE"));
    palette.setColor(QPalette::Active, QPalette::Light, QColor("#E7E9EE"));
//    palette.setColor(QPalette::Active, QPalette::Midlight, QColor());
//    palette.setColor(QPalette::Active, QPalette::Dark, QColor());
    palette.setColor(QPalette::Active, QPalette::Mid, QColor("#C8CDD8"));
    palette.setColor(QPalette::Active, QPalette::Text, QColor("#000000"));
    palette.setColor(QPalette::Active, QPalette::BrightText, QColor("#000000"));
    palette.setColor(QPalette::Active, QPalette::ButtonText, QColor("#000000"));
    palette.setColor(QPalette::Active, QPalette::Base, QColor("#FFFFFF"));
    palette.setColor(QPalette::Active, QPalette::Window, QColor("#FFFFFF"));
    palette.setColor(QPalette::Active, QPalette::Shadow, QColor("#858FA9"));
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
    case PE_FrameTabWidget:
    case PE_FrameWindow:
        drawFrame(opt, p);
        break;

    case PE_Frame:
        if (qobject_cast<QComboBox*>(w->parentWidget())) {
            drawFrame(opt, p, QPalette::Light);
        } else {
            QProxyStyle::drawPrimitive(pe, opt, p, w);
        }
        break;

    case PE_IndicatorCheckBox:
        drawCheckBox(opt, p, static_cast<const QCheckBox*>(w));
        break;

    case PE_IndicatorRadioButton:
        drawRadioButton(opt, p, static_cast<const QRadioButton*>(w));
        break;

    case PE_PanelLineEdit:
        drawLineEditBackground(opt, p, w);
        break;

    case PE_PanelButtonTool:
    case PE_FrameButtonTool:
        drawToolButtonBackground(opt, p, static_cast<const QToolButton*>(w));
        break;

    case PE_PanelButtonCommand:
    case PE_PanelButtonBevel:
    case PE_FrameDefaultButton:
        drawPushButtonBackground(opt, p);
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
    case CE_TabBarTabShape:
        drawTabBackground(opt, p);
        break;

    case CE_TabBarTabLabel: {
        QStyleOptionTab tab = *qstyleoption_cast<const QStyleOptionTab*>(opt);
        tab.rect.adjust(-tabSpacing(), 0, 0, 0);
        if (!tab.text.isEmpty())
            tab.icon = QIcon();
        QProxyStyle::drawControl(control, &tab, p, w);
        break;
    }

    default:
        QProxyStyle::drawControl(control, opt, p, w);
        break;
    }
}

void EyeOs::Style::drawComplexControl(ComplexControl control, const QStyleOptionComplex *opt, QPainter *p, const QWidget *w) const
{
    switch (control) {
    case CC_ComboBox:
        drawComboBox(qstyleoption_cast<const QStyleOptionComboBox*>(opt), p, static_cast<const QComboBox*>(w));
        break;

    default:
        QProxyStyle::drawComplexControl(control, opt, p, w);
    }
}

int EyeOs::Style::pixelMetric(QStyle::PixelMetric metric, const QStyleOption *option, const QWidget *widget) const
{
    switch (metric) {
    case PM_ExclusiveIndicatorWidth:
    case PM_ExclusiveIndicatorHeight:
        return 18;
    case PM_IndicatorWidth:
    case PM_IndicatorHeight:
        return 19;

    case PM_DefaultFrameWidth:
        return frameWidth();
    case PM_TabBarBaseOverlap:
        return frameWidth();
    case PM_TabBarBaseHeight:
        return 30;
    case PM_TabBarTabHSpace:
        return tabSpacing() + QProxyStyle::pixelMetric(metric, option, widget);
    case PM_TabBarTabVSpace:
        return activeLineWidth() + QProxyStyle::pixelMetric(metric, option, widget);
    default:
        return QProxyStyle::pixelMetric(metric, option, widget);
    }
}

int EyeOs::Style::styleHint(QStyle::StyleHint hint, const QStyleOption *opt, const QWidget *widget, QStyleHintReturn *returnData) const
{
    switch (hint) {
    case SH_ToolButtonStyle:
        return Qt::ToolButtonIconOnly;
    default:
        return QProxyStyle::styleHint(hint, opt, widget, returnData);
    }
}

QSize EyeOs::Style::sizeFromContents(QStyle::ContentsType type, const QStyleOption *opt, const QSize &contentsSize, const QWidget *w) const
{
    QSize result = QProxyStyle::sizeFromContents(type, opt, contentsSize, w);

    switch (type) {
    case CT_PushButton:
    case CT_CheckBox:
    case CT_RadioButton:
    case CT_ComboBox:
    case CT_ProgressBar:
    case CT_MenuItem:
    case CT_MenuBarItem:
    case CT_MenuBar:
    case CT_Slider:
    case CT_LineEdit:
    case CT_SpinBox:
    case CT_DialogButtons:
    case CT_HeaderSection:
        result.setHeight(qMax(30, result.height()));
        break;

    default:
        break;
    }

    return result;
}

int Style::tabSpacing() const
{
    return 5;
}

int Style::frameWidth() const
{
    return 1;
}

int Style::activeLineWidth() const
{
    return 4;
}

void Style::drawFrame(const QStyleOption *opt, QPainter *p, QPalette::ColorRole colorRole) const
{
    SAVE_PAINTER(p);

    const int penWidth = pixelMetric(PM_DefaultFrameWidth, 0, 0);
    const QColor penColor = opt->palette.color(colorRole);
    const QColor bgColor = opt->palette.color(QPalette::Window);

    p->setPen(QPen(penColor, penWidth));
    p->setBrush(bgColor);
    p->drawRect(opt->rect.adjusted(penWidth / 2,
                                   penWidth / 2,
                                   -penWidth / 2 - 1,
                                   -penWidth / 2 - 1));
}

void Style::drawTabBackground(const QStyleOption *opt, QPainter *p) const
{
    SAVE_PAINTER(p);

    const bool isSelected = (opt->state & QStyle::State_Selected);
    const bool mouseOver = opt->state & QStyle::State_MouseOver;

    const int spacing = tabSpacing();

    const QColor bgColor = (isSelected || mouseOver) ? opt->palette.color(QPalette::Base)
                                                     : opt->palette.color(QPalette::AlternateBase);
    const int outlineWidth = frameWidth();
    const QColor outlineColor = opt->palette.color(QPalette::Mid);

    p->setPen(QPen(outlineColor, outlineWidth));
    p->setBrush(bgColor);
    p->drawRect(opt->rect.adjusted(outlineWidth / 2,
                                   outlineWidth / 2,
                                   -spacing - outlineWidth / 2 - 1,
                                   -outlineWidth / 2 - 1));

    if (isSelected) {
        p->setPen(QPen(bgColor, outlineWidth));

        const int bottomOffsetX = outlineWidth + outlineWidth / 2;
        const int bottomOffsetY = -outlineWidth / 2;
        p->drawLine(opt->rect.bottomLeft() + QPoint(bottomOffsetX, bottomOffsetY),
                    opt->rect.bottomRight() + QPoint(-spacing - bottomOffsetX, bottomOffsetY));

        const int penWidth = activeLineWidth();
        const QColor penColor = opt->palette.color(QPalette::Active, QPalette::Highlight);
        p->setPen(QPen(penColor, penWidth));

        const int topOffsetX = outlineWidth + penWidth / 2;
        const int topOffsetY = outlineWidth + penWidth / 2;
        p->drawLine(opt->rect.topLeft() + QPoint(topOffsetX, topOffsetY),
                    opt->rect.topRight() + QPoint(-spacing - topOffsetX + 1, topOffsetY));
    }
}

void Style::drawPushButtonBackground(const QStyleOption *opt, QPainter *p) const
{
    const bool enabled = opt->state & QStyle::State_Enabled;
    const bool mouseOver = opt->state & QStyle::State_MouseOver;
    const bool hasFocus = opt->state & QStyle::State_HasFocus;

    const QColor bgColor = !enabled ? opt->palette.color(QPalette::Button)
                         : (mouseOver && !hasFocus) ? opt->palette.color(QPalette::Inactive, QPalette::Highlight)
                         : hasFocus ? opt->palette.color(QPalette::Active, QPalette::Highlight)
                         : opt->palette.color(QPalette::Button);

    p->fillRect(opt->rect, bgColor);
}

void Style::drawToolButtonBackground(const QStyleOption *opt, QPainter *p, const QWidget *w) const
{
    const bool mouseOver = opt->state & QStyle::State_MouseOver;
    const bool checked = opt->state & QStyle::State_On;
    const bool sunken = opt->state & QStyle::State_Sunken;

    const QComboBox *combo = qobject_cast<const QComboBox*>(w);
    const QToolButton *button = qobject_cast<const QToolButton*>(w);
    const bool hasMenu = combo
                      || (button && button->menu())
                      || (button && qobject_cast<KActionMenu*>(button->defaultAction()));

    const QColor bgColor = mouseOver ? opt->palette.color(QPalette::Inactive, QPalette::Highlight)
                         : opt->palette.color(QPalette::Window);

    p->fillRect(opt->rect, bgColor);

    if (checked || (hasMenu && sunken)) {
        SAVE_PAINTER(p);

        const int penWidth = activeLineWidth();
        const QColor penColor = opt->palette.color(QPalette::Active, QPalette::Highlight);

        p->setPen(QPen(penColor, penWidth));
        p->drawLine(opt->rect.topLeft() + QPoint(0, penWidth / 2),
                    opt->rect.topRight() + QPoint(0, penWidth / 2));
    }
}

void Style::drawLineEditBackground(const QStyleOption *opt, QPainter *p, const QWidget *widget) const
{
    // The combo will control its own look, no need for any frame here
    if (qobject_cast<QComboBox*>(widget->parentWidget())) {
        return;
    }

    const QComboBox *combo = qobject_cast<const QComboBox*>(widget);
    const bool hasFrame = widget->property("frame").toBool()
                       || (combo && (opt->state & QStyle::State_On));

    const QColor bgColor = opt->palette.color(QPalette::Base);
    const QColor penColor = hasFrame ? opt->palette.color(QPalette::Light)
                                     : bgColor;
    const int outlineWidth = frameWidth();

    SAVE_PAINTER(p);

    p->setPen(QPen(penColor, outlineWidth));
    p->setBrush(bgColor);
    p->drawRect(opt->rect.adjusted(outlineWidth / 2,
                                   outlineWidth / 2,
                                   -outlineWidth / 2 - 1,
                                   -outlineWidth / 2 - 1));

    if (!hasFrame) {
        p->setPen(QPen(opt->palette.color(QPalette::Mid), outlineWidth));
        p->drawLine(opt->rect.bottomLeft() - QPoint(0, outlineWidth / 2 + 1),
                    opt->rect.bottomRight() - QPoint(0, outlineWidth / 2 + 1));
    }
}

void Style::drawCheckBox(const QStyleOption *opt, QPainter *p, const QCheckBox *checkBox) const
{
    SAVE_PAINTER(p);

    const QColor penColor = opt->palette.color(QPalette::Shadow);
    const int outlineWidth = frameWidth();

    p->setPen(QPen(penColor, outlineWidth));
    p->drawRect(opt->rect.adjusted(outlineWidth / 2,
                                   outlineWidth / 2,
                                   -outlineWidth / 2 - 1,
                                   -outlineWidth / 2 - 1));

    if (checkBox->isChecked()) {
        const QRect markRect = opt->rect.adjusted(4, 4, -4, -4);

        p->setPen(Qt::NoPen);
        p->setBrush(opt->palette.color(QPalette::Highlight));

        if (checkBox->checkState() == Qt::Checked) {
            p->drawRect(markRect);
        } else {
            p->drawPolygon(QVector<QPoint>() << markRect.bottomLeft()
                                             << markRect.topLeft()
                                             << markRect.topRight());
        }
    }
}

void Style::drawRadioButton(const QStyleOption *opt, QPainter *p, const QRadioButton *radioButton) const
{
    SAVE_PAINTER(p);

    const QColor penColor = opt->palette.color(QPalette::Shadow);
    const int outlineWidth = frameWidth();

    p->setRenderHint(QPainter::Antialiasing, true);
    p->setPen(QPen(penColor, outlineWidth));
    p->drawEllipse(opt->rect.adjusted(outlineWidth / 2,
                                      outlineWidth / 2,
                                      -outlineWidth / 2 - 1,
                                      -outlineWidth / 2 - 1));

    if (radioButton->isChecked()) {
        p->setPen(Qt::NoPen);
        p->setBrush(opt->palette.color(QPalette::Highlight));
        p->drawEllipse(opt->rect.adjusted(4, 4, -5, -5));
    }
}

void Style::drawComboBox(const QStyleOptionComboBox *opt, QPainter *p, const QComboBox *combo) const
{
    if (combo->isEditable() || (opt->state & QStyle::State_On)) {
        drawLineEditBackground(opt, p, combo);
    } else {
        drawToolButtonBackground(opt, p, combo);
    }

    if (opt->subControls & SC_ComboBoxArrow) {
        const bool sunken = opt->state & State_On;
        const bool reverse = opt->direction == Qt::RightToLeft;
        const int menuButtonWidth = 16;
        const int xoffset = sunken ? (reverse ? -1 : 1) : 0;
        const int yoffset = sunken ? 1 : 0;
        const QRect rect = opt->rect;

        SAVE_PAINTER(p);

        int left = !reverse ? rect.right() - menuButtonWidth : rect.left();
        int right = !reverse ? rect.right() : rect.left() + menuButtonWidth;
        QRect arrowRect((left + right) / 2 - 3 + xoffset,
                        rect.center().y() - 1 + yoffset, 7, 4);

        QPolygon arrow;
        arrow << arrowRect.center() + QPoint(-4, -2)
              << arrowRect.center() + QPoint(0, 2)
              << arrowRect.center() + QPoint(4, -2);
        p->setRenderHint(QPainter::Antialiasing, true);
        p->setPen(QPen(p->pen().brush(), 1.1));
        p->drawPolyline(arrow);
    }
}
