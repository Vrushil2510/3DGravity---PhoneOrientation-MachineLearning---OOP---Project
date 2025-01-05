#pragma once
#include "Classifier.h"

class NNClassifier : public Classifier {
    std::vector<DataPoint> trainingData;
public:
    void train(const std::vector<DataPoint>& data) override;
    OrientationLabel classify(const Vector3D& point) override;
};
