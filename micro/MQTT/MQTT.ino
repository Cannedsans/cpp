#include "ESP8266WiFi.h"
#include "Adafruit_MQTT_Client.h"
#include <DFRobot_DHT11.h>
DFRobot_DHT11 DHT;
#define WIFI_SSID       "IFSertaoPE-Visitantes" // nome de sua rede wifi
#define WIFI_PASS       "ifsalgueiro"     // senha de sua rede wifi
#define AIO_SERVER      "io.adafruit.com"
#define AIO_SERVERPORT  1883
#define AIO_USERNAME    "Cannednsas" // Seu usuario cadastrado na plataforma da Adafruit
#define AIO_KEY         "aio_pIuZ21rbqLjbkbQZesvW9OHl3Rtg" //key

WiFiClient client;
 
Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_KEY);
 
Adafruit_MQTT_Publish dht11 = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/dht11", MQTT_QOS_1);
void setup() {
  DHT.read(D0);
  Serial.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  
  int8_t ret;
 
  if (mqtt.connected()) {
    return;
  }
 
  Serial.println("Conectando-se ao broker mqtt...");
 
  int8_t num_tentativas = 3;
  while ((ret = mqtt.connect()) != 0) {
    Serial.println(mqtt.connectErrorString(ret));
    Serial.println("Falha ao se conectar. Tentando se reconectar em 5 segundos.");
    mqtt.disconnect();
    delay(5000);
    num_tentativas--;
    if (num_tentativas == 0) {
      Serial.println("Seu ESP será resetado.");
      while (1);
    }
  }
 
  Serial.println("Conectado ao broker com sucesso.");
}

void loop() { 
  mqtt.processPackets(5000);
  DHT.read(D0);
  int c = DHT.temperature;
    delay(200);
    Serial.print("Temp: "); Serial.print(c); Serial.println("C");
 
    if (! dht11.publish(DHT.temperature)) {
      Serial.println("Falha ao enviar o valor do sensor.");
    }
 Serial.write(DHT.temperature);
 delay(500);
}
