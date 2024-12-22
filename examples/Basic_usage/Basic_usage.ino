#include <LinearRegressionModel.h>

// Initialize the model with initial coefficients and learning rate
LinearRegressionModel model(0.5, 0.2, 1.0, 0.01);

void setup() {
  Serial.begin(9600);
  Serial.println("=== Linear Regression Model Example ===");

  // Example input
  float volume = 10.0;
  float targetDeltapH = 7.0;

  // Predict waktu
  float waktu = model.predictWaktu(volume, targetDeltapH);
  if (waktu < 0) waktu = 0.1; // Prevent negative waktu
  Serial.print("Predicted Waktu: ");
  Serial.println(waktu);

  // Predict deltapH
  float predictedDeltapH = model.predictDeltapH(volume, waktu);
  Serial.print("Predicted DeltapH: ");
  Serial.println(predictedDeltapH);

  // Simulated feedback (actual deltapH)
  float actualDeltapH = 6.9; // Replace with actual feedback
  Serial.print("Actual DeltapH: ");
  Serial.println(actualDeltapH);

  // Update model coefficients based on feedback
  model.updateCoefficients(volume, waktu, actualDeltapH, predictedDeltapH);
  model.printCoefficients();
}

void loop() {
  // Nothing to do in the loop
}
