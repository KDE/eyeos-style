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
#include <QDateEdit>
#include <QDateTimeEdit>
#include <QDoubleSpinBox>
#include <QMenuBar>
#include <QPainter>
#include <QPushButton>
#include <QRadioButton>
#include <QScrollBar>
#include <QSpinBox>
#include <QStyleFactory>
#include <QStyleOption>
#include <QTimeEdit>
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

void Style::polish(QWidget *widget)
{
    if (qobject_cast<QScrollBar*>(widget)
     || qobject_cast<QSlider*>(widget)) {
        widget->setAttribute(Qt::WA_Hover);
    }
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
    case PE_FrameGroupBox:
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

    case PE_FrameMenu:
        drawFrame(opt, p, QPalette::Light);
        break;

    case PE_IndicatorDockWidgetResizeHandle:
        drawSplitterHandle(opt, p);
        break;

    case PE_IndicatorCheckBox:
        drawCheckBox(opt, p);
        break;

    case PE_IndicatorRadioButton:
        drawRadioButton(opt, p);
        break;

    case PE_IndicatorSpinUp:
    case PE_IndicatorArrowUp:
        drawArrow(opt->rect, p, Qt::UpArrow);
        break;
    case PE_IndicatorSpinDown:
    case PE_IndicatorArrowDown:
        drawArrow(opt->rect, p, Qt::DownArrow);
        break;

    case PE_IndicatorArrowLeft:
        drawArrow(opt->rect, p, Qt::LeftArrow);
        break;
    case PE_IndicatorArrowRight:
        drawArrow(opt->rect, p, Qt::RightArrow);
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
        if (!qobject_cast<const QDoubleSpinBox*>(w)
         && !qobject_cast<const QDateTimeEdit*>(w)
         && !qobject_cast<const QDateEdit*>(w)
         && !qobject_cast<const QSpinBox*>(w)
         && !qobject_cast<const QTimeEdit*>(w)) {
            drawPushButtonBackground(opt, p);
        }
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
    case CE_MenuItem:
        drawMenuItem(qstyleoption_cast<const QStyleOptionMenuItem*>(opt), p, w);
        break;

    case CE_MenuBarItem:
        if (opt->state & QStyle::State_Sunken) {
            drawLineEditBackground(opt, p, w);
            p->setPen(opt->palette.color(QPalette::Window));
            p->drawLine(opt->rect.bottomLeft() + QPoint(1, 0),
                        opt->rect.bottomRight() - QPoint(1, 0));
        }
        QCommonStyle::drawControl(control, opt, p, w);
        break;

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

    case CE_Splitter:
        drawSplitterHandle(opt, p);
        break;

    case CE_HeaderSection:
        drawHeaderSection(opt, p);
        break;

    case CE_ScrollBarAddPage:
    case CE_ScrollBarSubPage:
        p->fillRect(opt->rect, opt->palette.color(QPalette::Window));
        break;

    case CE_ScrollBarSlider:
        if (const QScrollBar *scrollBar = qobject_cast<const QScrollBar*>(w)) {
            drawScrollBarHandle(opt, p, scrollBar->orientation());
        }
        break;

    case CE_ScrollBarAddLine:
        if (const QScrollBar *scrollBar = qobject_cast<const QScrollBar*>(w)) {
            drawAddButton(opt, p, scrollBar->orientation());
        }
        break;
    case CE_ScrollBarSubLine:
        if (const QScrollBar *scrollBar = qobject_cast<const QScrollBar*>(w)) {
            drawSubButton(opt, p, scrollBar->orientation());
        }
        break;

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
    case CC_SpinBox: {
        QStyleOptionSpinBox option = *qstyleoption_cast<const QStyleOptionSpinBox*>(opt);
        option.subControls &= ~SC_SpinBoxFrame;
        drawLineEditBackground(opt, p, w);
        QCommonStyle::drawComplexControl(control, &option, p, w);
        break;
    }
    case CC_Slider:
        drawSlider(qstyleoption_cast<const QStyleOptionSlider*>(opt), p, w);
        break;

    default:
        QProxyStyle::drawComplexControl(control, opt, p, w);
    }
}

