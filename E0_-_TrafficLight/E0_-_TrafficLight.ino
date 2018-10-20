/*
  Traffic light

  Turns on/off three colored LEDs pretending to be a stop light.

  Created October 2018
  By José Lara
  for UW HCDE 539 - Physical Computing & Prototyping

  Tutorial based on the ArduinoIDE example: BLINK.
  http://www.arduino.cc/en/Tutorial/Blink
*/

// constants won't change. They're used here to set pin numbers:
const int ledRed = 12;      //pin for the red LED
const int ledYellow = 11;   // the number of the LED pin
const int ledGreen = 10;    // the number of the LED pin

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(ledRed, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledGreen, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  //turn a single LED on, and the other off
  digitalWrite(ledRed, HIGH);
  digitalWrite(ledYellow, LOW);
  digitalWrite(ledGreen, LOW);

  // wait for a bit
  delay (1000);

  //turn the other LED on and the rest off
  digitalWrite(ledRed, LOW);
  digitalWrite(ledYellow, LOW);
  digitalWrite(ledGreen, HIGH); 
  
  // wait for a bit
  delay (1000);

  //turn the other LED on and the rest off
  digitalWrite(ledRed, LOW);
  digitalWrite(ledYellow, HIGH);
  digitalWrite(ledGreen, LOW); 

  // wait for a bit
  delay (1000);
}
