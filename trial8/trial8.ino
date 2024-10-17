// read a photoresistor (how much light?)
// (read on pin A3)

const int PHOTOPIN = A3;

void setup(){
  pinMode(PHOTOPIN, INPUT);
  Serial.begin(9600);
}

void loop(){
  int photoVal = analogRead(PHOTOPIN);
  Serial.println(photoVal);
  delay(5);
}