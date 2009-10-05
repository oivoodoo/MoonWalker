#include "animationcontainer.h"
#include "voodoographics.h"
 #include <QVariant>

AnimationContainer::AnimationContainer(AnimationObject *parent) : AnimationObject(parent)
{
}

void AnimationContainer::render(VoodooGraphics graphics, int elapsed)
{
    for(int i = 0; i < children()->size(); i++)
    {
        children()->at(i)->render(graphics, elapsed);
    }
}
