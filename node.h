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

private:
    Vector speed;
    Vector earthForce;
    QList<LinkingThread*> threads;

    const double weigth;

};

#endif // NODE_H
