#pragma once
#include <cmath>
#include <cuda/std/detail/__config>

struct Vec3
{
    float x, y, z;
    __host__ __device__ Vec3() : x(0), y(0), z(0) {}
    __host__ __device__ Vec3(float xx, float yy, float zz) : x(xx), y(yy), z(zz) {}

    __host__ __device__ Vec3 operator+(const Vec3 &b) const { return Vec3(x + b.x, y + b.y, z + b.z); }
    __host__ __device__ Vec3 operator-(const Vec3 &b) const { return Vec3(x - b.x, y - b.y, z - b.z); }
    __host__ __device__ Vec3 operator*(float b) const { return Vec3(x * b, y * b, z * b); }
    __host__ __device__ Vec3 operator/(float b) const { return Vec3(x / b, y / b, z / b); }

    __host__ __device__ float dot(const Vec3 &b) const { return x * b.x + y * b.y + z * b.z; }
    __host__ __device__ Vec3 normalize() const
    {
        float len = sqrtf(x * x + y * y + z * z);
        return (*this) / len;
    }
};