// Function to rotate servo by 10 degrees
/*
void rotateServo() {
  static int angle = 90;  // Static variable to keep track of servo angle

  // Increment angle by 10 degrees
  angle += 10;

  // Make sure angle stays within 0 to 180 degrees
  angle = constrain(angle, 0, 180);

  // Rotate the servo to the new angle
  myServo.write(angle);

  // Print the current angle to serial monitor (optional)
  Serial.print("Servo angle: ");
  Serial.println(angle);
}
*/
/*
while true{
  while (angle>=0){
    angle-=1;
    myServo.write(angle);
  
  while (angle<=180){
    angle+=1;
    myServo.write(angle);
  
  
  while (angle>=90){
    angle-=1;
    myServo.write(angle);
  
  break;
  }
*/