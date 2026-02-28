#ifndef VECTOR_H
#define VECTOR_H

#include <cstddef>
#include <string>

#include"exception.h"

class Vector
{
private:
    float x, y, z;

public:
    Vector(Vector& v);
    Vector(float x, float y, float z);

    Vector operator+(const Vector &other);
    Vector operator-(const Vector &other);
    friend Vector operator*(const Vector &a, const float &b);
    friend Vector operator*(const float &a, const Vector &b);
    friend Vector operator*(const Vector &a, const Vector &b);
    friend Vector operator/(const Vector &a, const float &b);

    void copy_to(Vector &other);

    template <class T>
    T* into()
    {
        if (T* res = static_cast<T*>(this))
        {
            return res;
        }

        throw MathException("不合法的参数，泛型参数必须是Vector的子类",58);
    }
};

#endif