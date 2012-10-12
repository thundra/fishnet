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
    glClearColor(0,0,0,1);

    timer.start(10);
    timeUpdate.start();
}

void Widget::paintGL()
{
    const double size = 10.0f;
    double x = -25.0f;
    double y = 25.0f;

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    glRotatef(0, 0, 0, 0);
    glTranslated(-0.45, -0.3, 0);

    glColor3f(0.98, 0.625, 0.12);
    glRectf(x, y, x+size, y+size);

    glLoadIdentity();
    glFlush();
}

void Widget::resizeGL(int w, int h)
{
    double aspect;

    aspect = w / (double)h;

    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(0, 100, 100, 0, -1, -1);
//    gluPerspective(10.0f, aspect, 0.001f, 100.0f);
    if ( w <= h ) {
        glOrtho(-100.0, 100.0, -100/aspect, 100/aspect, 1.0, -1.0);
    } else {
        glOrtho(-100*aspect, 100*aspect, -100.0, 100.0, 1.0, -1.0);
    }

    glTranslatef(0, 0, 0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
