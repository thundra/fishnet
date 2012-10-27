#include "linkingthread.h"
#include "math.h"

#define COEF_HOOK 0.33f

LinkingThread::LinkingThread() {
    nodes.first = NULL;
    nodes.second = NULL;
}

void LinkingThread::connectNode(Node *newNode)
{
    if (nodes.first == NULL) nodes.first = newNode;
    else if (nodes.second == NULL) nodes.second = newNode;
}

void LinkingThread::draw()
{

}

Vector LinkingThread::getForce(Node *currentNode)
{
    double x, y, length;
    Point startPoint = currentNode->getCoordinates();

    if (nodes.first != currentNode) {
        Point endPoint = nodes.first->getCoordinates();

        x = endPoint.x - startPoint.x;
        y = endPoint.y - startPoint.y;
    } else {
        Point endPoint = nodes.second->getCoordinates();

        x = endPoint.x - startPoint.x;
        y = endPoint.y - startPoint.y;
    }

    length = hypot(x, y);

    if (length <= 300/9.0f) {
        return Vector(0, 0);
    } else {
        double force = (length - 300 / 9.0f) * COEF_HOOK;

        return Vector(x, y) * force / length;
    }
}

