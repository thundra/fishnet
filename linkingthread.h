#ifndef LINKINGTHREAD_H
#define LINKINGTHREAD_H

#include <QPair>

#include "node.h"
#include "vector.h"

class Node;

class LinkingThread
{
public:
    LinkingThread();

    void connectNode(Node*);
    void draw();
    Vector getForce(Node* currentNode);

private:
    QPair<Node*, Node*> nodes;
};

#endif // LINKINGTHREAD_H
