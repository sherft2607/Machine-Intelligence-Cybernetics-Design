int xpin = A3;
int ypin = A2;
int zpin = A1;
int xvalue;
int yvalue;
int zvalue;

void setup() {
  Serial.begin(9600);
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
  
  // Print the combined acceleration value
  Serial.println(acceleration);
  
  delay(100);
}
