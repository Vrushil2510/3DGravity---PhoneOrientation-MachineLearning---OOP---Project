#include "NNClassifier.h"
#include "AnotherClassifier.h"
#include "KNNClassifier.h"
#include "FileHandler.h"
#include <iostream>
#include <memory>

/**
 * @file main.cpp
 *
 * @brief Main function for the classifier program.
 *
 * This function loads training data, initializes different classifier objects
 * (Nearest Neighbor, AnotherClassifier, and K-Nearest Neighbors), allows the
 * user to select a classifier, prompts for a test point, performs classification,
 * and optionally demonstrates batch testing from a file (commented out).
 *
 * @author Adam, Dilraj, Mehak, Vrushil
 * @date 2024-04-11
 *
 * @return 0 on successful execution.
 */
int main() {
    // Load training data
    std::string fileName;
    std::cout << "enter file name:\n";
    std::cin >> fileName;
    std::vector<DataPoint> trainingData = FileHandler::readData("fileName");

    // Initialize classifiers
    NNClassifier nn;
    nn.train(trainingData);

    AnotherClassifier anotherClassifier;
    // Assuming AnotherClassifier doesn't need training for its dummy implementation.

    int k = 3; // Default value for KNN, can be asked from user as well.
    

    std::unique_ptr<Classifier> classifier;
    int choice;

    std::cout << "Select a classifier:\n";
    std::cout << "1. Nearest Neighbor\n";
    std::cout << "2. Another Classifier\n";
    std::cout << "3. K-Nearest Neighbors\n";
    std::cin >> choice;

    switch (choice) {
    case 1:
        classifier = std::make_unique<NNClassifier>(nn);
        break;
    case 2:
        //classifier = std::make_unique<AnotherClassifier>(anotherClassifier);
        std::cout << "this class is not implemented ";
        break;
    case 3:
        std::cout << "this class is not implemented ";
        break;
    default:
        std::cout << "Invalid choice.\n";
        return 0;
    }

    std::cout << "Enter a test point (x, y, z): ";
    Vector3D testPoint;
    std::cin >> testPoint.x >> testPoint.y >> testPoint.z;

    OrientationLabel predictedLabel = classifier->classify(testPoint);
    std::cout << "Predicted label: " << static_cast<int>(predictedLabel) << std::endl;

    // Example for batch testing from a file (conceptual, extend as needed)
    // std::vector<DataPoint> testData = FileHandler::readData("testData.txt");
    // for (const auto& dataPoint : testData) {
    //   OrientationLabel predictedLabel = classifier->classify(dataPoint.vector);
    //   std::cout << "Test Point: " << dataPoint.vector.x << ", " << dataPoint.vector.y << ", " << dataPoint.vector.z
    //             << " - Predicted Label: " << static_cast<int>(predictedLabel) << std::endl;
    // }

    return 0;
}