int EyeOs::Style::pixelMetric(QStyle::PixelMetric metric, const QStyleOption *option, const QWidget *widget) const
{
    switch (metric) {
    case PM_LayoutTopMargin:
        return 13;
    case PM_LayoutLeftMargin:
    case PM_LayoutRightMargin:
        return 15;
    case PM_LayoutBottomMargin:
        return 20;

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
    case CT_MenuItem:
        if (const QStyleOptionMenuItem *menuItem = qstyleoption_cast<const QStyleOptionMenuItem *>(opt)) {
            result.setWidth((menuItem->menuHasCheckableItems ? 19 : 0)
                          + (menuItem->maxIconWidth ? qMax(menuItem->maxIconWidth, 20) : 0)
                          + menuItem->fontMetrics.width(menuItem->text.left(menuItem->text.indexOf('\t')))
                          + 16
                          + 10);
            if (menuItem->menuItemType == QStyleOptionMenuItem::Separator && menuItem->text.isEmpty()) {
                result.setHeight(2);
            } else {
                result.setHeight(qMax(30, result.height()));
            }
        }
        break;

    case CT_PushButton:
    case CT_CheckBox:
    case CT_RadioButton:
    case CT_ComboBox:
    case CT_ProgressBar:
    case CT_MenuBarItem:
    case CT_MenuBar:
    case CT_Slider:
    case CT_LineEdit:
    case CT_SpinBox:
    case CT_DialogButtons:
    case CT_HeaderSection:
        result.setHeight(qMax(30, result.height()));
        break;

    case CT_ItemViewItem:
        result.setHeight(result.height() + 2 * pixelMetric(PM_FocusFrameVMargin, opt, w));

    default:
        break;
    }

    return result;
}

