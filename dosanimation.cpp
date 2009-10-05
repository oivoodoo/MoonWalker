#include <QtGui>

#include "dosanimation.h"
#include "voodoographics.h"
#include "animationcontainer.h"
#include "moonwalker.h"
#include "animationobject.h"
#include "asteroid.h"
#include "road.h"

DOSAnimation::DOSAnimation()
{
    container = new AnimationContainer();
    MoonWalker *walker = new MoonWalker((AnimationObject*)container, 800, 500);
    container->append(walker);
    for(int i = 0; i < 10; i++)
    {
        Asteroid *asteroid = new Asteroid((AnimationObject*)container, 800, 500);
        container->append(asteroid);
    }
    Road *road = new Road((AnimationObject*)container, 800, 500);
    container->append(road);
}

DOSAnimation::~DOSAnimation()
{
    delete container;
}

void DOSAnimation::render(QPainter *painter, int elapsed)
{
    container->render(VoodooGraphics(painter), elapsed);
}
