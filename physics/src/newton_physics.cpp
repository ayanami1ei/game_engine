#include"newton_physics.h"
#include"math_exception.h"

namespace NewtonPhysics
{
    Acceleration
    caculate_acceleration(const Force &f, const Mass &m)
    {
        return *(f / m).into<Acceleration>();
    }

    Displacement caculate_displacement(
        Velocity &v,
        const Acceleration &a,
        const Time &t)
    {
        auto res = *(v * t + 0.5 * a * t * t).into<Displacement>();
        return res;
    }

    Velocity caculate_velocity(const Displacement &d, const Time &t)
    {
        return *(d / t).into<Velocity>();
    }
    Velocity caculate_velocity(const Acceleration &a, const Time &t)
    {
        return *(a * t).into<Velocity>();
    }

    Momentum caculate_momentun(const Mass &m, const Velocity &v)
    {
        return *(m * v).into<Momentum>();
    }

    Impulse caculate_impulse(const Force &f, const Time &t)
    {
        return *(f * t).into<Impulse>();
    }
};
