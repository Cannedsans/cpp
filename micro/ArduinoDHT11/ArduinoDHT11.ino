#include <DFRobot_DHT11.h>
DFRobot_DHT11 DHT;
#define DHT11_PIN D0

void setup() {
  Serial.begin(115200);
  delay(2000);
}

void loop() {
 DHT.read(DHT11_PIN);
 Serial.print("Temperatura.:");
 Serial.print(DHT.temperature);
 Serial.println(" C");
 Serial.print("Umidade.:");
 Serial.println(DHT.humidity);
 delay(1000);
}
