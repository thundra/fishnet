#ifndef FISHNET_H
#define FISHNET_H

#include "node.h"
#include "linkingthread.h"

class FishNet
{
public:
    FishNet(int columns = 10, int rows = 10);
    ~FishNet();

    void calculate();

private:
    int columns;
    int rows;
};

#endif // FISHNET_H
