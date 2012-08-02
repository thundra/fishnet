#ifndef LINKINGTHREAD_H
#define LINKINGTHREAD_H

#include "node.h"

class Node;

class LinkingThread
{
public:
    LinkingThread();

    void connectNode(Node*);
};

#endif // LINKINGTHREAD_H
