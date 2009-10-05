#include "voodoographics.h"

#include <QtGui>
#include <QPainter>

VoodooGraphics::VoodooGraphics(QPainter *painter)
{
    this->_painter = painter;
}

void VoodooGraphics::drawLine(int x1, int y1, int x2, int y2, QColor color)
{
    int x, y, dx, dy, sx, sy, z, e, i;
    z = e = i = 0;
    bool ch = new bool();
    x = x1;
    y = y1;
    dx = abs(x2-x1);
    dy = abs(y2-y1);
    sx = sign(x2-x1);
    sy = sign(y2-y1);
    if(dx==0 && dy==0)
    {
        painter()->drawPoint(x1, y1);
        return;
    }
    if(dy > dx)
    {
        z = dx;
        dx = dy;
        dy = z;
        ch = true;
    }
    else
    {
        ch = false;
    }
    e = 2 * dy - dx;
    i = 1;
    do
    {
        painter()->drawPoint(x, y);
        while( e>=0 )
        {
            if( ch )
            {
                x = x + sx;
            }
            else
            {
                y = y + sy;
            }
            e = e - 2 * dx;
        }
        if( ch )
        {
            y = y + sy;
        }
        else
        {
            x = x + sx;
        }
        e = e + 2 * dy;
        i = i + 1;
    }
    while(i <= dx);
    painter()->drawPoint(x, y);
}

void VoodooGraphics::drawLine(int x1, int y1, int x2, int y2)
{
    drawLine(x1, y1, x2, y2, color);
}

void VoodooGraphics::drawLine(QPoint p1, QPoint p2)
{
    drawLine(p1.x(), p1.y(), p2.x(), p2.y(), color);
}

void VoodooGraphics::drawCircle(int x1, int y1, int radius) {
    drawCircle(x1, y1, radius, color);
}

void VoodooGraphics::drawCircle(int x1, int y1, int radius, QColor color)
{
    int x, d, dw;
    int y = radius;
    x = d = dw = 0;

    painter()->setPen(QPen(color));
    while(y >= x)
    {
        painter()->drawPoint(x1 + x, y1 + y);
        painter()->drawPoint(x1 + y, y1 + x);
        painter()->drawPoint(x1 - x, y1 + y);
        painter()->drawPoint(x1 - y, y1 + x);
        painter()->drawPoint(x1 + x, y1 - y);
        painter()->drawPoint(x1 + y, y1 - x);
        painter()->drawPoint(x1 - x, y1 - y);
        painter()->drawPoint(x1 - y, y1 - x);
        if (d <= 0)
        {
            d = d + (x << 1) + 1;
            if (d < 0)
            {
                x = x + 1;
            }
            else
            {
                dw = d + 1 - (y << 1);
                x = x + 1;
                if (dw < -d)
                {
                    d = dw;
                    y = y - 1;
                }
            }
        }
        else
        {
            d = d + 1 - (y << 1);
            if (d > 0)
            {
                y = y - 1;
            }
            else
            {
                dw = d + 1 + (x << 1);
                y = y - 1;
                if (dw > -d)
                {
                    d = dw; x = x + 1;
                }
            }
        }
    }
}

void VoodooGraphics::drawCircle(QPoint p, int radius) {
    drawCircle(p, radius, color);
}

void VoodooGraphics::drawCircle(QPoint p, int radius, QColor color)
{
    drawCircle(p.x(), p.y(), radius, color);
}

void VoodooGraphics::swap(int& value1, int& value2)
{
    int temp = value2;
    value2 = value1;
    value1 = temp;
}

int VoodooGraphics::sign(int value)
{
    if(value == 0)
    {
        return 0;
    } else if (value < 0)
    {
        return -1;
    } else
    {
        return 1;
    }
}

void VoodooGraphics::drawPoint(int x1, int y1, QColor color)
{
    painter()->setPen(QPen(color));
    painter()->drawPoint(x1, y1);
}

void VoodooGraphics::drawRect(QRect rect, QColor color)
{
    drawRect(rect.top(), rect.left(), rect.x(), rect.y(), color);
}

void VoodooGraphics::drawRect(int top, int left, int width, int height, QColor color)
{
    painter()->setPen(QPen(color));
    drawLine(top, left, top, left + height, color);
    drawLine(top, left, top + width, left, color);
    drawLine(top, left + height, top + width, left + height, color);
    drawLine(top + width, left, top + width, left + height, color);
}

void VoodooGraphics::drawPoint(QPoint p)
{
    painter()->drawPoint(p);
}

QPainter *VoodooGraphics::painter() const
{
    return _painter;
}

void VoodooGraphics::setColor(QColor& color) {
    this->color = color;
}

QPoint VoodooGraphics::rotate(QPoint point, qreal alpha) {
    alpha = alpha * 3.14 / 180;
    return QPoint(point.x() * cos(alpha) - point.y() * sin(alpha),
                  point.x() * sin(alpha) + point.y() * cos(alpha));
}

QPoint VoodooGraphics::rotate(int x, int y, qreal alpha) {
    return rotate(QPoint(x, y), alpha);
}
