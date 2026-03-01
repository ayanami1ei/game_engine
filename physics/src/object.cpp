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
        std::chrono::milliseconds del_t(0);
        while (del_t < standard)
        {
            del_t = del_t + game_clock.get_duration();
        }

        obj->force_mtx.lock();
        // 从 0 开始累加，避免无力时使用未初始化值
        Force f(0.0f, 0.0f, 0.0f);

        // 读取“当前生效力”的总和，但不消费队列，保证每个 tick 都能持续受力
        const size_t count = obj->forces.size();
        for (size_t i = 0; i < count; ++i)
        {
            Force current = obj->forces.front();
            obj->forces.pop();
            f = *(f + current).into<Force>();
            obj->forces.push(current);
        }
        obj->force_mtx.unlock();

        auto a = NewtonPhysics::caculate_acceleration(f, obj->m.m);
        obj->position = NewtonPhysics::caculate_displacement(obj->v, a, standard.count()) + obj->position;
        obj->v = *(obj->v + NewtonPhysics::caculate_velocity(a, standard.count())).into<Velocity>();
    }
}

Object::Object(std::string &name, Mass &m, Vector &position)
{
    this->name = name;
    this->m.m = m;
    this->position = position;

    alive = true;

    movement = std::thread(move, this);
}

void Object::add_force(const Force &f)
{
    force_mtx.lock();
    forces.emplace(f);
    force_mtx.unlock();
}

Object::~Object()
{
    alive = false;
    movement.join();
}