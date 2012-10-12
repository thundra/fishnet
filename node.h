#ifndef NODE_H
#define NODE_H

#include "vector.h"
#include "QList"
#include "linkingthread.h"
#include <QDebug>

class LinkingThread;

class Node
{
public:
    Node(int, int);
    void linkThread(LinkingThread*);
    void draw();
    void listOfThreads();

private:
    Vector speed;
    Vector earthForce;
    QList<LinkingThread*> threads;

    double x;
    double y;
    int row;
    int column;

    const double weigth;

};

#endif // NODE_H
