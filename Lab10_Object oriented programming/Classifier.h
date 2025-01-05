#pragma once
#include "DataPoint.h"
#include <vector>

/// @brief Base class for different classifier implementations.
///
/// This class defines the interface for various classifier algorithms.
/// It provides two pure virtual functions: `train` and `classify`.
/// Derived classes must implement these functions to provide specific classification logic.
class Classifier {
public:
	/// @brief Trains the classifier with a set of data points (pure virtual).
	///
	/// This function is intended to be overridden by derived classes
	/// to implement the training process for their specific algorithms.
	/// The provided data points are typically used to learn or build a model
	/// for classification.
	///
	/// @param data A constant reference to a vector of DataPoint objects containing the training data.
	virtual void train(const std::vector<DataPoint>& data) = 0;

	/// @brief Classifies a new data point (pure virtual).
	///
	/// This function is intended to be overridden by derived classes
	/// to implement the classification logic for their specific algorithms.
	/// It takes a new data point (represented by a Vector3D object) as input
	/// and returns the predicted orientation label.
	///
	/// @param point A constant reference to a Vector3D object representing the point to be classified.
	///
	/// @return The predicted orientation label for the input point.
	virtual OrientationLabel classify(const Vector3D& point) = 0;
};
