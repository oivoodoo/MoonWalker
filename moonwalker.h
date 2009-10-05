#ifndef MOONWALKER_H
#define MOONWALKER_H

#include <QtGui>
#include "animationobject.h"
#include "voodoographics.h"
#include <QVector>

template<class T> class QVector;
class VoodooGraphics;

class MoonWalker : public AnimationObject
{
public:
    MoonWalker(AnimationObject *_parent, qint32 _width, qint32 _height);
    ~MoonWalker();

    virtual void render(VoodooGraphics graphics, int elapsed);
private:
    QVector<QPoint> *lines1;
    QVector<QPoint> *lines2;
    QVector<QPoint> *lines3;
};

#endif // MOONWALKER_H
