#include "object.h"
#include <chrono>
#include <iostream>
#include <mutex>
#include "metronome.h"

void move(Object *obj)
{
    std::chrono::duration<int, std::milli> standard(500);
    while (obj->alive)
    {
        std::chrono::milliseconds del_t;
        while (del_t < standard)
        {
            del_t = del_t + game_clock.get_duration();
        }

        obj->force_mtx.lock();
        Force f;
        while (!obj->forces.empty())
        {
            f = *(f + obj->forces.front()).into<Force>();
            obj->forces.pop();
        }
        obj->force_mtx.unlock();

        auto a = NewtonPhysics::caculate_acceleration(f, obj->m);
        obj->position = NewtonPhysics::caculate_displacement(obj->v, a, standard.count()) + obj->position;
        obj->v = *(obj->v + NewtonPhysics::caculate_velocity(a, standard.count())).into<Velocity>();
    }
}

Object::Object(std::string &name, Mass &m, Vector &position)
{
    this->name = name;
    this->m = m;
    this->position = position;

    alive = true;

    movement = std::thread(move, this);
}

void Object::add_force(const Force &f)
{
    force_mtx.lock();
    forces.emplace(const_cast<Force &>(f));
    force_mtx.unlock();
}

Object::~Object()
{
    alive = false;
    movement.join();
}