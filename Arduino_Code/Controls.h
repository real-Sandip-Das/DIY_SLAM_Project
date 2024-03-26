const int m1p1 = 2;
const int m1p2 = 3;
const int m2p1 = 5;
const int m2p2 = 6;
const int m1speed = 8;
const int m2speed = 9;
const int speed = 255;

void motor_setup(int m1p1, int m1p2, int m2p1, int m2p2, int m1speed, int m2speed) {
  // put your setup code here, to run once:
  pinMode(m1p1, OUTPUT);
  pinMode(m1p2, OUTPUT);
  pinMode(m2p1, OUTPUT);
  pinMode(m2p2, OUTPUT);

  pinMode(m1speed, OUTPUT);
  pinMode(m2speed, OUTPUT);

  analogWrite(m1speed, speed);
  analogWrite(9, speed);
}

void motor_loop(char state) {
  // put your main code here, to run repeatedly:

  if (state == 'J') {
    halt(); 
             //Serial.println("Halt");
  } else if (state == 'S') {
    backward();
    //Serial.println("Back");
  } else if (state == 'W') {
    forward();
    //Serial.println("Forward");
  } else if (state == 'D') {
    left();
    //Serial.println("Left");
  } else if (state == 'A') {
    right();
    //Serial.println("Right");

    // forward();
    //right();
  }

void forward() {
  analogWrite(m1speed, speed);
  analogWrite(m2speed, speed);
  digitalWrite(m1p1, HIGH);
  digitalWrite(m1p2, LOW);
  digitalWrite(m2p1, LOW);
  digitalWrite(m2p2, HIGH);
}

void backward() {
  analogWrite(m1speed, speed);
  analogWrite(m2speed, speed);
  digitalWrite(m1p1, LOW);
  digitalWrite(m1p2, HIGH);
  digitalWrite(m2p1, HIGH);
  digitalWrite(m2p2, LOW);
}

void right() {
  analogWrite(m1speed, speed);
  analogWrite(m2speed, speed);
  digitalWrite(m1p1, HIGH);
  digitalWrite(m1p2, LOW);
  digitalWrite(m2p1, HIGH);
  digitalWrite(m2p2, LOW);
}

void left() {
  analogWrite(m1speed, speed);
  analogWrite(m2speed, speed);
  digitalWrite(m1p1, LOW);
  digitalWrite(m1p2, HIGH);
  digitalWrite(m2p1, LOW);
  digitalWrite(m2p2, HIGH);
}

void halt() {
  analogWrite(m1speed, 0);
  analogWrite(m2speed, 0);
}

}