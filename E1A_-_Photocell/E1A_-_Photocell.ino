/*
  Photocell - measurements

  Outputs varying values to the Serial monitor depending on the amount of light hitting the photocell.

  Created October 2018
  By José Lara
  for UW HCDE 539 - Physical Computing & Prototyping
  
  Tutorial based on the ArduinoIDE example: BLINK.
  http://www.arduino.cc/en/Tutorial/Blink
*/

// constants won't change. They're used here to set pin numbers:
const int photocellPin = 0;
int photocellReading;

// the setup function runs once when you press reset or power the board
void setup() {
  

  // initialize digital pinMode with A0 as INPUT.
  pinMode(A0, INPUT);

  // initialize serial comms
  Serial.begin(9600);

}

// the loop function runs over and over again forever
void loop() {

  //read the value of the light
  photocellReading = analogRead(A0);
  
  //console write
  Serial.println(photocellReading);

  // wait for a bit
  delay (5000);
}
