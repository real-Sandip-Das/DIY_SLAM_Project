void motor_setup(int m1p1, int m1p2, int m2p1, int m2p2, int m1speed, int m2speed) {
  // put your setup code here, to run once:
 pinMode(m1p1, OUTPUT);
 pinMode(m1p2, OUTPUT);
 pinMode(m2p1, OUTPUT);
 pinMode(m2p2, OUTPUT);

 pinMode(m1speed, OUTPUT);
 pinMode(m2speed, OUTPUT);

 analogWrite(8, speed) ;
 analogWrite(9, speed);

 }

void motor_loop(char state) {
  // put your main code here, to run repeatedly:

  if (state == 'J') {
  halt(); // Turn LED OFF
  //Serial.println("Halt");
 }
 else if (state == 'S') {
  back();
  //Serial.println("Back");
 } 
 else if (state == 'W') {
  forward();
  //Serial.println("Forward");
 } 
 else if (state == 'D') {
  left();
  //Serial.println("Left");
 } 
 else if (state == 'A') {
  right();
  //Serial.println("Right");

// forward(); 
//right();

}

void forward() {
  analogWrite(8, speed);
  analogWrite(9, speed);
  digitalWrite(m1p1, HIGH);
  digitalWrite(m1p2, LOW);
  digitalWrite(m2p1, LOW);
  digitalWrite(m2p2, HIGH);
}

void backward() {
  analogWrite(8, speed);
  analogWrite(9, speed);
  digitalWrite(m1p1, LOW);
  digitalWrite(m1p2, HIGH);
  digitalWrite(m2p1, HIGH);
  digitalWrite(m2p2, LOW);
}

void right() {
  analogWrite(8, speed);
  analogWrite(9, speed);
  digitalWrite(m1p1, HIGH);
  digitalWrite(m1p2, LOW);
  digitalWrite(m2p1, HIGH);
  digitalWrite(m2p2, LOW);
}

void left() {
  analogWrite(8, speed);
  analogWrite(9, speed);
  digitalWrite(m1p1, LOW);
  digitalWrite(m1p2, HIGH);
  digitalWrite(m2p1, LOW);
  digitalWrite(m2p2, HIGH);
}
 
void halt() {
  analogWrite(8, 0);
  analogWrite(9, 0);
}
