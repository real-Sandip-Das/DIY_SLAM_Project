#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

#include "WiFi.h"

#define UDP_PORT 4210

WiFiUDP UDP;
char packet[255];
char reply[] = "Packet Recieved!";

void setup() {
   
  Serial.begin(9600);
  Serial.println();
  
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  Serial.print("Connecting to ");
  Serial.print(WIFI_SSID);

  while (WiFi.status() !=WL_CONNECTED){
    delay(100);
    Serial.print("."); 
  }
Serial.println();
Serial.print("Connected IP address: ");
Serial.print(WiFi.localIP());

UDP.begin(UDP_PORT);
Serial.print("Listening on UDP port");
Serial.println(UDP_PORT);

}

void loop() {

  int packetSize = UDP.parsePacket();
  // if(packetSize) {
  //   Serial.print("Recieved Packet Size:");
  //   Serial.println(packetSize);
  //   int len = UDP.read(packet, 255);
  //   if (len>0){
  //     packet[len] = '\0';
  //   }
  //   Serial.print("Packet recieved");
  //   Serial.println(packet);

  //   UDP.beginPacket(UDP.remoteIP(), UDP.remotePort());
  //   UDP.write(reply);
  //   UDP.endPacket();
  //}
  
  // Check if there is data available to read from NodeMCU
  if (Serial.available() > 0) {
    // Read the incoming byte from NodeMCU
    char incomingByte = Serial.read();
    
    // Send the incoming byte to another Arduino via serial connection
    Serial.write(incomingByte); // Assuming you're using Serial1 for communication with the other Arduino
  }
}
