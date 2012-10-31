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

private:
    Point convertWidgetCoordinates(double x, double y);

private slots:
    void logoutRefreshRate();

private:
    FishNet net;
    Node* activeNode;
    QTimer timeUpdate;
    QTime timer;
    QTimer rateTimer;
    Point lastPoint;

    double x;
    double y;
    double aspect;
    double scale;
    int rate;

};

#endif // WIDGET_H
