#include <ESP8266WiFi.h>
#include <WiFiUDP.h>

#define UDP_PORT 4210

WiFiUDP UDP;
char packet[255];

const char *ssid = "NodeMCU_AP";      // SSID of the NodeMCU hotspot
const char *password = "password123"; // Password for the NodeMCU hotspot

void setup() {
  Serial.begin(9600);
  IPAddress local_IP(192, 168, 4, 22);
  IPAddress gateway(192, 168, 4, 9);
  IPAddress subnet(255, 255, 255, 0);
  
  // Set the NodeMCU as an access point
  WiFi.softAP(ssid, password);

  IPAddress ip = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(ip);
  Serial.print("Local IP: ")
  Serial.print(WiFi.localIP());
  UDP.begin(UDP_PORT);
}

void loop() {
  int packetSize = UDP.parsePacket();
  if (packetSize) {
    int len = UDP.read(packet, 255);
    if (len>0) {
      packet[len] = '\0';
    }
    if (packet == "Q") {
      //If the Packet reads 'Q' then scan using Servo Motor and Ultrasonic sensor
      scan(UDP);
    } else {
      //If the Packet reads 'W', 'A', 'S' or 'D', then move accordingly, else, if 'J' then wait
      Serial.print(packet);
    }
  }
}
