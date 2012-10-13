#include "fishnet.h"

#define NUMBERS_OF_ROW 10
#define NUMBERS_OF_COLUMNS 10

FishNet::FishNet()
{
    for (int row = 0; row < NUMBERS_OF_ROW; row++)
    {
        for (int column = 0; column < NUMBERS_OF_COLUMNS; column++)
        {
            matrix[row][column] = new Node(row, column);
            if (column > 0)
            {
                LinkingThread* threadHoriz = new LinkingThread;

                matrix[row][column]->linkThread(threadHoriz);
                matrix[row][column-1]->linkThread(threadHoriz);
            }
            if (row > 0)
            {
                LinkingThread* threadVert = new LinkingThread;

                matrix[row-1][column]->linkThread(threadVert);
                matrix[row][column]->linkThread(threadVert);
            }
        }
    }
}

FishNet::~FishNet()
{

}

void FishNet::paint()
{
    qDebug() << "FishNet::paint";
    for (int row = 0; row < NUMBERS_OF_ROW; row++)
    {
        for (int column = 0; column < NUMBERS_OF_COLUMNS; column++)
        {
            matrix[row][column]->draw();
        }
    }
}

Node* FishNet::getNodeAtPoint(double x, double y)
{
    qDebug() << __FUNCTION__;
    Node* node = NULL;
    for (int row = 0; row < NUMBERS_OF_ROW; row++)
    {
        qDebug() << __LINE__;
        for (int column = 0; column < NUMBERS_OF_COLUMNS; column++)
        {
            qDebug() << __LINE__;
            if (matrix[row][column]->check(x, y))
            {
                qDebug() << __LINE__;
                node = matrix[row][column];
                break;
            }
        }
        if (node != NULL) break;
    }
    return node;
}
