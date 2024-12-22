#ifndef LinearRegressionModel_h
#define LinearRegressionModel_h

#include "Arduino.h"

class LinearRegressionModel {
  public:
    // Constructor
    LinearRegressionModel(float coefVolume, float coefWaktu, float intercept, float learningRate);

    // Predict waktu based on volume and target deltapH
    float predictWaktu(float volume, float targetDeltapH);

    // Predict deltapH based on volume and waktu
    float predictDeltapH(float volume, float waktu);

    // Update coefficients using feedback
    void updateCoefficients(float volume, float waktu, float actualDeltapH, float predictedDeltapH);

    // Print current model coefficients
    void printCoefficients();

  private:
    float _coefVolume;   // Coefficient for volume
    float _coefWaktu;    // Coefficient for waktu
    float _intercept;    // Intercept of the model
    float _learningRate; // Learning rate for coefficient updates
};

#endif
