#include "LinearRegressionModel.h"

// Constructor
LinearRegressionModel::LinearRegressionModel(float coefVolume, float coefWaktu, float intercept, float learningRate) {
  _coefVolume = coefVolume;
  _coefWaktu = coefWaktu;
  _intercept = intercept;
  _learningRate = learningRate;
}

// Predict waktu based on volume and target deltapH
float LinearRegressionModel::predictWaktu(float volume, float targetDeltapH) {
  return (targetDeltapH - (_coefVolume * volume + _intercept)) / _coefWaktu;
}

// Predict deltapH based on volume and waktu
float LinearRegressionModel::predictDeltapH(float volume, float waktu) {
  return _coefVolume * volume + _coefWaktu * waktu + _intercept;
}

// Update coefficients using feedback
void LinearRegressionModel::updateCoefficients(float volume, float waktu, float actualDeltapH, float predictedDeltapH) {
  float error = predictedDeltapH - actualDeltapH;

  // Gradient descent update rules
  _coefVolume -= _learningRate * error * volume; // Update coef_volume
  _coefWaktu -= _learningRate * error * waktu;   // Update coef_waktu
  _intercept -= _learningRate * error;           // Update intercept
}

// Print current model coefficients
void LinearRegressionModel::printCoefficients() {
  Serial.println("Current Model Coefficients:");
  Serial.print("  Coef Volume: ");
  Serial.println(_coefVolume);
  Serial.print("  Coef Waktu: ");
  Serial.println(_coefWaktu);
  Serial.print("  Intercept: ");
  Serial.println(_intercept);
}
