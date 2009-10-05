#ifndef ANIMATIONSCENE_H
#define ANIMATIONSCENE_H

#include <QPainter>

class QPainter;

class AnimationScene
{
public:
    AnimationScene();

    virtual void render(QPainter *painter, int elapsed) = 0;
};

#endif // ANIMATIONSCENE_H
