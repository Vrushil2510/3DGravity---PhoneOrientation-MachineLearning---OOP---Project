#include "FileHandler.h"

// Function to read data from a file and return as a vector of DataPoint objects
std::vector<DataPoint> FileHandler::readData(const std::string& filename) {
    std::vector<DataPoint> data; // Vector to store the read data points
    std::ifstream file(filename); // Open the input file stream
    std::string line; // String to store each line read from the file
    // Loop through each line in the file
    while (getline(file, line)) {
        std::istringstream iss(line); // Create a string stream from the line
        double x, y, z; // Variables to store coordinates
        int label; // Variable to store label
        // Attempt to extract coordinates and label from the line
        if (iss >> x >> y >> z >> label) {
            // If successful, create a DataPoint object and add it to the data vector
            data.push_back({ Vector3D{x, y, z}, static_cast<OrientationLabel>(label) });
        }
    }
    return data; // Return the vector of DataPoint objects
}

// Function to write results to a file
void FileHandler::writeResults(const std::string& filename, const std::vector<std::pair<Vector3D, OrientationLabel>>& results) {
    std::ofstream file(filename); // Open the output file stream
    // Loop through each result in the results vector
    for (const auto& result : results) {
        // Write the coordinates and label to the file, separated by commas
        file << result.first.x << "," << result.first.y << "," << result.first.z << "," << static_cast<int>(result.second) << "\n";
    }
}