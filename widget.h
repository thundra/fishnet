#ifndef WIDGET_H
#define WIDGET_H

#include <QtOpenGL>
#include "fishnet.h"
#include <QDebug>

class Widget : public QGLWidget
{
    Q_OBJECT

public:
    Widget(QGLWidget *parent = 0);
    ~Widget() {}

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);

    virtual void mousePressEvent(QMouseEvent* event);
    virtual void mouseMoveEvent(QMouseEvent* event);
    virtual void mouseReleaseEvent(QMouseEvent* event);

    struct Point {
        double x;
        double y;
    };

private:
    Point convertWidgetCoordinates(double x, double y);

    FishNet net;
    Node* activeNode;
    QTimer timeUpdate;

    double x;
    double y;
    double aspect;
    double scale;

};

#endif // WIDGET_H
