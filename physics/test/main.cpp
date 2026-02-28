#include <iostream>
#include "object.h"
#include "metronome.h"

int main()
{
    game_clock.time_start();

    std::string name = "obj";
    Vector position;
    Mass m = 10;
    Object obj(name, m, position);

    Force f(0, 0, 1.0 / 1000000);
    obj.add_force(f);

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << "加入10个力1秒后obj位置：" << obj.position.x << ", " << obj.position.y << ", " << obj.position.z << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << "等待1秒后obj位置：" << obj.position.x << ", " << obj.position.y << ", " << obj.position.z << std::endl;
}