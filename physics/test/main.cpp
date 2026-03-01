#include <iostream>
#include "object.h"
#include "metronome.h"
#include "math_exception.h"

int main()
{
    game_clock.time_start(std::chrono::milliseconds(1));

    std::string name = "obj";
    Vector position = zero;
    Mass m = 1;
    Object obj(name, m, position);
    obj.v = *Vector(0, 0, 1).into<Velocity>();

    // Force f(0, 0, 1.0);
    // obj.add_force(f);

    // std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    // std::cout << "加入1个力1秒后obj位置：" << obj.position.x << ", " << obj.position.y << ", " << obj.position.z << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << "等待1秒后obj位置：" << obj.position.x << ", " << obj.position.y << ", " << obj.position.z << std::endl;
}