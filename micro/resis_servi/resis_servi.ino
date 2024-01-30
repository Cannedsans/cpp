#include <Servo.h>
Servo motor;
int g =0;
void setup() {
  Serial.begin(9600);
  motor.attach(9);
  motor.write(0);
}

void loop() {
  g = (analogRead(A0)/6);
  Serial.println(g);
  motor.write(g);
  delay(50);
}
