#pragma once

#include <array>

struct CameraIntrinsics {
    double fx;
    double fy;
    double cx;
    double cy;
};

struct CameraExtrinsics {
    std::array<std::array<double, 3>, 3> R;
    std::array<double, 3> t;
};

struct Point3D {
    double x;
    double y;
    double z;
};

struct Pixel {
    double u;
    double v;
};

Pixel project(const Point3D& pw,
              const CameraIntrinsics& K,
              const CameraExtrinsics& extr);

double pixelDistance(const Pixel& a, const Pixel& b);
