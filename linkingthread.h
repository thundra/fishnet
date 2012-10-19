#ifndef LINKINGTHREAD_H
#define LINKINGTHREAD_H

#include "node.h"
#include "vector.h"

class Node;

class LinkingThread
{
public:
    LinkingThread() {}

    void connectNode(Node*);
    void draw();
    Vector getForce();

private:
    QVector<Node*> nodes;
};

#endif // LINKINGTHREAD_H
