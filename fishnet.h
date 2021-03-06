#ifndef FISHNET_H
#define FISHNET_H

#include "node.h"
#include "linkingthread.h"
#include "QGenericMatrix"

class FishNet
{
public:
    FishNet();
    ~FishNet();

//    void calculate();
    void paint();
    Node* getNodeAtPoint(double x, double y);


private:
    Node* matrix[10][10];
    QTime timer;
};

#endif // FISHNET_H
