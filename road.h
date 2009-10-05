#ifndef ROAD_H
#define ROAD_H

#include "animationobject.h"
#include "voodoographics.h"
#include <QVector>

class AnimationObject;
class VoodooGraphics;
template <class T> class QVector;

class Road : public AnimationObject
{
public:
    Road(AnimationObject *_parent, qint32 _width, qint32 _height);
    ~Road();

    virtual void render(VoodooGraphics graphics, int elapsed);
};

#endif // ROAD_H
