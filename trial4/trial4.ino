// Define pins for accelerometer and speaker
const int accelerometerPin = A0;  // Analog pin for accelerometer
const int speakerPin = 9;         // PWM pin for speaker

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Set speaker pin as output
  pinMode(speakerPin, OUTPUT);
}

void loop() {
  // Read the value from the accelerometer
  int sensorValue = analogRead(accelerometerPin);

  // Map the sensor value to the desired range for speaker loudness
  int loudness = map(sensorValue, 0, 1023, 0, 255);

  // Adjust speaker loudness
  analogWrite(speakerPin, loudness);

  // Print sensor value and loudness to serial monitor
  Serial.print("Sensor Value: ");
  Serial.print(sensorValue);
  Serial.print("   Loudness: ");
  Serial.println(loudness);

  // Add a short delay to avoid overwhelming the serial monitor
  delay(100);
}
