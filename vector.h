#ifndef VECTOR_H
#define VECTOR_H

class Vector
{
public:
    Vector(double x = 0, double y = 0);

    double getX() const {return x;}
    double getY() const {return y;}
    void set(double, double);

    Vector operator+ (const Vector&) const;
    Vector operator- (const Vector&) const;

    Vector operator* (double) const;
    Vector operator/ (double) const;

    Vector& operator+= (const Vector&);
    Vector& operator-= (const Vector&);

    Vector& operator*= (double);
    Vector& operator/= (double);

    bool operator== (Vector&) const;
    bool operator!= (Vector&) const;

private:
    double x;
    double y;
};

#endif // VECTOR_H
