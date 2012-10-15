#include "widget.h"

Widget::Widget(QGLWidget *parent)
    : QGLWidget(parent),
      activeNode(NULL),  x(-5), y(-5)
{
    setWindowTitle(QString("Fishnet"));
    setGeometry(100, 100, 800, 600);
}

void Widget::initializeGL()
{
    glClearColor(0,0,0,1);

    connect(&timeUpdate, SIGNAL(timeout()), SLOT(update()));
//    connect(&timeUpdate, SIGNAL(timeout()), this, SLOT(logout()));
    timeUpdate.setInterval(10);
    timeUpdate.start();
}

void Widget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    glRotatef(0, 0, 0, 0);
    glTranslated(-0.45, -0.3, 0);

    net.paint();

    glLoadIdentity();
    glFlush();
}

void Widget::resizeGL(int w, int h)
{
    aspect = w / (double)h;

    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if ( aspect <= 1 ) {
        glOrtho(-200.0, 200.0, -200/aspect, 200/aspect, 1.0, -1.0);
        scale = (double)400 / w;
    } else {
        glOrtho(-200*aspect, 200*aspect, -200.0, 200.0, 1.0, -1.0);
        scale = (double)400 / h;
    }

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void Widget::mousePressEvent(QMouseEvent* event)
{
    Widget::Point point = convertWidgetCoordinates(event->x(), event->y());
    activeNode = net.getNodeAtPoint(point.x, point.y);
    timeUpdate.stop();
    if (activeNode != NULL) activeNode->setXY(point.x, point.y);
    timeUpdate.start();
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    if (activeNode != NULL)
    {
        Point point = convertWidgetCoordinates(event->x(), event->y());
        activeNode->setXY(point.x, point.y);
        timeUpdate.stop();
        updateGL();
        timeUpdate.start();
    }
}

void Widget::mouseReleaseEvent(QMouseEvent *)
{
    if (activeNode != NULL) activeNode->release();
    activeNode = NULL;
}

Widget::Point Widget::convertWidgetCoordinates(double x, double y)
{
    Point point;

    if (aspect > 1) {
        point.x = x * scale - 200 * aspect;
        point.y = 200 - y * scale;
    } else {
        point.x = x * scale - 200;
        point.y = 200 * aspect - y * scale;
    }

    return point;
}

void Widget::logout()
{
    static int k = 0;
    qDebug() << "Ops!" << k++;
}

