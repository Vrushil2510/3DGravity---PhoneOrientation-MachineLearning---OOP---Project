#include "KNNClassifier.h"
#include <algorithm>
#include <map>
#include <iostream>

void KNNClassifier::train(const std::vector<DataPoint>& data) {
    trainingData = data;
    std::cout << "train";
}

OrientationLabel KNNClassifier::classify(const Vector3D& point) {
   
    OrientationLabel predictedLabel = OrientationLabel::Unknown;
    std::cout << "classify";
    return predictedLabel;
}
