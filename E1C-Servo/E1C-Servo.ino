/*
  Sweep

  Moves the position of a servo between 0, 90, 180 degrees

  Created October 2018
  By José Lara
  for UW HCDE 539 - Physical Computing & Prototyping  Sweep
  
  Based on the tutorial 
  http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int pos = 0;    // variable to store the servo position

//initialize the components
void setup() {
  // attaches the servo on pin 9 to the servo object
  myservo.attach(9);  

  //initializes the console
  Serial.begin(9600);
}

//helper function to output the current position
//PARAM pos: the current position to be printed in the console
void printPos(int pos)
{
  Serial.print("Position= ");
  Serial.println(pos);
}

//function that runs in the Arduino
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
