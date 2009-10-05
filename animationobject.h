#ifndef ANIMATIONOBJECT_H
#define ANIMATIONOBJECT_H

#include <QtGui>
#include <QVector>
#include "voodoographics.h"

template<typename T> class QVector;
class VoodooGraphics;
class AnimationObject;

class AnimationObject
{
public:
    AnimationObject(AnimationObject *parent = NULL);
    AnimationObject(AnimationObject *parent, qint32 width, qint32 height);
    ~AnimationObject();

public:
        // Left top position of object
    QPoint* position() const;
    void setPosition(QPoint position);
    void setPosition(qint32 x, qint32 y);

    AnimationObject *parent();

    QVector<AnimationObject*>* children() const;
    void append(AnimationObject *object);

    int iterator() const;
    void setIterator(qint32 iterator);
    
    qint32 height() const;
    void setHeight(qint32 height);
    
    qint32 width() const;
    void setWidth(qint32 width);

    qint32 scale() const;
    void setScale(qint32 _scale);

    qint32 alpha() const;
    void setAlpha(qint32 _alpha);

    void setSize(qint32 width, qint32 height);

    virtual void render(VoodooGraphics graphics, int elapsed) = 0;

    void drawLines(VoodooGraphics graphics, QVector<QPoint> *lines);
private:
    QPoint *_position;
    qint32 _width;
    qint32 _height;
    qint32 _scale;
    qint32 _alpha;
    AnimationObject *_parent;
    QVector<AnimationObject*>* _children;
    qint32 _iterator;
};

#endif // ANIMATIONOBJECT_H
