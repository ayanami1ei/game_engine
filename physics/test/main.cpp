#include <iostream>
#include "object.h"
#include "metronome.h"

int main()
{
    game_clock.time_start();

    std::string name = "obj";
    Vector position(0.0, 0.0, 0.0);
    Mass m = 10;
    Object obj(name, m, position);

    Vector v(0.0, 0.0, 1.0);
    Force f(v);

    for (int i = 0; i < 100; i++)
    {
        obj.add_force(f);
        std::cout << "第"<<i+1<<"次记录，obj位置：" << obj.position.x << ", " << obj.position.y << ", " << obj.position.z << std::endl;
    }
}