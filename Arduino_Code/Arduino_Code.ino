#include <Servo.h>
#include "Controls.h"
#include "servo.h"

#define SERVO_PIN 13

Servo myServo;

// minimum speed =130
char given_state = 'J';

void setup() {
  Serial.begin(9600);  // Set the baud rate to match the communication with the ESP826
  motor_setup(m1p1, m1p2, m2p1, m2p2, m1speed, m2speed);
  myServo.write(90);
  myServo.attach(SERVO_PIN);
}

void loop() {
  int angle = 90;
  if (Serial.available() > 0) {
    char state = Serial.read();
    if (state == 'J' || state == 'W' || state == 'A' || state == 'S' || state == 'D') {
      motor_loop(state);
    } else if (state == 'p') {
      angle++;
      myServo.write(angle);
    } else if (state == 'n') {
      angle--;
      myServo.write(angle);
    }
  }
}
