#include "widget.h"

Widget::Widget(QGLWidget *parent)
    : QGLWidget(parent), x(-5), y(-5),
      activeNode(NULL)
{
    setWindowTitle(QString("Fishnet"));
    setGeometry(100, 100, 800, 600);
}

void Widget::initializeGL()
{
    glClearColor(0,0,0,1);

    timer.start(10);
    timeUpdate.start();
}

void Widget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    glRotatef(0, 0, 0, 0);
    glTranslated(-0.45, -0.3, 0);

    net.paint();
//    updateNet();

    glLoadIdentity();
    glFlush();
}

void Widget::updateNet()
{
    const double halfSize = 15.0f;

    glColor3f(0.98, 0.625, 0.12);
    glRectf(x-halfSize, y-halfSize, x+halfSize, y+halfSize);
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
    qDebug() << "Widget::mousePressEvent";
    Widget::Point point = convertCoordinates(event->x(), event->y());

    activeNode = net.getNodeAtPoint(point.x, point.y);
    if (activeNode != NULL)
    {
//        qDebug() << __FUNCTION__ << " " << __LINE__;
        activeNode->setXY(point.x, point.y);
    }
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    if (activeNode != NULL)
    {
        Point point = convertCoordinates(event->x(), event->y());
//        x = (event->x() - geometry().width()/2) / coordRatio;
//        y = (event->y() - geometry().height()/2) / -coordRatio;

        activeNode->setXY(point.x, point.y);
//        qDebug() << event->x() << ", " << event->y();
//        qDebug() << x << ", " << y;

        updateGL();
    }
}

void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    if (activeNode != NULL) activeNode->release();
    activeNode = NULL;
}

Widget::Point Widget::convertCoordinates(double x, double y)
{
    Point point;

    if (aspect > 1) {
        point.x = x * scale - 200 * aspect;
        point.y = -y * scale + 200;
    } else {
        point.x = x * scale - 200;
        point.y = -y * scale + 200 * aspect;
    }

    return point;
}

