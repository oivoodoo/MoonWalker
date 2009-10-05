#include <QtGui>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "glscene.h"
#include "dosanimation.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    GLScene *scene = new GLScene(new DOSAnimation(), this);
    setCentralWidget(scene);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), scene, SLOT(animate()));
    timer->start(50);

    setFixedSize(800, 500);
    setWindowTitle(tr("Machine Graphics #1"));
}

MainWindow::~MainWindow()
{
}
