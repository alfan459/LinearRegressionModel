# LinearRegressionModel

A simple Arduino library for linear regression modeling with coefficient updates based on feedback.

## Features
- Predict `waktu` based on `volume` and `target deltapH`.
- Update model coefficients using gradient descent with feedback.
- Easy to integrate with Arduino projects.

## Installation
1. Download this repository as a ZIP file.
2. Open Arduino IDE.
3. Go to `Sketch > Include Library > Add .ZIP Library`.
4. Select the downloaded ZIP file.

## Usage
Here’s an example of how to use this library:

```cpp
#include <LinearRegressionModel.h>

// Initialize the model with initial coefficients and learning rate
LinearRegressionModel model(0.5, 0.2, 1.0, 0.01);

void setup() {
  Serial.begin(9600);

  float volume = 10.0;
  float targetDeltapH = 7.0;
  float waktu = model.predictWaktu(volume, targetDeltapH);

  Serial.print("Predicted waktu: ");
  Serial.println(waktu);
}

void loop() {}
