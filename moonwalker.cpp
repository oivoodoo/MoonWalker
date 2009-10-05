#include "moonwalker.h"
#include "voodoographics.h"
#include "animationobject.h"

#include <QVector>

MoonWalker::MoonWalker(AnimationObject *_parent, qint32 _width, qint32 _height)
        : AnimationObject(_parent, _width, _height)
{
    setScale(15);
    setPosition(0, 135);

    lines1 = new QVector<QPoint>();
    lines1->append(QPoint(2, 1));
    lines1->append(QPoint(3, 3));
    lines1->append(QPoint(10, 3));
    lines1->append(QPoint(12, 5));
    lines1->append(QPoint(10, 7));
    lines1->append(QPoint(3, 7));
    lines1->append(QPoint(2, 5));
    lines1->append(QPoint(3, 3));

    lines2 = new QVector<QPoint>();
    lines2->append(QPoint(5, 4));
    lines2->append(QPoint(10, 4));
    lines2->append(QPoint(11, 5));
    lines2->append(QPoint(10, 5));
    lines2->append(QPoint(5, 5));
    lines2->append(QPoint(5, 4));

    lines3 = new QVector<QPoint>();
    lines3->append(QPoint(10, 3));
    lines3->append(QPoint(12, 2));
    lines3->append(QPoint(12, 0));
}

MoonWalker::~MoonWalker()
{
    delete lines1;
    delete lines2;
    delete lines3;
}

void MoonWalker::render(VoodooGraphics graphics, int elapsed)
{
    graphics.painter()->save();

    // если нужно создать наклон для машинки

    if(position()->x() >= 0 && position()->x() <= 30)
    {
        setAlpha(1);
    } else if (position()->x() >= 30 && position()->x() <= 50)
    {
        setAlpha(2);
    } else if (position()->x() >= 100 && position()->x() <= 300)
    {
        setAlpha(-1);
    } else if (position()->x() >= 300 && position()->x() <= 510)
    {
        setAlpha(1);
    } else if (position()->x() >= 510 && position()->x() <= 800)
    {
        setAlpha(-4);
    }

    // тело машины
    drawLines(graphics, lines1);
    // кабинка
    drawLines(graphics, lines2);
    // антенна
    drawLines(graphics, lines3);

    QPoint point;
    qint32 radius = 1 * scale();
    for(int i = 0; i < 4; i++)
    {
        point = graphics.rotate(10 * scale() - i * radius * 2, 7 * scale(), alpha());
        graphics.drawCircle(point.x() + position()->x(), point.y() + position()->y(), radius);
        graphics.drawCircle(point.x() + position()->x(), point.y() + position()->y(), elapsed / 160);
    }

    // антенна
    point = graphics.rotate(12 * scale(), 0, alpha());
    graphics.drawCircle(position()->x() + point.x(), position()->y() + point.y(), 1 * scale());
    graphics.drawCircle(position()->x() + point.x(), position()->y() + point.y(), 5);
    graphics.drawCircle(position()->x() + point.x(), position()->y() + point.y(), elapsed / 20);

    if (position()->x() >= width() + 10)
    {
        setPosition(0, position()->y());
        setIterator(0);
    }

    setPosition(iterator() + 1, position()->y());
    setIterator(iterator() + 1);
    graphics.painter()->restore();
}
