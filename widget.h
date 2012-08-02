#ifndef WIDGET_H
#define WIDGET_H

#include <QGLWidget>
#include "fishnet.h"

class Widget : public QGLWidget
{
    Q_OBJECT

public:
    Widget(QGLWidget *parent = 0);
    ~Widget();

    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);

private:
    FishNet net;

};

#endif // WIDGET_H
