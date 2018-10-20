/*
  Photocell - Variable LED output

  Varies the intensity of light a LED emits based on the amount of light that hits the photocell.

  Created October 2018
  By José Lara
  for UW HCDE 539 - Physical Computing & Prototyping
  
  Code based on the Adafruit page for the Cds photocell - and Instructables https://www.instructables.com/id/Light-Sensor-Photoresistor-Arduino-Tinkercad/
*/

// constants won't change. They're used here to set pin numbers:
const int photocellPin = 0;
const int ledPin = 3;
int photocellReading;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.

  pinMode(ledPin, OUTPUT);
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {

  //read the value of the light
  photocellReading = analogRead(A0);

  //update the Led
  analogWrite(ledPin, map(photocellReading, 0, 48, 0, 255));
  
  //console write
  Serial.print("photocellReading= ");
  Serial.print(photocellReading);
  Serial.print("   analogWrite=");
  Serial.println(map(photocellReading, 0, 48, 0, 255));
 
  // wait for a bit 
  delay (100);
}
