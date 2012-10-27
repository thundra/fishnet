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
    newThread->connectNode(this);
}

void Node::listOfThreads()
{
    qDebug() << "Number of threads" << threads.size();
}

void Node::draw(int timeElapsed)
{
//    if ((row != 0 && column != 0) ||
//        (row != 0 && column != 9)) {
        if (!hooked)
        {
            calculateNextState(timeElapsed);
    //        x += speed.getX() * timeElapsed;
    //        y += speed.getY() * timeElapsed;
    //        if (y <= -LIMIT_FRAME)
    //        {
    //            y = -LIMIT_FRAME;
    //            speed.set(-speed.getX() * 0.95, -speed.getY() * 0.95);
    //        }
    //        if (speed.getY() > -0.07 && speed.getY() < 0.07) speed.set(0, 0);
        }

        glColor3f(1.0, 1.0, 1.0);
        glRectf(x-halfSize, y-halfSize, x+halfSize, y+halfSize);

        calculateNextState(timeElapsed);
//    }
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
    Vector acceleration = calculateAcceleration(timeElapsed);
    Vector movement = speed * timeElapsed +
            acceleration * timeElapsed * timeElapsed / 2.0f;
    speed += acceleration * (double)timeElapsed;

    x += movement.getX();
    y += movement.getY();
}

Vector Node::calculateAcceleration(int timeElapsed)
{
    // linkingThreads compute
    Vector linkForce;

    foreach (LinkingThread* thread, threads) {
        linkForce += thread->getForce(this);
    }

    // gravity compute
    // airresistence compute
    double resistenceModule;
    Vector airResistenceForce;
    if (speed.getLength() != 0)
    {
        resistenceModule = speed.getLength() * speed.getLength() * 0.001;
        airResistenceForce = -speed * resistenceModule / speed.getLength();
    }
    // Sum all forces and devide it by weight
//    Vector acc(-0.000001, -0.000005);
    Vector acc;
    acc += (linkForce * 0.000001 + airResistenceForce);
//    qDebug() << acc.getLength() << " " << airResistenceForce.getLength();
    return acc;
}

void Node::release(Vector newSpeed)
{
    speed = newSpeed;
    hooked = false;
}

void Node::setXY(double x, double y)
{
    hooked = true;
    if (x <= LIMIT_FRAME && x >= -LIMIT_FRAME) this->x = x;
    if (y <= LIMIT_FRAME && y >= -LIMIT_FRAME) this->y = y;
}

Point Node::getCoordinates()
{
    return Point(x, y);
}

Point::Point(double x, double y) : x(x), y(y) {}
