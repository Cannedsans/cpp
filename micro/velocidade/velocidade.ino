int v = 0;
void setup() {
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
}

void loop() {
  v = analogRead(A0)/5;
  if (v < 50){
    v = 50;}
  digitalWrite(4,LOW);
  digitalWrite(2,HIGH);
  delay(v);
  digitalWrite(2,LOW);
  digitalWrite(3,HIGH);
  delay(v);
  digitalWrite(3,LOW);
  digitalWrite(4,HIGH);
  delay(v);

}
