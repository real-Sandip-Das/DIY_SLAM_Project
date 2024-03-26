const int m1p1 = 2;
const int m1p2 = 3;

const int m2p1 = 4;
const int m2p2 = 5;

const int m1speed = 8;
const int m2speed = 9;

const int speed = 255;

const int servo1 = 2;
const int servo2 = 3;
const int servo3 = 4;

// minimum speed =130
char state='J';

void setup() {
  Serial.begin(9600);  // Set the baud rate to match the communication with the ESP826
  motor_setup(m1p1, m1p2, m2p1, m2p2, m1speed, m2speed);
}

void loop() {
  if (Serial.available() > 0) {
    char state = Serial.read();
    motor_loop(state);
}


