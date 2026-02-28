#include "vector.h"

Vector::Vector(float length, float width, float height)
{
    this->x = length;
    this->y = width;
    this->z = height;
}

Vector::Vector(Vector& v){
    x = v.x;
    y = v.y;
    z = v.z;
}

Vector Vector::operator+(const Vector &other)
{
    Vector res(this->x + other.x, this->y + other.y, this->z + other.z);
    return res;
}

Vector Vector::operator-(const Vector &other)
{
    Vector res(this->x - other.x, this->y - other.y, this->z - other.z);
    return res;
}

Vector operator*(const Vector &a, const float &b)
{
    Vector res(a.x * b, a.y * b, a.z * b);
    return res;
}
Vector operator*(const float &a, const Vector &b)
{
    Vector res(a * b.x, a * b.y, a * b.z);
    return res;
}
Vector operator*(const Vector &a, const Vector &b)
{
    Vector res(a.x * b.x, a.y * b.y, a.z * b.z);
    return res;
}

Vector operator/(const Vector &a, const float &b)
{
    Vector res(a.x / b, a.y / b, a.z / b);
    return res;
}

void Vector::copy_to(Vector &other){
    other.x = this->x;
    other.y = this->y;
    other.z = this->z;
}