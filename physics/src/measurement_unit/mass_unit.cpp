#include "measurement_unit/mass_unit.h"
#include "newton_physics.h"

using namespace MeasurementUnit::MassUnit;

illegal_into(KiloGram)

    template <>
    Gram KiloGram::into()
{
    Gram res;
    res.m = m * 1000;
    return res;
}
operations(KiloGram, m)

    illegal_into(Gram) template <>
    KiloGram Gram::into()
{
    KiloGram res;
    res.m = m / 1000;
    return res;
}
operations(Gram, m)