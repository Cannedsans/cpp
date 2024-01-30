/************************* Inclusão das Bibliotecas *********************************/
#include "ESP8266WiFi.h"
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"
 
#include "Adafruit_MCP9808.h"
 
/************************* Conexão WiFi*********************************/
 
#define WIFI_SSID       "everaldo" // nome de sua rede wifi
#define WIFI_PASS       "eve3r@1do"     // senha de sua rede wifi
 
/********************* Credenciais Adafruit io *************************/
 
#define AIO_SERVER      "io.adafruit.com"
#define AIO_SERVERPORT  1883
#define AIO_USERNAME    "Cannednsas" // Seu usuario cadastrado na plataforma da Adafruit
#define AIO_KEY         "aio_pIuZ21rbqLjbkbQZesvW9OHl3Rtg"       // Sua key da dashboard
 
/********************** Variaveis globais *******************************/
 
WiFiClient client;
 
Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_KEY);
 
int rele01 = D5; // pino do rele
 
Adafruit_MCP9808 mcp9808 = Adafruit_MCP9808(); // instancia o objeto do sensor
 
long previousMillis = 0;
 
/****************************** Declaração dos Feeds ***************************************/
 
/* feed responsavel por receber os dados da nossa dashboard */
Adafruit_MQTT_Subscribe _rele01 = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/rele01", MQTT_QOS_1);
 
/* feed responsavel por enviar os dados do sensor para nossa dashboard */
Adafruit_MQTT_Publish _mcp9808 = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/mcp9808", MQTT_QOS_1);
 
/* Observe em ambas declarações acima a composição do tópico mqtt
  --> AIO_USERNAME "/feeds/mcp9808"
  O mpc9808 será justamente o nome que foi dado la na nossa dashboard, portanto o mesmo nome atribuido la, terá de ser colocado aqui tambem
*/
 
/*************************** Declaração dos Prototypes ************************************/
 
void initSerial();
void initPins();
void initWiFi();
void initMQTT();
void initMCP9808();
void conectar_broker();
 
/*************************** Sketch ************************************/
 
void setup() {
  initSerial();
  initPins();
  initWiFi();
  initMQTT();
  initMCP9808();
}
 
void loop() {
  conectar_broker();
  mqtt.processPackets(5000);
 
  // Função responsável por ler e enviar o valor do sensor a cada 5 segundos
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis > 5000 && mqtt.connected()) {
    previousMillis = currentMillis;
 
    mcp9808.shutdown_wake(0);
    float c = mcp9808.readTempC();
 
    delay(200);
    Serial.print("Temp: "); Serial.print(c); Serial.println("*Ct");
 
    if (! _mcp9808.publish(c)) {
      Serial.println("Falha ao enviar o valor do sensor.");
    }
    mcp9808.shutdown_wake(1);
 
  }
}
 
/*************************** Implementação dos Prototypes ************************************/
 
/* Conexao Serial */
void initSerial() {
  Serial.begin(115200);
  delay(10);
}
 
/* Configuração dos pinos */
void initPins() {
  pinMode(rele01, OUTPUT);
  digitalWrite(rele01, HIGH);
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
 
/* Configuração da conexão MQTT */
void initMQTT() {
  _rele01.setCallback(rele01_callback);
  mqtt.subscribe(&_rele01);
}
 
/* Inicialização do Sensor */
void initMCP9808() {
  if (!mcp9808.begin()) {
    Serial.println("Sensor MCP não pode ser iniciado!");
    while (1);
  }
}
 
/*************************** Implementação dos Callbacks ************************************/
 
/* callback responsavel por tratar o feed do rele */
void rele01_callback(char *data, uint16_t len) {
  String state = data;
 
  if (state == "ON") {
    digitalWrite(rele01, LOW);
  } else {
    digitalWrite(rele01, HIGH);
  }
 
  Serial.print("Led: "); Serial.println(state);
 
}
 
/*************************** Demais implementações ************************************/
 
/* Conexão com o broker e também servirá para reestabelecer a conexão caso caia */
void conectar_broker() {
  int8_t ret;
 
  if (mqtt.connected()) {
    return;
  }
 
  Serial.println("Conectando-se ao broker mqtt...");
 
  uint8_t num_tentativas = 3;
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
