#include <QtGui>
#include "glscene.h"

GLScene::GLScene(AnimationScene *animation, QWidget *parent)
{
    this->animation = animation;
    elapsed = 0;
    setFixedSize(800, 500);
    setAutoFillBackground(true);
}

void GLScene::animate()
{
    elapsed = (elapsed + qobject_cast<QTimer*>(sender())->interval()) % 1000;
    repaint();
}

void GLScene::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);
    animation->render(&painter, elapsed);
    painter.end();
}
