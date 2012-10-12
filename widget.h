#ifndef WIDGET_H
#define WIDGET_H

#include <QtOpenGL>
#include "fishnet.h"

class Widget : public QGLWidget
{
    Q_OBJECT

public:
    Widget(QGLWidget *parent = 0);
    ~Widget();

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);

private:
    FishNet net;
    QTime timeUpdate;
    QTimer timer;

};

#endif // WIDGET_H
