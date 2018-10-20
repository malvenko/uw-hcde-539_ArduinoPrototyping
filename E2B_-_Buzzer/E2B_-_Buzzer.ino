/*
 * Assignment 2 Integrated Builds
 * Part 2: Buzzer
 * 
 * Based on code from: https://www.instructables.com/id/How-to-use-a-Buzzer-Arduino-Tutorial/ 
 * Based on code from HCDE539 - Button Examples
 * 
 * Author: JoseLara@uw.edu
 * HCDE539A
 * Fall 2018
 */

// import the ButtonLib
#include <Button.h>

//Set the constants for the pins
const int pinLed = 7;
const int pinBuzz = 3;
const int btnPin = 2;

//init button object
Button butt (btnPin);

void setup() {
  //config pins for output
  pinMode(pinBuzz, OUTPUT);
  pinMode(pinLed, OUTPUT);

  //initialize serial comms
  Serial.begin(9600);
  
}

void loop() {

  //get button state
  int action = butt.checkButtonAction();

  //check button state and if held or pressed, turn on buzzer and LED for 1 second
  if (action == Button::HELD_CLICKED or action == Buetton::CLICKED) {
    tone(pinBuzz, 500); // Send 1KHz sound signal
    digitalWrite(pinLed, HIGH);
    delay(1000);
  }
  else{
    noTone(pinBuzz);     // Stop sound...
    digitalWrite(pinLed, LOW);
  }

  //print button state to console
  Serial.print("Button Action= ");
  Serial.println(action);
}
