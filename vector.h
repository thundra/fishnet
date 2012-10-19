#ifndef VECTOR_H
#define VECTOR_H

class Vector
{
public:
    Vector(double x = 0, double y = 0);

    double getX() const {return x;}
    double getY() const {return y;}
    double getLength() const;
    void set(double x, double y);

    Vector operator+ (const Vector&) const;
    Vector operator- (const Vector&) const;

    Vector operator* (double) const;
    Vector operator/ (double) const;

    Vector& operator+= (const Vector&);
    Vector& operator-= (const Vector&);

    Vector& operator*= (int);
    Vector& operator/= (int);

    bool operator== (Vector&) const;
    bool operator!= (Vector&) const;

private:
    double x;
    double y;
};

#endif // VECTOR_H
