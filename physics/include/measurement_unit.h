#ifndef UNITS_H
#define UNITS_H

#include "physics_exception.h"

#define ops_declare(unit, op) unit operator op(const unit &other);
#define op_declare(unit) ops_declare(unit, +) \
    ops_declare(unit, -)                      \
        ops_declare(unit, *)                  \
            ops_declare(unit, /)

#define operation(unit, op, var)              \
    unit unit::operator op(const unit &other) \
    {                                         \
        unit res;                             \
        res.var = m op other.var;             \
        return res;                           \
    }

#define operations(unit, var) operation(unit, +, var) \
    operation(unit, -, var)                           \
        operation(unit, *, var)                       \
            operation(unit, /, var)

#define illegal_into(name)                         \
    template <class T>                             \
    T name::into()                                 \
    {                                              \
        throw PhysicsException("undeclared type"); \
    }

namespace MeasurementUnit
{
    namespace MassUnit
    {
        class KiloGram;
        class Gram;
    }
    namespace DisplacementUnit
    {
        class KiloMeter;
        class Meter;
        class MilliMeter;
        class MicroMeter;
    }
    namespace ForceUnit
    {
    }
};

#endif