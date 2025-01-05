#pragma once
#include <cmath>

struct Vector3D {
    double x, y, z;

    double distanceTo(const Vector3D& other) const {
        return std::sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y) + (z - other.z) * (z - other.z));
    }
};
