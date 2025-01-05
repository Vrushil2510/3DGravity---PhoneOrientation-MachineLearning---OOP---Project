#pragma once
#include "DataPoint.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
/// @brief Reads data points from a text file.
///
/// This function parses a text file containing data points in the format:
///
/// ```
/// x y z label
/// ...
/// ```
///
/// where x, y, and z are floating-point values representing coordinates in 3D space,
/// and label is an integer representing the associated orientation label.
///
/// The function reads each line of the file, parses the values, and creates
/// a DataPoint object. It then adds the created DataPoint to a vector and
/// returns the entire vector containing all data points from the file.
///
/// @param filename The path to the text file containing the data points.
///
/// @return A vector of DataPoint objects representing the data points read from the file.
///
/// @throws std::runtime_error If the file cannot be opened or there is an error during parsing.
class FileHandler {
public:
    /// @brief Writes classification results to a text file.
///
/// This function takes a vector of pairs containing a Vector3D object and
/// an OrientationLabel. It writes each pair to a text file in the format:
///
/// ```
/// x y z label
/// ...
/// ```
///
/// where x, y, and z are the coordinates of the Vector3D, and label is the
/// integer representation of the OrientationLabel.
///
/// @param filename The path to the output text file.
/// @param results A vector of pairs containing the predicted Vector3D and its associated OrientationLabel.
    static std::vector<DataPoint> readData(const std::string& filename);
    static void writeResults(const std::string& filename, const std::vector<std::pair<Vector3D, OrientationLabel>>& results);
};
