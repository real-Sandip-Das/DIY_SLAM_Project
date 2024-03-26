#include <Servo.h>
#include "Controls.h"
#include "servo.h"

#define SERVO_PIN 13

Servo myServo;

// minimum speed =130
char given_state='J';

void setup() {
  Serial.begin(9600);  // Set the baud rate to match the communication with the ESP826
  motor_setup(m1p1, m1p2, m2p1, m2p2, m1speed, m2speed);
  myServo.attach(SERVO_PIN);
}

void loop() {
  if (Serial.available() > 0) {
    char state = Serial.read();
    motor_loop(state);
    //if (state == 'p' || state == 'n') {
    //rotateServo();
    }
}

/*
void setup() {
  myServo.attach(SERVO_PIN);
}

void loop() {
  myServo.write(180);
  delay(2000);
  myServo.write(0);
  delay(2000);
}

*/