#ifndef NODE_H
#define NODE_H

#include "vector.h"
#include "QList"
#include "linkingthread.h"
#include <QtOpenGL>
#include <QDebug>

#define LIMIT_FRAME 190

class LinkingThread;

struct Point {
    Point(double x = 0, double y = 0);

    double x;
    double y;
};

class Node
{
public:
    Node(int, int);
    ~Node();
    void linkThread(LinkingThread*);
    void draw(int timeElapsed);
    void release(Vector newSpeed);
    bool check(double x, double y);
    void setXY(double x, double y);
    Point getCoordinates();

private:
    void calculateNextState(int timeElapsed);
    Vector calculateAcceleration();

    Vector speed;
    Vector earthForce;
    QList<LinkingThread*> threads;

    double x;
    double y;
    int row;
    int column;
    bool hooked;

    const double weigth;
    const double halfSize;

};

#endif // NODE_H
