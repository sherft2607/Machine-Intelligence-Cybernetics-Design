int xpin = A3;
int ypin = A2;
int zpin = A1;
int xvalue;
int yvalue;
int zvalue;
int buzzPin = 8;

void setup() {
  Serial.begin(9600);
  pinMode(buzzPin, OUTPUT);
}

void loop() {
  xvalue = analogRead(xpin);
  int x = map(xvalue, 271, 407, -100, 100);
  
  yvalue = analogRead(ypin);
  int y = map(yvalue, 266, 403, -100, 100);
  
  zvalue = analogRead(zpin);
  int z = map(zvalue, 272, 408, -100, 100);
  
  // Calculate the magnitude of the acceleration vector
  float acceleration = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
  
  // Adjust clicking speed based on acceleration
  int delayTime = map(acceleration, 140, 60, 300, 0); // Adjust the range as needed
  
  // Print the combined acceleration value
  Serial.println(acceleration);
  
  // Buzz based on acceleration
  buzz(delayTime);
  
  delay(50);
}

void buzz(int delayTime) {
  digitalWrite(buzzPin, HIGH);
  delay(delayTime);
  digitalWrite(buzzPin, LOW);
  delay(delayTime);
}
