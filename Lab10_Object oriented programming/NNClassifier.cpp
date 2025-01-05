#include "NNClassifier.h"
#include <limits>

/**
 * @brief Trains the NNClassifier with a set of data points.
 *
 * This method stores the provided data points for use in the classification process.
 *
 * @param data A constant reference to a vector of DataPoint objects containing the training data.
 */
void NNClassifier::train(const std::vector<DataPoint>& data) {
    trainingData = data;
}

/**
 * @brief Classifies a new data point using the Nearest Neighbor algorithm.
 *
 * This method finds the data point in the training data that is closest
 * (in Euclidean distance) to the provided point and returns the associated label.
 *
 * @param point A constant reference to a Vector3D object representing the point to be classified.
 *
 * @return The predicted orientation label for the input point based on the nearest neighbor in the training data.
 */
OrientationLabel NNClassifier::classify(const Vector3D& point) {
    double minDistance = std::numeric_limits<double>::max();
    OrientationLabel closestLabel = OrientationLabel::Unknown;

    for (auto& dataPoint : trainingData) {
        double distance = point.distanceTo(dataPoint.vector);
        if (distance < minDistance) {
            minDistance = distance;
            closestLabel = dataPoint.label;
        }
    }

    return closestLabel;
}
