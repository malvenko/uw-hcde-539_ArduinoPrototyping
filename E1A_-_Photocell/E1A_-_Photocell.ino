/*
  Traffic light
  Tutorial based on the ArduinoIDE example: BLINK.
  http://www.arduino.cc/en/Tutorial/Blink
*/

// constants won't change. They're used here to set pin numbers:
const int photocellPin = 0;
int photocellReading;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.

/*
  pinMode(ledRed, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledGreen, OUTPUT);
*/

  pinMode(A0, INPUT);
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
