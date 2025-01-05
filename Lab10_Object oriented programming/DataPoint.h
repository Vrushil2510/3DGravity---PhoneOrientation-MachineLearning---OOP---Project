#pragma once
#include "Vector3D.h"

enum class OrientationLabel {
    Unknown, PortraitUp, PortraitDown, LandscapeLeft, LandscapeRight, FaceUp, FaceDown
};

struct DataPoint {
    Vector3D vector;
    OrientationLabel label;
};
