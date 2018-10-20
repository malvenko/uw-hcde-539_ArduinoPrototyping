
const int pinLed = 3;
const int pinPot = A0;

int potVal = 0;
int ledVal = 0;

void setup() {
  // put your setup code here, to run once:

  //
  pinMode(pinLed, OUTPUT);
  pinMode(pinPot, INPUT);
  
  Serial.begin(9600);

}

void printSerial(int potVal, int ledVal)
{
  Serial.print("potVal =");
  Serial.print(potVal);
  Serial.print(" ledVal =");
  Serial.println(ledVal);
}

void loop() {
  // put your main code here, to run repeatedly:

  potVal = analogRead(pinPot);
  ledVal = map(potVal, 0, 1023, 0, 255);

  analogWrite(pinLed, ledVal);

  printSerial(potVal, ledVal);

}
