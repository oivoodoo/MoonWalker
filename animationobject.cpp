#include "animationobject.h"

#include <QtGui>
#include <QVector>

AnimationObject::AnimationObject(AnimationObject *_parent)
{
    _children = new QVector<AnimationObject*>();
    this->_parent = _parent;
    this->_position = new QPoint(0, 0);
    this->_iterator = 0;
    this->_alpha = 0;
    this->_scale = 1;
}

AnimationObject::AnimationObject(AnimationObject *_parent, qint32 _width, qint32 _height)
{
    _children = new QVector<AnimationObject*>();
    this->_parent = _parent;
    this->_position = new QPoint(0, 0);
    this->_width = _width;
    this->_height = _height;
    this->_iterator = 0;
    this->_alpha = 0;
    this->_scale = 1;
}

AnimationObject::~AnimationObject()
{
    delete _position;
    delete _children;
}

QPoint* AnimationObject::position() const
{
    return _position;
}

QVector<AnimationObject*>* AnimationObject::children() const
{
    return _children;
}

void AnimationObject::setPosition(QPoint position)
{
    this->_position->setX(position.x());
    this->_position->setY(position.y());
}

void AnimationObject::setPosition(qint32 x, qint32 y)
{
    this->_position->setX(x);
    this->_position->setY(y);
}

void AnimationObject::append(AnimationObject *object)
{
    _children->append(object);
}

qint32 AnimationObject::iterator() const
{
    return _iterator;
}

void AnimationObject::setIterator(qint32 iterator)
{
    this->_iterator = iterator;
}

qint32 AnimationObject::width() const
{
    return _width;
}

void AnimationObject::setWidth(qint32 width)
{
    this->_width = width;
}

qint32 AnimationObject::height() const
{
    return _height;
}

void AnimationObject::setHeight(qint32 height)
{
    this->_height = height;
}

void AnimationObject::setSize(qint32 width, qint32 height)
{
    this->_width = width;
    this->_height = height;
}

AnimationObject *AnimationObject::parent()
{
    return _parent;
}

qint32 AnimationObject::scale() const
{
    return _scale;
}

void AnimationObject::setScale(qint32 _scale)
{
    this->_scale = _scale;
}

qint32 AnimationObject::alpha() const
{
    return this->_alpha;
}

void AnimationObject::setAlpha(qint32 _alpha)
{
    this->_alpha = _alpha;
}

void AnimationObject::drawLines(VoodooGraphics graphics, QVector<QPoint> *lines)
{
    for(int i = 0; i < lines->size() - 1; i++) {
        QPoint point1 = QPoint(lines->at(i) * scale());
        QPoint point2 = QPoint(lines->at(i + 1) * scale());
        point1 = graphics.rotate(point1, alpha());
        point2 = graphics.rotate(point2, alpha());
        graphics.drawLine(point1.x() + position()->x(), point1.y() + position()->y(),
                          point2.x() + position()->x(), point2.y() + position()->y());
    }
}
