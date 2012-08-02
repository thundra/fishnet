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

private:
    QGenericMatrix<10, 10, Node*> matrix;
};

#endif // FISHNET_H
