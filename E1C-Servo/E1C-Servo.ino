/* Sweep
 Based on the tutorial 
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int pos = 0;    // variable to store the servo position

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);
}

void printPos(int pos)
{
  Serial.print("Position= ");
  Serial.println(pos);
}

void loop() {
  //Move the arm to intial position
  pos = 0;
  myservo.write(pos);

  //print the current position
  printPos(pos);

  //wait
  delay(500);
  
  //move the arm to the middle position
  pos = 90;
  myservo.write(pos);

  //print the current position
  printPos(pos);

  //wait
  delay(500);
 
  //move the arm to the final position
  pos = 180;
  myservo.write(pos);
 
    //print the current position
  printPos(pos);

  //wait
  delay(500);  
}
