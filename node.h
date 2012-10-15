#ifndef NODE_H
#define NODE_H

#include "vector.h"
#include "QList"
#include "linkingthread.h"
#include <QtOpenGL>
#include <QDebug>

#define LIMIT_FRAME 190

class LinkingThread;

class Node
{
public:
    Node(int, int);
    ~Node();
    void linkThread(LinkingThread*);
    void draw(int timeElapsed);
    void listOfThreads();
    void release(Vector newSpeed);
    bool check(double x, double y);
    void setXY(double x, double y);

private:
    void calculateNextState(int timeElapsed);

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
