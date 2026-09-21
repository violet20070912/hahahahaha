#include "reprojection.hpp"
#include <iostream>
#include <cmath>
#include <array>
#include <exception>

int main() {
    CameraIntrinsics K;
    K.fx = 100.0;
    K.fy = 100.0;
    K.cx = 320.0;
    K.cy = 240.0;

    CameraExtrinsics extr;
    extr.R = {{
        {1.0, 0.0, 0.0},
        {0.0, 1.0, 0.0},
        {0.0, 0.0, 1.0}
    }};
    extr.t = {0.0, 0.0, 0.0};

    std::cout << "--- 测试 1：正常深度 ---\n";
    Point3D pw_ok = {0.0, 0.0, 1.0};
    Pixel observed_ok = {320.0, 240.0};

    try {
        Pixel projected = project(pw_ok, K, extr);
        std::cout << "投影像素: (" << projected.u << ", " << projected.v << ")\n";
        double dist = pixelDistance(projected, observed_ok);
        std::cout << "观测像素: (" << observed_ok.u << ", " << observed_ok.v << ")\n";
        std::cout << "像素距离: " << dist << "\n";
    } catch (const std::exception& e) {
        std::cerr << "发生错误: " << e.what() << "\n";
    }

    std::cout << "\n--- 测试 2：非正深度 ---\n";
    Point3D pw_bad = {0.0, 0.0, -1.0}; 

    try {
        Pixel projected = project(pw_bad, K, extr);
        std::cout << "投影像素: (" << projected.u << ", " << projected.v << ")\n";
    } catch (const std::invalid_argument& e) {
        std::cout << "成功捕获到预期异常: " << e.what() << "\n";
    } catch (const std::exception& e) {
        std::cout << "捕获到其他异常: " << e.what() << "\n";
    }

    return 0;
}
