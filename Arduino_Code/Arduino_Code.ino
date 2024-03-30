#include <Servo.h>
#include "Controls.h"
#include "servo.h"
int angle;
#define SERVO_PIN 13

Servo myServo;

// minimum speed =130
char given_state = 'J';

void setup() {
  Serial.begin(9600);  // Set the baud rate to match the communication with the ESP826
  motor_setup();
  myServo.write(90);
  myServo.attach(SERVO_PIN);
  angle = 90;
}

void loop() {

  if (Serial.available() > 0) {
    char state = Serial.read();
    if (state == 'J' || state == 'W' || state == 'A' || state == 'S' || state == 'D') {
      motor_loop(state);
    } else if (state == 'P') {
      angle +=10;
      myServo.write(angle);
    } else if (state == 'N') {
      angle -=10;
      myServo.write(angle);
    }
  }
}
