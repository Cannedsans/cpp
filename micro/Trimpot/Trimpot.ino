void setup() {
  pinMode(7,INPUT);
  pinMode(8,OUTPUT);
}

void loop() {
  digitalWrite(8,digitalRead(7));
}
