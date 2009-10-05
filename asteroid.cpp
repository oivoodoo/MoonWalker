#include "asteroid.h"
#include "animationobject.h"

Asteroid::Asteroid(AnimationObject *parent, qint32 _width, qint32 _height) 
        : AnimationObject(parent, _width, _height)
{
    initialize();
    this->_alphaDirection = 1;

    lines = new QVector<QPoint>();
    lines->append(QPoint(1, 0));
    lines->append(QPoint(2, 0));
    lines->append(QPoint(3, 1));
    lines->append(QPoint(3, 2));
    lines->append(QPoint(2, 3));
    lines->append(QPoint(1, 3));
    lines->append(QPoint(0, 2));
    lines->append(QPoint(0, 1));
    lines->append(QPoint(1, 0));
}

Asteroid::~Asteroid()
{
    delete lines;
}

void Asteroid::render(VoodooGraphics graphics, int elapsed)
{
    graphics.painter()->save();
    for(int i = 0; i < lines->size() - 1; i++) {
        QPoint point1 = QPoint(lines->at(i) * scale());
        QPoint point2 = QPoint(lines->at(i + 1) * scale());
        point1 = graphics.rotate(point1, alpha());
        point2 = graphics.rotate(point2, alpha());
        graphics.drawLine(point1.x() + position()->x(), point1.y() + position()->y(),
                          point2.x() + position()->x(), point2.y() + position()->y());
    }
    graphics.painter()->restore();

    if (alpha() >= 15 && alpha() <= -15) {
        this->_alphaDirection *= 1;
    }

    if (position()->y() >= height() + 40)
    {
        initialize();
    }

    setAlpha(alpha() + this->_alphaDirection);
    setPosition(position()->x(), position()->y() + iterator() + 1);
    setIterator(iterator() + 1);
}

void Asteroid::initialize()
{
    setPosition(QPoint(width() * ((double)qrand() / (double)RAND_MAX),
                       height() * ((double)qrand() / (double)RAND_MAX)));
    setScale(10 * (double)qrand() / (double)RAND_MAX);
    setAlpha(180 * (double)qrand() / (double)RAND_MAX);
    setIterator(0);
}
