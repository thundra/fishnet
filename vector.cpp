#include "vector.h"
#include "math.h"

Vector::Vector(double x, double y): x(x), y(y)
{
}

void Vector::set(double x, double y)
{
    this->x = x;
    this->y = y;
}

Vector Vector::operator+ (const Vector& other) const
{
    return Vector(x + other.getX(), y + other.getY());
}

Vector Vector::operator- (const Vector& other) const
{
    return Vector(x-other.getX(), y-other.getY());
}

Vector Vector::operator- () const
{
    return Vector(-x, -y);
}

Vector Vector::operator* (double multiplier) const
{
    return Vector(x * multiplier, y * multiplier);
}

Vector Vector::operator/ (double devision) const
{
    return Vector(x / devision, y / devision);
}

Vector& Vector::operator+= (const Vector& other)
{
    x += other.getX();
    y += other.getY();

    return *this;
}

Vector& Vector::operator-= (const Vector& other)
{
    x -= other.getX();
    y -= other.getY();

    return *this;
}

Vector& Vector::operator*= (int multiplier)
{
    x *= multiplier;
    y *= multiplier;

    return *this;
}

Vector& Vector::operator/= (int multiplier)
{
    x /= multiplier;
    y /= multiplier;

    return *this;
}

bool Vector::operator== (Vector& other) const
{
    return x == other.getX() && y == other.getY();
}

bool Vector::operator!= (Vector& other) const
{
    return !(*this == other);
}

double Vector::getLength() const
{
    return hypot(x, y);
}

Vector Vector::normalized() const
{
    return *this / getLength();
}

