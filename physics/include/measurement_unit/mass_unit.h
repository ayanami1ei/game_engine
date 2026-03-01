#ifndef MASSUNIT_H
#define MASSUNIT_H

#include "measurement_unit.h"
#include "newton_physics.h"
using namespace MeasurementUnit;

#define mass_class(name)   \
    class MassUnit::name   \
    {                      \
    public:                \
        Mass m;            \
        template <class T> \
        T into();          \
                           \
        op_declare(name)   \
    };

mass_class(KiloGram)
    mass_class(Gram)

#endif