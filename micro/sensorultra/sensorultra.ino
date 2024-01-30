#include <HCSR04.h>
#define echo 5
#define trig 6

UltraSonicDistanceSensor distanceSensor(echo, trig);
void setup() {
 Serial.begin(9600);
 pinMode(4,OUTPUT);
 pinMode(7,OUTPUT);
 digitalWrite(4,HIGH);
 digitalWrite(7,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(distanceSensor.measureDistanceCm());
  delay(500);
}
