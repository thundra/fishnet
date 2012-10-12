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

    void calculate();
//    virtual void paint() = 0;

private:
    Node* matrix[10][10];
};

#endif // FISHNET_H
