#include "road.h"
#include "animationobject.h"
#include "voodoographics.h"

Road::Road(AnimationObject *_parent, qint32 _width, qint32 _height)
        : AnimationObject(_parent, _width, _height)
{
    setAlpha(0);
}

Road::~Road()
{
}

void Road::render(VoodooGraphics graphics, int elapsed)
{
    graphics.painter()->save();

    qint32 direction = 1;
    setAlpha(0);

    graphics.drawLine(0, 250, 80, 250);
    graphics.drawLine(80, 250, 180, 260);
    graphics.drawLine(180, 260, 300, 250);
    graphics.drawLine(300, 250, 600, 260);
    graphics.drawLine(600, 260, 800, 240);

    graphics.painter()->restore();
}
