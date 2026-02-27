#include "vector.h"

Vector::Vector(float length, float width, float height)
{
    this->x = length;
    this->y = width;
    this->z = height;
}

Vector Vector::operator+(const Vector &other)
{
    Vector res(this->x + other.x, this->y + other.y, this->z + other.z);
    return res;
}
