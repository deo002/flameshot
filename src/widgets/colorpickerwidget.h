// SPDX-License-Identifier: GPL-3.0-or-later
// SPDX-FileCopyrightText: 2017-2019 Alejandro Sirgo Rica & Contributors

#pragma once

#include <QDebug>
#include <QWidget>

class ColorPickerWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ColorPickerWidget(QWidget* parent = nullptr);

    static const QVector<QColor>& getDefaultColors();
    void updateWidget();

signals:
    void colorSelected(QColor c);

public slots:
    void updateSelection(int index);

protected:
    void paintEvent(QPaintEvent* event) override;
    void repaint(int i, QPainter& painter);

    int m_colorAreaSize;
    int m_selectedIndex, m_lastIndex;
    QVector<QRect> m_colorAreaList;
    QVector<QColor> m_colorList;

    QColor m_uiColor;

private:
    void initColorPicker();
    static QVector<QColor> defaultColors;
};
