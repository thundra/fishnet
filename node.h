#ifndef NODE_H
#define NODE_H

#include "vector.h"
#include "QList"
#include "linkingthread.h"

class LinkingThread;

class Node
{
public:
    Node();
    void linkThread(LinkingThread*);
    void draw();

private:
    Vector speed;
    Vector earthForce;
    QList<LinkingThread*> threads;

    double x;
    double y;

    const double weigth;

};

#endif // NODE_H