QRect Style::subControlRect(ComplexControl control, const QStyleOptionComplex *opt, SubControl subControl, const QWidget *w) const
{
    QRect result = QProxyStyle::subControlRect(control, opt, subControl, w);

    switch (control) {
    case CC_Slider:
        switch (subControl) {
        case SC_SliderGroove: {
            const QSlider *slider = qobject_cast<const QSlider*>(w);
            Q_ASSERT(slider);
            if (slider->orientation() == Qt::Horizontal)
                result.setY((opt->rect.height() - result.height()) / 2);
            else
                result.setX((opt->rect.width() - result.width()) / 2);
            break;
        }
        case SC_SliderHandle: {
            const int size = qMax(result.height(), result.width()) - 2;
            result = QRect(result.center() - QPoint(size / 2, size / 2), QSize(size, size));
            break;
        }

        default:
            break;
        }
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
    if (qobject_cast<QComboBox*>(widget->parentWidget())
     || qobject_cast<QDoubleSpinBox*>(widget->parentWidget())
     || qobject_cast<QDateTimeEdit*>(widget->parentWidget())
     || qobject_cast<QDateEdit*>(widget->parentWidget())
     || qobject_cast<QSpinBox*>(widget->parentWidget())
     || qobject_cast<QTimeEdit*>(widget->parentWidget())) {
        return;
    }

    const QComboBox *combo = qobject_cast<const QComboBox*>(widget);
    const QMenuBar *menuBar = qobject_cast<const QMenuBar*>(widget);
    const bool hasFrame = widget->property("frame").toBool()
                       || (menuBar && (opt->state & QStyle::State_Sunken))
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

void Style::drawCheckBox(const QStyleOption *opt, QPainter *p) const
{
    SAVE_PAINTER(p);

    const QColor penColor = opt->palette.color(QPalette::Shadow);
    const int outlineWidth = frameWidth();

    p->setPen(QPen(penColor, outlineWidth));
    p->setBrush(opt->palette.color(QPalette::Window));
    p->drawRect(opt->rect.adjusted(outlineWidth / 2 + 1,
                                   outlineWidth / 2 + 1,
                                   -outlineWidth / 2 - 1,
                                   -outlineWidth / 2 - 1));

    if (opt->state & (State_On | State_NoChange)) {
        const QRect markRect = opt->rect.adjusted(4, 4, -3, -3);

        p->setPen(Qt::NoPen);
        p->setBrush(opt->palette.color(QPalette::Highlight));

        if (opt->state & State_On) {
            p->drawRect(markRect);
        } else {
            p->drawPolygon(QVector<QPoint>() << markRect.bottomLeft()
                                             << markRect.topLeft()
                                             << markRect.topRight());
        }
    }
}

void Style::drawRadioButton(const QStyleOption *opt, QPainter *p) const
{
    SAVE_PAINTER(p);

    const QColor penColor = opt->palette.color(QPalette::Shadow);
    const int outlineWidth = frameWidth();

    p->setRenderHint(QPainter::Antialiasing, true);
    p->setPen(QPen(penColor, outlineWidth));
    p->setBrush(opt->palette.color(QPalette::Window));
    p->drawEllipse(opt->rect.adjusted(outlineWidth / 2,
                                      outlineWidth / 2,
                                      -outlineWidth / 2 - 1,
                                      -outlineWidth / 2 - 1));

    if (opt->state & State_On) {
        p->setPen(Qt::NoPen);
        p->setBrush(opt->palette.color(QPalette::Highlight));
        p->drawEllipse(opt->rect.adjusted(4, 4, -5, -5));
    }
}

void Style::drawArrow(QRect rect, QPainter *p, Qt::ArrowType arrow) const
{
    QPolygon shape;
    switch (arrow) {
    case Qt::NoArrow:
        break;
    case Qt::UpArrow:
        shape << rect.center() + QPoint(-4, 2)
              << rect.center() + QPoint(0, -2)
              << rect.center() + QPoint(4, 2);
        break;
    case Qt::DownArrow:
        shape << rect.center() + QPoint(-4, -2)
              << rect.center() + QPoint(0, 2)
              << rect.center() + QPoint(4, -2);
        break;
    case Qt::LeftArrow:
        shape << rect.center() + QPoint(2, -4)
              << rect.center() + QPoint(-2, 0)
              << rect.center() + QPoint(2, 4);
        break;
    case Qt::RightArrow:
        shape << rect.center() + QPoint(-2, -4)
              << rect.center() + QPoint(2, 0)
              << rect.center() + QPoint(-2, 4);
        break;
    }

    SAVE_PAINTER(p);

    p->setRenderHint(QPainter::Antialiasing, true);
    p->setPen(QPen(p->pen().brush(), 1.1));
    p->drawPolyline(shape);
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


        int left = !reverse ? rect.right() - menuButtonWidth : rect.left();
        int right = !reverse ? rect.right() : rect.left() + menuButtonWidth;
        QRect arrowRect((left + right) / 2 - 3 + xoffset,
                        rect.center().y() - 1 + yoffset, 7, 4);

        drawArrow(arrowRect, p, Qt::DownArrow);
    }
}

void Style::drawScrollBarHandle(const QStyleOption *opt, QPainter *p, Qt::Orientation orientation) const
{
    p->fillRect(opt->rect, opt->palette.color(QPalette::Window));

    SAVE_PAINTER(p);

    const QColor handleColor = !(opt->state & State_Enabled) ? opt->palette.color(QPalette::Mid)
                             : (opt->state & State_MouseOver) ? opt->palette.color(QPalette::Highlight)
                             : opt->palette.color(QPalette::Shadow);
    p->setPen(Qt::NoPen);
    p->setBrush(handleColor);
    p->setRenderHint(QPainter::Antialiasing, true);

    const int radius = (orientation == Qt::Vertical) ? opt->rect.width() / 4
                                                     : opt->rect.height() / 4;
    QRect handleRect = opt->rect;
    if (orientation == Qt::Vertical) {
        handleRect.setWidth(2 * radius);
        handleRect.translate(radius, 0);
    } else {
        handleRect.setHeight(2 * radius);
        handleRect.translate(0, radius);
    }
    p->drawRoundedRect(handleRect, radius, radius);
}

void Style::drawAddButton(const QStyleOption *opt, QPainter *p, Qt::Orientation orientation) const
{
    p->fillRect(opt->rect, opt->palette.color(QPalette::Window));
    drawArrow(opt->rect.adjusted(1, 1, 0, 0), p, (orientation == Qt::Vertical) ? Qt::DownArrow : Qt::RightArrow);
}

void Style::drawSubButton(const QStyleOption *opt, QPainter *p, Qt::Orientation orientation) const
{
    p->fillRect(opt->rect, opt->palette.color(QPalette::Window));

    const int arrowSize = (orientation == Qt::Vertical) ? opt->rect.width() : opt->rect.height();

    const QRect button1(opt->rect.topLeft() + QPoint(1, 1), QSize(arrowSize, arrowSize));
    drawArrow(button1, p, (orientation == Qt::Vertical) ? Qt::UpArrow : Qt::LeftArrow);

    const QPoint button2Origin = (orientation == Qt::Vertical) ? opt->rect.bottomLeft() - QPoint(-1, arrowSize)
                                                               : opt->rect.topRight() - QPoint(arrowSize, -1);
    const QRect button2(button2Origin, QSize(arrowSize, arrowSize));
    drawArrow(button2, p, (orientation == Qt::Vertical) ? Qt::UpArrow : Qt::LeftArrow);
}

void Style::drawMenuItem(const QStyleOptionMenuItem *opt, QPainter *p, const QWidget *w) const
{
    if (opt->menuItemType == QStyleOptionMenuItem::Separator) {
        drawSeparator(opt, p);
        return;
    }

    SAVE_PAINTER(p);

    const bool enabled = opt->state & State_Enabled;
    const bool active = opt->state & State_Selected;

    const QColor bgColor = (active && enabled) ? opt->palette.color(QPalette::Inactive, QPalette::Highlight)
                                               : opt->palette.color(QPalette::Window);
    p->fillRect(opt->rect, bgColor);

    const QRect contentsRect = opt->rect.adjusted(5, 0, -5, 0);

    const bool showCheckbox = opt->menuHasCheckableItems;
    const bool checkable = opt->checkType != QStyleOptionMenuItem::NotCheckable;
    const bool checked = opt->checked;
    const QRect checkLogicalRect(QPoint(contentsRect.left(), contentsRect.top() + (contentsRect.height() - 19) / 2),
                                 showCheckbox ? QSize(19, 19) : QSize(0, 19));
    const QRect checkRect = visualRect(opt->direction, opt->rect, checkLogicalRect);

    if (checkable) {
        QStyleOptionButton button;
        button.rect = checkRect;
        button.state = opt->state;
        if (checked)
            button.state |= State_On;
        button.palette = opt->palette;

        if ((opt->checkType & QStyleOptionMenuItem::Exclusive))
            proxy()->drawPrimitive(PE_IndicatorRadioButton, &button, p, w);
        else
            proxy()->drawPrimitive(PE_IndicatorCheckBox, &button, p, w);
    }

    const int iconWidth = opt->maxIconWidth ? qMax(opt->maxIconWidth, 20) : 0;
    const QRect iconLogicalRect(checkLogicalRect.right() + 5,
                                contentsRect.top() + (contentsRect.height() - iconWidth) / 2,
                                iconWidth,
                                iconWidth);
    const QRect iconRect = visualRect(opt->direction, opt->rect, iconLogicalRect);

    if (!opt->icon.isNull()) {
        const QIcon::Mode mode = (active && enabled) ? QIcon::Active
                               : enabled ? QIcon::Normal
                               : QIcon::Disabled;
        const QPixmap pixmap = opt->icon.pixmap(pixelMetric(PM_SmallIconSize, opt, w), mode);
        const QPoint iconOffset((iconRect.width() - pixmap.width()) / 2,
                                (iconRect.height() - pixmap.height()) / 2);
        p->drawPixmap(iconRect.topLeft() + iconOffset, pixmap);
    }

    const QColor textColor = opt->palette.color(QPalette::WindowText);
    p->setPen(textColor);

    const QRect textLogicalRect(iconLogicalRect.right() + 5,
                                contentsRect.top(),
                                contentsRect.width() - iconLogicalRect.right() - 5,
                                contentsRect.height());
    const QRect textRect = visualRect(opt->direction, opt->rect, textLogicalRect);

    if (!opt->text.isEmpty()) {
        const int textFlags = Qt::AlignVCenter
                            | Qt::AlignLeft
                            | Qt::TextShowMnemonic
                            | Qt::TextDontClip
                            | Qt::TextSingleLine;
        const int tabIndex = opt->text.indexOf(QLatin1Char('\t'));
        p->drawText(textRect, textFlags, opt->text.left(tabIndex));
    }

    if (opt->menuItemType == QStyleOptionMenuItem::SubMenu) {
        const QRect arrowLogicalRect(contentsRect.right() - 16,
                                     contentsRect.top() + (contentsRect.height() - 16) / 2,
                                     16,
                                     16);
        const QRect arrowRect = visualRect(opt->direction, opt->rect, arrowLogicalRect);
        const PrimitiveElement arrow = (opt->direction == Qt::RightToLeft) ? PE_IndicatorArrowLeft : PE_IndicatorArrowRight;

        QStyleOptionMenuItem option = *opt;
        option.rect = arrowRect;
        option.state = opt->state & State_Enabled;
        drawPrimitive(arrow, &option, p, w);
    }
}

void Style::drawSeparator(const QStyleOptionMenuItem *opt, QPainter *p) const
{
    SAVE_PAINTER(p);

    p->fillRect(opt->rect, opt->palette.color(QPalette::Window));

    const QRect contentsRect = opt->rect.adjusted(5, 0, -5, 0);
    const int textLength = !opt->text.isEmpty() ? opt->fontMetrics.width(opt->text) + 5 : 0;

    if (textLength) {
        p->setPen(opt->palette.color(QPalette::WindowText));
        proxy()->drawItemText(p,
                              contentsRect,
                              Qt::AlignLeft | Qt::AlignVCenter,
                              opt->palette,
                              opt->state & State_Enabled,
                              opt->text,
                              QPalette::Text);
    }

    const bool reverse = opt->direction == Qt::RightToLeft;
    const QPoint start(contentsRect.left() + (reverse ? 0 : textLength),
                       opt->rect.center().y());
    const QPoint end(contentsRect.right() - (reverse ? textLength : 0),
                     opt->rect.center().y());

    p->setPen(opt->palette.color(QPalette::Mid));
    p->drawLine(start, end);
}

void Style::drawHeaderSection(const QStyleOption *opt, QPainter *p) const
{
    SAVE_PAINTER(p);

    const QColor bgColor = (opt->state & State_On) ? opt->palette.color(QPalette::Light)
                                                   : opt->palette.color(QPalette::AlternateBase);
    p->fillRect(opt->rect, bgColor);

    const QColor penColor = opt->palette.color(QPalette::Mid);
    const QPoint bottomLeft = opt->rect.bottomLeft();// - QPoint(0, 1);
    const QPoint bottomRight = opt->rect.bottomRight();// - QPoint(0, 1);
    const QPoint topRight = opt->rect.topRight();

    p->setPen(penColor);
    p->drawLine(bottomLeft, bottomRight);
    p->drawLine(bottomRight, topRight);
}

void Style::drawSlider(const QStyleOptionSlider *opt, QPainter *p, const QWidget *w) const
{
    SAVE_PAINTER(p);

    if (opt->subControls & SC_SliderGroove) {
        QRect grooveRect = subControlRect(CC_Slider, opt, SC_SliderGroove, w);
        const QColor grooveColor = opt->palette.color(QPalette::Light);

        p->setPen(Qt::NoPen);
        p->setBrush(grooveColor);
        p->setRenderHint(QPainter::Antialiasing, true);

        const int radius = (opt->orientation == Qt::Vertical) ? grooveRect.width() / 4
                                                              : grooveRect.height() / 4;
        if (opt->orientation == Qt::Vertical) {
            grooveRect.setWidth(2 * radius);
            grooveRect.translate(radius, 0);
        } else {
            grooveRect.setHeight(2 * radius);
            grooveRect.translate(0, radius);
        }
        p->drawRoundedRect(grooveRect, radius, radius);
    }

    if (opt->subControls & SC_SliderHandle) {
        const QRect handleRect = subControlRect(CC_Slider, opt, SC_SliderHandle, w);
        const bool isActive = opt->activeSubControls & SC_SliderHandle;
        const bool isEnabled = opt->state & State_Enabled;

        const QColor bgColor = opt->palette.color(QPalette::Window);
        const QColor outlineColor = !isEnabled ? opt->palette.color(QPalette::Light)
                                  : isActive ? opt->palette.color(QPalette::Highlight)
                                  : opt->palette.color(QPalette::Mid);
        p->setPen(outlineColor);
        p->setBrush(bgColor);
        p->setRenderHint(QPainter::Antialiasing, true);
        p->drawEllipse(handleRect.adjusted(1, 1, -1, -1));
    }
}

void Style::drawSplitterHandle(const QStyleOption *opt, QPainter *p) const
{
    SAVE_PAINTER(p);

    const QColor color = (opt->state & State_Enabled) ? opt->palette.color(QPalette::Mid)
                                                      : opt->palette.color(QPalette::Light);
    const QPoint start = (opt->state & State_Horizontal) ? QPoint(opt->rect.left(), opt->rect.center().y())
                                                         : QPoint(opt->rect.center().x(), opt->rect.top());
    const QPoint end = (opt->state & State_Horizontal) ? QPoint(opt->rect.right(), opt->rect.center().y())
                                                       : QPoint(opt->rect.center().x(), opt->rect.bottom());
    p->setPen(color);
    p->drawLine(start, end);
}
