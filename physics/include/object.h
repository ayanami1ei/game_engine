#ifndef OBJECT_H
#define OBJECT_H

#include "vector.h"
#include"newton_physics.h"
#include <string>

class Object // 物体
{
private:
    Vector position;
    Velocity v;
    Mass m;

    std::string name;
    std::string id;
};

#endif