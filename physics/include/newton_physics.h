#ifndef NEWTON_H
#define NEWTON_H

#include "vector.h"

typedef float Mass;        // 质量
typedef unsigned int Time; // 时间

class Force : public Vector // 力
{
public:
    Force() {}
    explicit Force(Vector &v) : Vector(v) {}
};
class Displacement : public Vector // 位移
{
public:
    explicit Displacement(Vector &v) : Vector(v) {}
};
class Acceleration : public Vector // 加速度
{
public:
    explicit Acceleration(Vector &v) : Vector(v) {}
};
class Velocity : public Vector // 速度
{
public:
    explicit Velocity() {}
    explicit Velocity(Vector &v) : Vector(v) {}
};
class Impulse : public Vector // 冲量
{
public:
    explicit Impulse(Vector &v) : Vector(v) {}
};
class Momentum : public Vector // 动量
{
public:
    explicit Momentum(Vector &v) : Vector(v) {}
};

namespace NewtonPhysics // 牛顿物理定律
{
    // 计算加速度
    Acceleration caculate_acceleration(const Force &f, const Mass &m);
    Acceleration caculate_acceleration(const Velocity &delta_v, const Time &t);

    // 计算位移
    Displacement caculate_displacement(
        const Velocity &v,
        const Acceleration &a,
        const Time &t);

    // 计算速度
    Velocity caculate_velocity(const Displacement &d, const Time &t);
    Velocity caculate_velocity(const Acceleration &a, const Time &t);

    // 计算动量
    Momentum caculate_momentun(const Mass &m, const Velocity &v);

    // 计算冲量
    Impulse caculate_impulse(const Force &f, const Time &t);
};

#endif
