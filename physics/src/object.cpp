#include "object.h"
#include <chrono>
#include "metronome.h"

void move(Object *obj)
{
    std::chrono::duration<int, std::milli> standard(500);
    while (obj->alive)
    {
        std::chrono::microseconds del_t;
        while (del_t < standard)
        {
            del_t = del_t + game_clock.get_duration();
        }

        Force f;
        while (!obj->forces.empty())
        {
            f = *(f + obj->forces.front()).into<Force>();
            obj->forces.pop();
        }

        auto a = NewtonPhysics::caculate_acceleration(f, obj->m);
        obj->position = NewtonPhysics::caculate_displacement(obj->v, a, del_t.count()) + obj->position;
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
    forces.emplace(const_cast<Force &>(f));
}

Object::~Object()
{
    alive = false;
    movement.join();
}