#ifndef VECTOR_H
#define VECTOR_H

#include <cstddef>

class Vector
{
private:
    float x, y, z;

public:
    Vector(float x, float y, float z);

    Vector operator+(const Vector &other);
};

#endif