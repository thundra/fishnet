#include "fishnet.h"

FishNet::FishNet() {
    for (int row = 0; row < 10; row++) {
        for (int column = 0; column < 10; column++) {
            matrix[row][column] = new Node(row, column);
            if (column > 0) {
                LinkingThread* threadHoriz = new LinkingThread;
                matrix[row][column]->linkThread(threadHoriz);
                matrix[row][column-1]->linkThread(threadHoriz);
            }
            if (row > 0) {
                LinkingThread* threadVert = new LinkingThread;
                matrix[row-1][column]->linkThread(threadVert);
                matrix[row][column]->linkThread(threadVert);
            }
        }
    }
}

FishNet::~FishNet() {

}


void FishNet::calculate() {

}
