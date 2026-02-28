#ifndef OBJECT_H
#define OBJECT_H

#include "vector.h"
#include "newton_physics.h"
#include <string>
#include <queue>
#include <thread>

class Object // 物体
{
private:
    Velocity v;
    Mass m;
    std::queue<Force> forces;

    std::thread movement;

    std::string name;
    int id;

    bool alive;

public:
    Vector position;
    Object(std::string &name, Mass &m, Vector &position);

    friend void move(Object *obj);

    void add_force(const Force &f);

    ~Object();
};

#endif