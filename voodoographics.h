#ifndef VOODOOGRAPHICS_H
#define VOODOOGRAPHICS_H

#include <QtGui>

class VoodooGraphics
{
public:
    VoodooGraphics(QPainter *painter);

    void drawLine(QPoint p1, QPoint p2, QColor color);
    void drawLine(int x1, int y1, int x2, int y2, QColor color);
    void drawLine(QPoint p1, QPoint p2);
    void drawLine(int x1, int y1, int x2, int y2);
    void drawCircle(QPoint center, int radius, QColor color);
    void drawCircle(int x1, int y1, int radius, QColor color);
    void drawCircle(QPoint center, int radius);
    void drawCircle(int x1, int y1, int radius);
    void drawPoint(int x1, int y1, QColor color);
    void drawPoint(QPoint p, QColor color);
    void drawPoint(QPoint p);
    void drawRect(int top, int left, int width, int height, QColor color);
    void drawRect(QRect rect, QColor color);
    QPoint rotate(QPoint point, qreal alpha);
    QPoint rotate(int x, int y, qreal alpha);
    void setColor(QColor& color);

    QPainter* painter() const;

private:
    void swap(int& value1, int& value2);
    int sign(int value);
private:
    QPainter *_painter;
    QColor color;
};

#endif // VOODOOGRAPHICS_H
