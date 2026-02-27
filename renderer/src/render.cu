#include "vec3.h"
#include <cuda_runtime.h>

struct Sphere {
    Vec3 center;
    float radius;
    Vec3 color;
};

// 判断光线与球是否相交
__device__ bool intersectSphere(const Vec3 &orig, const Vec3 &dir, const Sphere &sphere, float &t) {
    Vec3 oc = orig - sphere.center;
    float b = oc.dot(dir);
    float c = oc.dot(oc) - sphere.radius * sphere.radius;
    float disc = b*b - c;
    if(disc > 0) {
        t = -b - sqrtf(disc);
        if(t > 0) return true;
        t = -b + sqrtf(disc);
        return t > 0;
    }
    return false;
}

// CUDA kernel，每个线程计算一个像素
__global__ void renderKernel(Vec3 *fb, int width, int height, Sphere *spheres, int nspheres) {
    int i = blockIdx.x * blockDim.x + threadIdx.x;
    int j = blockIdx.y * blockDim.y + threadIdx.y;
    if(i >= width || j >= height) return;

    int idx = j * width + i;

    Vec3 orig(0, 1, 5);  // 摄像机位置
    float u = (i - width/2.0f) / width;
    float v = (j - height/2.0f) / height;
    Vec3 dir = Vec3(u, -v, -1).normalize(); // 光线方向

    Vec3 pixelColor(0.2f, 0.7f, 1.0f); // 背景蓝色

    float t_min = 1e20f;
    for(int s=0; s<nspheres; s++) {
        float t = 0;
        if(intersectSphere(orig, dir, spheres[s], t)) {
            if(t < t_min) {
                t_min = t;
                pixelColor = spheres[s].color;
            }
        }
    }
    fb[idx] = pixelColor;
}

// 在 CPU 上调用 CUDA 渲染
void render(Vec3 *fb, int width, int height, Sphere *spheres, int nspheres) {
    Vec3 *d_fb;
    Sphere *d_spheres;
    size_t fb_size = width * height * sizeof(Vec3);
    size_t sph_size = nspheres * sizeof(Sphere);

    cudaMalloc(&d_fb, fb_size);
    cudaMalloc(&d_spheres, sph_size);
    cudaMemcpy(d_spheres, spheres, sph_size, cudaMemcpyHostToDevice);

    dim3 block(16,16);
    dim3 grid((width+15)/16, (height+15)/16);
    renderKernel<<<grid, block>>>(d_fb, width, height, d_spheres, nspheres);
    cudaDeviceSynchronize();

    cudaMemcpy(fb, d_fb, fb_size, cudaMemcpyDeviceToHost);
    cudaFree(d_fb);
    cudaFree(d_spheres);
}