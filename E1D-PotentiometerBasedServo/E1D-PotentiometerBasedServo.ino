/*
 Servo controlled by an additional sensor

  Moves the position of a servo by using a potentiometer

  Created October 2018
  By José Lara
  for UW HCDE 539 - Physical Computing & Prototyping  Sweep
  
  Based on the tutorial 
  http://www.arduino.cc/en/Tutorial/Sweep
 */

#include <Servo.h>

const int pinLed = 3;
const int pinPotentiometer = A0;

Servo myServo;

int potentiometerVal = 0;
int servoPos = 0;
int ledValue = 0;

void setup() {

  //setting up pins
  pinMode(pinPotentiometer, INPUT);
  pinMode(pinLed, OUTPUT);

  //setting up servo pin
  myServo.attach(9);

  //initialize serial console
  Serial.begin(9600);
}

//Helper function that prints the position and related variables
//PARAM potentiometerPos: the current position of the potentiometer
//PARAM servoPos: the current position of the servo
//PARAM ledValue: the current level of the LED brightness
void printPos(int potentiometerPos, int servoPos, int ledValue)
{
  Serial.print("potentiometer position=");
  Serial.print(potentiometerPos);
  Serial.print(" servo position=");
  Serial.print(potentiometerPos);
  Serial.print(" led value=");
  Serial.println(potentiometerPos);
}

void loop() {

  //read the potentiometer position
  potentiometerVal = analogRead(pinPotentiometer);
  
  //map the potentiometer thresholds to the servo position range
  servoPos = map(potentiometerVal, 0, 1023, 0, 180);

  //set the servo position to the potentiometer setting
  myServo.write(servoPos);

  //Set the LED brightness to the potentiometer setting
  ledValue = map(potentiometerVal, 0, 1023, 0, 255);
  analogWrite(pinLed, ledValue);

  //print current values to console
  printPos(potentiometerVal, servoPos, ledValue);
  
}
