#include "node.h"

Node::Node(int row, int column) : speed(0, 0), earthForce(0, -0.005), row(row),
    column(column), hooked(false), weigth(20.0), halfSize(3.0)
{
    x = -150 + column * 300 / 9.0f;
    y = 150 - row * 300 / 9.0f;
}

Node::~Node()
{
    if (row != 0 && column == 0)
    {
        // TODO: Memory leakage - linking threads
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

void Node::draw(int timeElapsed)
{
    if (!hooked)
    {
        x += speed.getX() * timeElapsed;
        y += speed.getY() * timeElapsed;
        if (y <= -LIMIT_FRAME){
            y = -LIMIT_FRAME;
            speed.set(-speed.getX() * 0.95, -speed.getY() * 0.95);
        }
        if (speed.getY() > -0.07 && speed.getY() < 0.07) speed.set(0, 0);
    }

    glColor3f(1.0, 1.0, 1.0);
    glRectf(x-halfSize, y-halfSize, x+halfSize, y+halfSize);

    calculateNextState(timeElapsed);
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

void Node::calculateNextState(int timeElapsed)
{
    if (!hooked)
    {
        speed += earthForce * timeElapsed * 0.9;
    }
}

void Node::release()
{
    hooked = false;
}

void Node::setXY(double x, double y)
{
    hooked = true;
    if (x <= LIMIT_FRAME && x >= -LIMIT_FRAME) this->x = x;
    if (y <= LIMIT_FRAME && y >= -LIMIT_FRAME) this->y = y;
}
