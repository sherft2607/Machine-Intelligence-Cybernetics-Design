// do a digital read of pin 8
// and report back to the computer 

void setup(){
  pinMode(8, INPUT);
  Serial.begin(9600);
}

void loop(){
  // making a variable, saving a value
  // into it
  int readVal = digitalRead(8);
  Serial.println(readVal);
  delay(10);
}