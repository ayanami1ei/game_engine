#ifndef OBJECT_H
#define OBJECT_H

#include "vector.h"
#include "newton_physics.h"
#include"measurement_unit/mass_unit.h"
#include <string>
#include <queue>
#include <thread>
#include <mutex>

class Object // 物体
{
private:
    MeasurementUnit::MassUnit::KiloGram m;
    std::queue<Force> forces;

    std::thread movement;

    std::mutex force_mtx;

    std::string name;
    int id;

    bool alive;

public:
    Velocity v;
    Vector position;
    Object(std::string &name, Mass &m, Vector &position);

    friend void move(Object *obj);

    void add_force(const Force &f);

    ~Object();
};

#endif