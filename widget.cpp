#include "widget.h"

Widget::Widget(QGLWidget *parent)
    : QGLWidget(parent), x(-5), y(-5)
{
    setWindowTitle(QString("Fishnet"));
    setGeometry(100, 100, 800, 600);

    coordRatio = geometry().height() / 200;

}

Widget::~Widget()
{

}

void Widget::initializeGL()
{
    glClearColor(0,0,0,1);

    timer.start(10);
    timeUpdate.start();
//    connect(SIGNAL(),)
}

void Widget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    glRotatef(0, 0, 0, 0);
    glTranslated(-0.45, -0.3, 0);

    updateNet();

    glLoadIdentity();
    glFlush();
}

void Widget::updateNet()
{
    const double halfSize = 5.0f;
//    double x = -25.0f;
//    double y = 25.0f;

    glColor3f(0.98, 0.625, 0.12);
    glRectf(x-halfSize, y-halfSize, x+halfSize, y+halfSize);
}

void Widget::resizeGL(int w, int h)
{
    double aspect;

    aspect = w / (double)h;
    coordRatio = geometry().height() / h;

    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(0, 100, 100, 0, -1, -1);
//    gluPerspective(10.0f, aspect, 0.001f, 100.0f);
//    if ( w <= h ) {
//        glOrtho(-1000.0, 1000.0, -1000/aspect, 1000/aspect, 1.0, -1.0);
//    } else {
//        glOrtho(-1000*aspect, 1000*aspect, -1000.0, 1000.0, 1.0, -1.0);
//    }

    glOrtho(-w/2, w/2, -h/2, h/2, 1.0, -1.0);

//    if ( w <= h ) {
//        glOrtho(-w/2, w/2, -h/2, h/2, 1.0, -1.0);
//    } else {
//        glOrtho(, 1000*aspect, -1000.0, 1000.0, 1.0, -1.0);
//    }

    glTranslatef(0, 0, 0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

//void Widget::mousePressEvent(QMouseEvent* event)
//{
//    qDebug() << event->x() << ", " << event->y();
//    x /= 3;
//    y /= 3;
//}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    qDebug() << event->x() << ", " << event->y();
    x = (event->x() - geometry().width()/2) / coordRatio;
    y = (event->y() - geometry().height()/2) / -coordRatio;
    qDebug() << x << ", " << y;
    updateGL();
}

//void Widget::mouseReleaseEvent(QMouseEvent *event)
//{
//    qDebug() << event->x() << ", " << event->y();
//}

