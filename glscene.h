#ifndef GLSCENE_H
#define GLSCENE_H

#include <QtGui>
#include <QGLWidget>

#include "animationscene.h"

class QGLWidget;
class QPaintEvent;
class QWidget;
class AnimationScene;

class GLScene : public QGLWidget
{
    Q_OBJECT

private:
    int elapsed;
    AnimationScene *animation;

public:
    GLScene(AnimationScene *animation, QWidget *parent);

public slots:
    void animate();

protected:
    void paintEvent(QPaintEvent *);
};

#endif // GLSCENE_H
