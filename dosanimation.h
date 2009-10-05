#ifndef DOSANIMATION_H
#define DOSANIMATION_H

#include "animationscene.h"
#include "voodoographics.h"
#include "animationcontainer.h"
#include "animationobject.h"

class AnimationScene;
class QPainter;
class VoodooGraphics;
class AnimationContainer;
class AnimationObject;
class QObject;

class DOSAnimation : public AnimationScene
{
public:
    DOSAnimation();
    ~DOSAnimation();

    virtual void render(QPainter *painter, int elapsed);
private:
    AnimationContainer *container;
};

#endif // DOSANIMATION_H
