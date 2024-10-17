// read a potentiometer's value
// (attached to pin A0)
// and print it to the computer user

void setup(){
  pinMode(A0, INPUT);

  //open the serial communication port
  //to talk back to the computer 
  Serial.begin(9600);
}

void loop(){
  //making a new variable of type 'int'
  // calling that variable 'potVal'
  // setting the value of it to 0
  int potVal = 0;

  // do the analogRead
  // and store the value into potVal
  potVal = analogRead(A0);

  // send data back to the computer
  // specifically, send potVal's value
  Serial.println(potVal);
}