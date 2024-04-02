#include <ESP8266WiFi.h>

const char *ssid = "NodeMCU_AP";      // SSID of the NodeMCU hotspot
const char *password = "password123"; // Password for the NodeMCU hotspot

void setup() {
  Serial.begin(115200);
  
  // Set the NodeMCU as an access point
  WiFi.softAP(ssid, password);

  IPAddress ip = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(ip);
  Serial.print("Local IP: ", WiFi.localIP());
}

void loop() {
  // Code here
}
