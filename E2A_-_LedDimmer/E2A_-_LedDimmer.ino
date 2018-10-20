/*
 * Assignment 2 Integrated Builds
 * Part 1: Light Dimmer
 * 
 * Author: JoseLara@uw.edu
 * HCDE539A
 * Fall 2018
 */

//Set the constants for the pins
const int pinLed = 3;
const int pinPot = A0;

//Initialize variables that hold the value of inputs/outputs
int potVal = 0;
int ledVal = 0;


void setup() {
  // set the pin mode
  pinMode(pinLed, OUTPUT);
  pinMode(pinPot, INPUT);

  //start serial console
  Serial.begin(9600);

}

//Helper function that prints the position and related variables
//PARAM potVal: the current position of the potentiometer
//PARAM ledVal: the current level of the LED brightness
void printSerial(int potVal, int ledVal)
{
  Serial.print("potVal =");
  Serial.print(potVal);
  Serial.print(" ledVal =");
  Serial.println(ledVal);
}

void loop() {
  //read potentiometer position
  potVal = analogRead(pinPot);

  //set led Value from potentiometer position
  ledVal = map(potVal, 0, 1023, 0, 255);

  //set the led value from the potentiometer position
  analogWrite(pinLed, ledVal);

  //print current values to the serial console
  printSerial(potVal, ledVal);
}
