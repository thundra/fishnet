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
    void updateNet();

    virtual void mousePressEvent(QMouseEvent* event);
    virtual void mouseMoveEvent(QMouseEvent* event);
    virtual void mouseReleaseEvent(QMouseEvent* event);

private:
    FishNet net;
    Node* activeNode;
    QTime timeUpdate;
    QTimer timer;

    double x;
    double y;
    double coordRatio;

};

#endif // WIDGET_H
