#include <idDHT11.h>

#define pinosig 7

dht sensor;
void setup() {
  Serial.begin(9600);
   delay(2000);
}

void loop() {
  sensor.read11(pinosig);
  Serial.print ("Umidade:");
  Serial.println (sensor.humidity);
  Serial.print ("Temperatura:");
  Serial.println (sensor.temperature);
  delay(100);
}
