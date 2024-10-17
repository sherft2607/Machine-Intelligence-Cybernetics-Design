// blink an external LED
// attached to pin 5

void setup(){
  pinMode(5,OUTPUT);
  pinMode(3,OUTPUT);
}

void loop(){
  digitalWrite(5, HIGH);
  delay(500);
  digitalWrite(5, LOW);
  delay(100);
  digitalWrite(3, HIGH);
  delay(500);
  digitalWrite(3, LOW);
  delay(100);
}

