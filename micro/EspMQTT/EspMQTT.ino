#include "ESP8266WiFi.h"
#include "Adafruit_MQTT_Client.h"
#include <DFRobot_DHT11.h>
DFRobot_DHT11 DHT;
#define WIFI_SSID       "IFSertaoPE-Visitantes" // nome de sua rede wifi
#define WIFI_PASS       "ifsalgueiro"     // senha de sua rede wifi
#define AIO_SERVER      "io.adafruit.com"
#define AIO_SERVERPORT  1883
#define AIO_USERNAME    "Cannednsas" // Seu usuario cadastrado na plataforma da Adafruit
#define AIO_KEY         "aio_pIuZ21rbqLjbkbQZesvW9OHl3Rtg"       // Sua key da dashboard

WiFiClient client;
 
Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_KEY);
 
Adafruit_MQTT_Publish dht11 = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/dht11", MQTT_QOS_1);
void initSerial();
void initPins();
void initWiFi();
void initMQTT();
void conectar_broker();
 
void setup() {
  initSerial();
  initPins();
  initWiFi();
  initMQTT();
}
 
void loop() {
  DHT.read(A0);
  conectar_broker();
  mqtt.processPackets(5000);
    delay(200);
    Serial.print("Temp: "); Serial.print(DHT.temperature); Serial.println("*Ct");
 
    if (! dht11.publish(DHT.temperature)) {
      Serial.println("Falha ao enviar o valor do sensor.");
    }
 delay(5000);
    }
/* Conexao Serial */
void initSerial() {
  Serial.begin(115200);
  delay(10);
}
 
/* Configuração da conexão WiFi */
void initWiFi() {
  Serial.print("Conectando-se na rede "); Serial.println(WIFI_SSID);
 
  WiFi.begin(WIFI_SSID, WIFI_PASS);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
 
  Serial.println("Conectado à rede com sucesso"); Serial.println("Endereço IP: "); Serial.println(WiFi.localIP());
}
 
 
