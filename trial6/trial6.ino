// challenge

// Inputs: potentiometer, button
// Output: LED

// potentiometer should drive the LED's blink rate
// while the button is held, blink rate halves

//int buttonVal = digitalRead(8);

//if (buttonVal == HIGH); {
// run some code if the button is pressed
// }
//else {
//run code when the button is not pressed
// }

void setup (){
  pinMode(3, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(8, INPUT);

  Serial.begin(9600);
}

void loop(){
  int potVal = analogRead(A0);
  int buttonVal = digitalRead(8);

  if (buttonVal == HIGH) {
    potVal = potVal / 2;
  }
  digitalWrite(3, HIGH);
  delay(500);

  digitalWrite(3, LOW);
  delay(potVal);
}