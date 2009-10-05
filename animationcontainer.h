#ifndef ANIMATIONCONTAINER_H
#define ANIMATIONCONTAINER_H

#include "animationobject.h"

class AnimationContainer : public AnimationObject
{
public:
    AnimationContainer(AnimationObject *parent = NULL);

    virtual void render(VoodooGraphics graphics, int elapsed);
};

#endif // ANIMATIONCONTAINER_H
