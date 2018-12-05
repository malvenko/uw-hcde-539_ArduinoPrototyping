
/*
 * HCDE 539 Project: Office Assistant
 * Prototype 2: Detecting orientation
 * 
 * Based on code from: https://create.arduino.cc/projecthub/Nicholas_N/how-to-use-the-accelerometer-gyroscope-gy-521-6dfc19
 * Based on code from HCDE539 - Button Examples
 * 
 * Uses Accelerometer/Gyro GY521 to detect current orientation, and depending on the orientation, illuminates an LED.
 * 
 * Author: JoseLara@uw.edu; Wamwitha@uw.edu
 * HCDE539A
 * Fall 2018
 */

#include<Wire.h>
#include <math.h>
const int MPU=0x68;

//Variables to store acceleration, temp, gyro values
int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;
double pitch,roll;

//variable to store the current orientation side
int side;

//variable to store buttonLedBrightness
int buttonLedBrightness = 0;
int buttonLedBrightnessDirection = 1;

//variable to store recording state (0:not recording, 1:recording, 2:recording complete)
int recordingState = 0;

//Declaring the pins for the LEDs
const int ledRedPin = 6;
const int ledGreenPin = 5;
const int ledYellowPin = 7;

//Declaring the pins for the button
const int buttonLedPin = 9;

//Delcaring the pin for the RaspberryPi
const int rpiPin = 3;

//RaspberryPi pin state
int rpiPinState = 0;

void setup(){
  Wire.begin();
  Wire.beginTransmission(MPU);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);

  //setting up the LEDs
  pinMode(ledRedPin, OUTPUT);
  pinMode(ledGreenPin, OUTPUT);
  pinMode(ledYellowPin, OUTPUT);
  pinMode(buttonLedPin, OUTPUT);

  //setting up the RaspberryPi pin
  pinMode(rpiPin, INPUT);
  
  //start the serial console
  Serial.begin(9600);
}

void loop(){

  Wire.beginTransmission(MPU);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU,14,true);
  
  int AcXoff,AcYoff,AcZoff,GyXoff,GyYoff,GyZoff;
  int temp,toff;
  double t,tx,tf;
  
  //Acceleration data correction
  AcXoff = -950;
  AcYoff = -300;
  AcZoff = 0;
  
  //Temperature correction
  toff = -1600;
  
  //Gyro correction
  GyXoff = 480;
  GyYoff = 170;
  GyZoff = 210;
  
  //read accel data
  AcX=(Wire.read()<<8|Wire.read()) + AcXoff;
  AcY=(Wire.read()<<8|Wire.read()) + AcYoff;
  AcZ=(Wire.read()<<8|Wire.read()) + AcYoff;
  
  //read temperature data
  temp=(Wire.read()<<8|Wire.read()) + toff;
  tx=temp;
  t = tx/340 + 36.53;
  tf = (t * 9/5) + 32;
  
  //read gyro data
  GyX=(Wire.read()<<8|Wire.read()) + GyXoff;
  GyY=(Wire.read()<<8|Wire.read()) + GyYoff;
  GyZ=(Wire.read()<<8|Wire.read()) + GyZoff;
  
  //get pitch/roll
  getAngle(AcX,AcY,AcZ);
  
  //get the side
  side = round((AcX*1/30000)+(AcY*2/30000)+(AcZ*3/30000));
  
  //send the data out the serial port
  /*
  Serial.print("Angle: ");
  Serial.print("Pitch = "); Serial.print(pitch);
  Serial.print(" | Roll = "); Serial.print(roll);
  
  Serial.print("   Temp: ");
  Serial.print("Temp(F) = "); Serial.print(tf);
  Serial.print(" | Temp(C) = "); Serial.print(t);
  
  
  Serial.print("Accelerometer: ");
  Serial.print("X = "); Serial.print(AcX);
  Serial.print(" | Y = "); Serial.print(AcY);
  Serial.print(" | Z = "); Serial.print(AcZ);
  
  Serial.print("   Gyroscope: ");
  Serial.print("X = "); Serial.print(GyX);
  Serial.print(" | Y = "); Serial.print(GyY);
  Serial.print(" | Z = "); Serial.print(GyZ);
  
  Serial.print(" | SIDE = "); Serial.println(side);
  */


  //Illuminate the LEDs depending on the side the cube is facing
  if(side == 1)
  {
    digitalWrite(ledRedPin, LOW);
    digitalWrite(ledGreenPin, LOW);
    digitalWrite(ledYellowPin, HIGH);
  }
  else if (side == -1)
  {
    digitalWrite(ledRedPin, HIGH);
    digitalWrite(ledGreenPin, LOW);
    digitalWrite(ledYellowPin, LOW);  
  }
  else if (side == 0)
  {
    digitalWrite(ledRedPin, LOW);
    digitalWrite(ledGreenPin, HIGH);
    digitalWrite(ledYellowPin, LOW);  
  }

  //get the recording state sent from the RaspberryPi pin
  rpiPinState = digitalRead(rpiPin); 
  Serial.println(rpiPinState);
  recordingState = rpiPinState;
  

  //Make the recording button fade in/out
  if(recordingState ==0)
  {
      if(buttonLedBrightnessDirection == 1)
      {
        analogWrite(buttonLedPin, buttonLedBrightness);
        buttonLedBrightness+=1;
        if(buttonLedBrightness == 255)
        {
          buttonLedBrightnessDirection = -1;   
        }
      }
      else if(buttonLedBrightnessDirection == -1)
      {
        analogWrite(buttonLedPin, buttonLedBrightness);
        buttonLedBrightness-=1;
        if(buttonLedBrightness == 0)
        {
          buttonLedBrightnessDirection = 1;   
        }
      } 
   } 
   //make the button LED blink constantly when the recording mode is detected
   if(recordingState ==1)
   {
      
        analogWrite(buttonLedPin, 255);
        buttonLedBrightness=0;
        buttonLedBrightnessDirection = 1;
        delay(100);
        analogWrite(buttonLedPin, 0);
        buttonLedBrightness=0;
        buttonLedBrightnessDirection = 1;
        delay(100);
   }
      
      
  //Serial.println(" ");
  delay(10); 
}

//convert the accel data to pitch/roll
void getAngle(int Vx,int Vy,int Vz) {
double x = Vx;
double y = Vy;
double z = Vz;
}
