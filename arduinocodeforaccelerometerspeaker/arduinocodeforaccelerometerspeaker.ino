// Define pins for accelerometer and speaker
const int accelerometerPin = A4;  // SDA pin for accelerometer
const int accelerometerPin2 = A5; // SCL pin for accelerometer
const int speakerPin = 9;         // PWM pin for speaker

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Set speaker pin as output
  pinMode(speakerPin, OUTPUT);
}

void loop() {
  // Read the value from the accelerometer
  // For ADXL345, we'll need to use a library to read data over I2C
  // Let's assume you've installed and included the library already
  int sensorValue = readAccelerometer();

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

// Function to read accelerometer data over I2C
int readAccelerometer() {
  // Include necessary libraries for ADXL345 and I2C communication
  // Assuming you've already included the required libraries at the top of your code
  
  // Initialize communication with ADXL345
  // Assuming you've already initialized the ADXL345 module in your setup() function
  
  // Read accelerometer data
  // Assuming you've implemented code to read accelerometer data from the ADXL345 module
}
