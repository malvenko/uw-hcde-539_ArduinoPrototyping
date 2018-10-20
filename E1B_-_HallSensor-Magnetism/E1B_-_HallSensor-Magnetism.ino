/*
  Traffic light

  Turns on/off three colored LEDs pretending to be a stop light.

  Created October 2018
  By José Lara
  for UW HCDE 539 - Physical Computing & Prototyping
  
   Code based on the https://maker.pro/arduino/tutorial/how-to-use-a-hall-effect-sensor-with-arduino 
*/

// constants won't change. They're used here to set pin numbers:
int sensorReading;

// the setup function runs once when you press reset or power the board
void setup() {

  // initialize pin 8 as INPUT.
  pinMode(8, INPUT);

  // initialize serial comms
  Serial.begin(9600);

}

// the loop function runs over and over again forever
void loop() {

  //read the value of the light
  sensorReading = digitalRead(8);

  //console write
  Serial.print("sensorReading= ");
  Serial.println(sensorReading);
  
  // wait for a bit 
  delay (100);
}
