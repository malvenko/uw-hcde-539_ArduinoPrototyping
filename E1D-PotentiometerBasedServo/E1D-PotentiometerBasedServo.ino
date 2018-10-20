/*
 * Servo controlled by an additional sensor
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

  //setting up servopin
  myServo.attach(9);

  Serial.begin(9600);
}

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

  printPos(potentiometerVal, servoPos, ledValue);
  
}
