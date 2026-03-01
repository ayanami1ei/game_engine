#ifndef DISPLACEMENTUNIT_H
#define DISPLACEMENTUNIT_H

#include "measurement_unit.h"
#include "newton_physics.h"

using namespace MeasurementUnit;

#define displace_class(name)     \
    class DisplacementUnit::name \
    {                            \
    public:                      \
        Displacement d;          \
        template <class T>       \
        T into();                \
                                 \
        op_declare(name)         \
    };

displace_class(KiloMeter)
    displace_class(Meter)
        displace_class(MilliMeter)
            displace_class(MicroMeter)

#endif