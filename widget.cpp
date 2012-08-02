#include "widget.h"

Widget::Widget(QGLWidget *parent)
    : QGLWidget(parent)
{
    setWindowTitle(QString("Fishnet"));
    setMouseTracking(true);
}

Widget::~Widget()
{

}

void Widget::initializeGL()
{

}

void Widget::paintGL()
{

}

void Widget::resizeGL(int w, int h)
{

}
