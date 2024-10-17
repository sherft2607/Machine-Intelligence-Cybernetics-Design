#include <ADXL335.h>

// Accelerometer Pins
const int xPin = A0;
const int yPin = A1;
const int zPin = A2;
const int buzzerPin = 9;

// Accelerometer Calibration
const float zeroG = 512.0;
const float scale = 102.3;

// Tone range
float minTone = 1000.0;
const float minToneForUpdate = 1000.0;  //must be the same value as above duplicated because it needs to be defined as an constant float
float maxTone = 2000.0;
const float maxToneForUpdate = 2000.0;  //must be the same value as above duplicated because it needs to be defined as an constant float
const float upperRangeRatio = 1.3;
const float lowerRangeRatio = 0.7;
const float upperLimit = 3000.0;
const float lowerLimit = 200.0;

// Timing
unsigned long lastToneTime = 0;
const int toneInterval = 500;

// Detecting High Tone
float highToneThreshold = 1500.0;
const float highToneThresholdForUpdate = 1500.0;  //must be the same value as above duplicated because it needs to be defined as an constant float
int highToneCount = 0;
int lowToneCount = 0;
unsigned long lastFiveSeconds = 0;
const int resetInterval = 5000;

// To check for an upper limit
bool resetToneRange = false;

void setup() {
  Serial.begin(9600);
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  pinMode(zPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Read raw data from the accelerometer
  int xRaw = analogRead(xPin);
  int yRaw = analogRead(yPin);
  int zRaw = analogRead(zPin);

  // Calculate g-force
  float xG = (xRaw - zeroG) / scale;
  float yG = (yRaw - zeroG) / scale;
  float zG = (zRaw - zeroG) / scale;
  float gForce = sqrt(xG * xG + yG * yG + zG * zG);

  // Map g-force to buzzer tone
  float toneValue;
  if (gForce < 3.4) {
    toneValue = 0;  // No tone for g-force below 1.5
  } else if (gForce <= 4.3) {
    toneValue = map(gForce, 3.4, 4.3, minTone, maxTone);
  } else {
    toneValue = maxTone;  // Limit the tone value at the max tone for g-force above the max(in the current case 8)
  }

  // Timing to create tone every 500 ms
  if (millis() - lastToneTime >= toneInterval) {
    lastToneTime = millis();
    tone(buzzerPin, toneValue);
    delay(500);  // Duration of the tone
    noTone(buzzerPin);

    // Check if tone is high and increase the high tone count
    if (toneValue > highToneThreshold) {
      //toneValue = toneValue * 5; //create a high pitched tone only once after impacts bigger than the treshold, cancelled out!
      highToneCount++;
    }

    else if (toneValue < highToneThreshold) {
      lowToneCount++;
    }

    // Check if tone exceeds the upper/lower limit
    if (toneValue > upperLimit) {
      resetToneRange = true;
    }

    if (toneValue < lowerLimit) {
      resetToneRange = true;
    }
  }

  // Check every five seconds
  if (millis() - lastFiveSeconds >= resetInterval) {
    lastFiveSeconds = millis();

    // If more than 3 high tones, increase range by X
    if (highToneCount > 3) {
      minTone *= upperRangeRatio;
      maxTone *= upperRangeRatio;
      highToneThreshold *= upperRangeRatio;
      //delay(500); //create intervals during which there is no sound coming from the buzzer,cancelled out!
    }

    if (lowToneCount > 10) {
      minTone *= lowerRangeRatio;
      maxTone *= lowerRangeRatio;
      highToneThreshold *= lowerRangeRatio;
    }

    // Reset the high tone count
    highToneCount = 0;
    lowToneCount = 0;

    // Reset to a lower tone range
    if (resetToneRange) {
      minTone = minToneForUpdate;
      maxTone = maxToneForUpdate;
      highToneThreshold = highToneThresholdForUpdate;
      resetToneRange = false;
    }
  }

  Serial.print("G-Force: ");
  Serial.println(gForce);
  Serial.print("Tone Value: ");
  Serial.println(toneValue);
  Serial.print("High Tone Threshold: ");
  Serial.println(highToneThreshold);
  Serial.print("High Tone Count: ");
  Serial.println(highToneCount);
  Serial.print("Low Tone Count: ");
  Serial.println(lowToneCount);
}