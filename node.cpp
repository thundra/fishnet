#include "node.h"

Node::Node(int row, int column) : row(row), column(column), weigth(20.0)
{

}

void Node::linkThread(LinkingThread *newThread)
{
    threads.append(newThread);
}

void Node::listOfThreads()
{
    qDebug() << "Number of threads" << threads.size();
}
