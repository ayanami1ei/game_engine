#include <iostream>
#include <fstream>
#include "vec3.h"

struct Sphere; // 前置声明
void render(Vec3 *fb, int width, int height, Sphere *spheres, int nspheres);

struct Sphere
{
    Vec3 center;
    float radius;
    Vec3 color;
};

int main()
{
    const int width = 800;
    const int height = 600;

    Vec3 *framebuffer = new Vec3[width * height];

    Sphere spheres[2];
    spheres[0] = {{0, 0, 0}, 1, {1, 0, 0}};  // 红色球
    spheres[1] = {{2, 0, -1}, 1, {0, 1, 0}}; // 绿色球

    render(framebuffer, width, height, spheres, 2);

    std::ofstream ofs("output.ppm");
    ofs << "P3\n"
        << width << " " << height << "\n255\n";
    for (int j = height - 1; j >= 0; j--)
    {
        for (int i = 0; i < width; i++)
        {
            Vec3 &c = framebuffer[j * width + i];
            int r = std::min(255, int(255 * c.x));
            int g = std::min(255, int(255 * c.y));
            int b = std::min(255, int(255 * c.z));
            ofs << r << " " << g << " " << b << " ";
        }
        ofs << "\n";
    }
    ofs.close();
    delete[] framebuffer;
    std::cout << "渲染完成，输出 output.ppm\n";
    return 0;
}