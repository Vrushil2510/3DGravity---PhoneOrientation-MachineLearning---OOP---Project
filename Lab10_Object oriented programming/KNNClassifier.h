#pragma once
#include "Classifier.h"
#include <vector>

class KNNClassifier : public Classifier {
    std::vector<DataPoint> trainingData;
    int k; // Number of neighbors to consider
public:
    KNNClassifier(int k = 3) : k(k) {}
    void train(const std::vector<DataPoint>& data) override;
    OrientationLabel classify(const Vector3D& point) override;
};
