void setup() {
  // put your setup code here, to run once:
  for(int i=8; i >= 13; i++){
    pinMode(i, OUTPUT);
    }
}
void motor1(int m){
  switch (m){
    case 1:
    digitalWrite(8,HIGH);
    digitalWrite(9,HIGH);
    digitalWrite(10,LOW);
    break;
    case 2:
    digitalWrite(8,HIGH);
    digitalWrite(10,HIGH);
    digitalWrite(9,LOW);
    break;
    default:
    digitalWrite(8,LOW);
    }
  }
  void motor2(int m){
  switch (m){
    case 1:
    digitalWrite(13,HIGH);
    digitalWrite(11,HIGH);
    digitalWrite(12,LOW);
    break;
    case 2:
    digitalWrite(13,HIGH);
    digitalWrite(12,HIGH);
    digitalWrite(11,LOW);
    break;
    default:
    digitalWrite(11,LOW);
    }
  }
void loop() {
  // put your main code here, to run repeatedly:
  motor1(1);
  motor2(1);
  delay (1000);
  motor1(2);
  motor2(2);
  delay(1000);
  motor1(1);
  motor2(2);
  delay(1000);
}
