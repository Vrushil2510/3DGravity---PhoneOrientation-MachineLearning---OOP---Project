#include "AnotherClassifier.h"
#include <iostream>

OrientationLabel AnotherClassifier::classify(const Vector3D& point) {
    //// This heuristic approach classifies based on the dominant gravity axis
    //double absX = std::abs(point.x), absY = std::abs(point.y), absZ = std::abs(point.z);

    //if (absX > absY && absX > absZ) return OrientationLabel::LandscapeLeft; // Example heuristic
    //if (absY > absX && absY > absZ) return OrientationLabel::PortraitUp;    // Example heuristic
    std::cout << "classify";
    return OrientationLabel::FaceUp; // Default case
}
