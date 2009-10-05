#ifndef ASTEROID_H
#define ASTEROID_H

#include "animationobject.h"
#include <QVector>

class AnimationObject;
template<class T> class QVector;

class Asteroid : public AnimationObject
{
public:
    Asteroid(AnimationObject *parent, qint32 _width, qint32 _height);
    ~Asteroid();

    virtual void render(VoodooGraphics graphics, int elapsed);
    void initialize();
private:
    QVector<QPoint> *lines;
    qint32 _alphaDirection;
};

#endif // ASTEROID_H
