#include "node.h"

Node::Node(int row, int column) : row(row), column(column), weigth(20.0),
    halfSize(3.0)
{
    x = -150 + column * 300 / 9.0f;
    y = 150 - row * 300 / 9.0f;
}

Node::~Node()
{
    if (row != 0 && column == 0)
    {

    }
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
    glColor3f(1.0, 1.0, 1.0);
    glRectf(x-halfSize, y-halfSize, x+halfSize, y+halfSize);
}

bool Node::check(double x, double y)
{
    bool result = false;

    if ((x >= (this->x - halfSize) && x <= (this->x + halfSize)) &&
        (y >= (this->y - halfSize) && y <= (this->y + halfSize)))
    {
        result = true;
    }

    return result;
}

//void Node::release()
//{

//}

void Node::setXY(double x, double y)
{
    if (x <= LIMIT_FRAME && x >= -LIMIT_FRAME) this->x = x;
    if (y <= LIMIT_FRAME && y >= -LIMIT_FRAME) this->y = y;
}
