/**
 * Blink
 * Turns on an LED on for one second,
 * then off for one second, repeatedly.
 */
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

/* #define DEBUG */

const char* WIFI_SSID = "TODO";
const char* WIFI_PASS = "TODO";
const char* MQTT_SERV = "TODO";
const char* MQTT_CHAN = "wtfb";
const char* WTFB_ID   = "TODO";

WiFiClient espClient;
PubSubClient client(espClient);

void setup()
{
#ifdef DEBUG
  Serial.begin(9600);
#endif
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  delay(10);
#ifdef DEBUG
Serial.println();
Serial.print("Connecting to ");
Serial.println(WIFI_SSID);
#endif
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
#ifdef DEBUG
      Serial.print(".");
#endif
  }
#ifdef DEBUG
  Serial.println();
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
#endif
  client.setServer(MQTT_SERV, 1883);
#ifdef DEBUG
  Serial.print("Connecting to ");
  Serial.println(MQTT_SERV);
#endif
  client.connect(WTFB_ID);
#ifdef DEBUG
  Serial.print("Sending \"");
  Serial.print(WTFB_ID);
  Serial.print("\" to channel \"");
  Serial.print(MQTT_CHAN);
  Serial.println("\".");
#endif
#ifdef DEBUG
  if(client.publish(MQTT_CHAN, WTFB_ID)) {
    Serial.println("Sending succeeded");
  } else {
    Serial.println("Sending failed");
  }
#else
  client.publish(MQTT_CHAN, WTFB_ID);
#endif
  client.disconnect();
}

void loop()
{
  while(true) {
    Serial.println("Going to sleep");
    digitalWrite(LED_BUILTIN, HIGH);
    ESP.deepSleep(UINT32_MAX);
  }
}
