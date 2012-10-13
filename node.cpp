#include "node.h"

Node::Node(int row, int column) : row(row), column(column), weigth(20.0),
    halfSize(5.0)
{
    x = -150 + column * 300 / 9.0f;
    y = 150 - row * 300 / 9.0f;
}

void Node::linkThread(LinkingThread *newThread)
{
    threads.append(newThread);
}

void Node::listOfThreads()
{
    qDebug() << "Number of threads" << threads.size();
}

void Node::draw()
{
    qDebug() << "Node::draw" << x << "," << y;

    glColor3f(0.98, 0.625, 0.12);
    glRectf(x-halfSize, y-halfSize, x+halfSize, y+halfSize);
}

bool Node::check(double x, double y)
{
    qDebug() << __FUNCTION__;
    qDebug() << x << "," << y;
    qDebug() << "this" << this->x << "," << this->y;
    bool result = false;

    if ((x > (this->x - halfSize) && x < (this->x + halfSize)) &&
        (y > (this->y - halfSize) && y < (this->y + halfSize)))
    {
        result = true;
    }

    return result;
}

void Node::release()
{

}

void Node::setXY(double x, double y)
{
    this->x = x;
    this->y = y;

    qDebug() << "Node::setXY" << this->x << "," << this->y;
}
