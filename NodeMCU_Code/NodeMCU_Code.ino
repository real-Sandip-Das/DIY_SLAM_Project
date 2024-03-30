#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

#include "WiFi.h"

#define UDP_PORT 4210

WiFiUDP UDP;
char packet[256];

void setup() {
  scan_setup(); //sets up the Ultrasonic Sensor for Measuring Distances
  Serial.begin(9600);
  //try connecting to WiFi Hotspot
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
  }
  //connected to WiFi
  UDP.begin(UDP_PORT);
}

void loop() {
  int packetSize = UDP.parsePacket(); //Parse Packet received over UDP
  if (packetSize) {
    int len = UDP.read(packet, 255); //Read Packet received over UDP
    if (len > 0) {
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
