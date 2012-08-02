#include "fishnet.h"

FishNet::FishNet() {
    for (int row = 0; row < 10; row++)
    {
        for (int column = 0; column < 10; column++)
        {
            matrix(row, column) = new Node;
        }
    }
}

FishNet::~FishNet() {

}


void FishNet::calculate() {

}
