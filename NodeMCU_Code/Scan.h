#include <WiFiUDP.h>

const int trigPin = D4;
const int echoPin = D2;

//define sound velocity in cm/microsecond
#define SOUND_VELOCITY 0.034

char message[50];

void send_message(char[] message_arg, WiFiUDP UDP) {
  //Function to send string message 'message_arg' over UDP
  UDP.beginPacket(UDP.remoteIP(), UDP.remotePort());
  UDP.write(message_arg);
  UDP.endPacket();
}

void scan_setup() {
  pinMode(trigPin, OUTPUT);  // Sets the trigPin as an Output
  pinMode(echoPin, INPUT);   // Sets the echoPin as an Input
}

void scan_angle(int angle_degrees, WiFiUDP UDP) {
  double distanceCm;
  long duration;
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);

  // Calculate the distance
  distanceCm = duration * SOUND_VELOCITY / 2;

  //send the information(angle & distance) over UDP
  delay(60);
  sprintf(message, "%d %f", i, dist);
  send_message(message, UDP);
}

void scan(WiFiUDP UDP) {
  for (int i = 90; i > 0; i--) {
    scan_angle(i, UDP);
    serial.print('p');  //assuming counterclockwise convention
  }
  //i = 0
  for (int i = 0; i < 180; i++) {
    scan_angle(i, UDP);
    serial.print('n');
  }
  //i = 180
  for (int i = 180; i > 90; i--) {
    scan_angle(i, UDP);
    serial.print('p')
  }
}