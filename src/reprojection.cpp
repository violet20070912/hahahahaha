#include "reprojection.hpp"
#include <cmath>
#include <stdexcept>

Pixel project(const Point3D& pw, const CameraIntrinsics& K, const CameraExtrinsics& extr)
{
    double pc_x = extr.R[0][0]*pw.x + extr.R[0][1]*pw.y + extr.R[0][2]*pw.z + extr.t[0];
    double pc_y = extr.R[1][0]*pw.x + extr.R[1][1]*pw.y + extr.R[1][2]*pw.z + extr.t[1];
    double pc_z = extr.R[2][0]*pw.x + extr.R[2][1]*pw.y + extr.R[2][2]*pw.z + extr.t[2];

    if (pc_z <= 0.0) {
        throw std::invalid_argument("Non-positive depth (Zc <= 0)");
    }

    Pixel result;
    result.u = K.fx * (pc_x / pc_z) + K.cx;
    result.v = K.fy * (pc_y / pc_z) + K.cy;

    return result;
}

double pixelDistance(const Pixel& a, const Pixel& b)
{
    double du = a.u - b.u;
    double dv = a.v - b.v;
    return std::sqrt(du * du + dv * dv);
}
