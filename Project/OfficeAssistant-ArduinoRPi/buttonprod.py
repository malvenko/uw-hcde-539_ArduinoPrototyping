# Import Raspberry Pi GPIO library
import RPi.GPIO as GPIO 
import time
import sys
import subprocess

# Ignore warning for now
GPIO.setwarnings(False) 
# Use physical pin numbering
GPIO.setmode(GPIO.BOARD) 
# Set pin 10 to be an input pin and set initial value to be pulled low (off)
GPIO.setup(10, GPIO.IN, pull_up_down=GPIO.PUD_DOWN) 

#Defining the action to take whenever the button press is detected
def button_action(channel):
	time.sleep(0.01)
	if GPIO.input(10): #if the button is pressed
		#Debug: Print when the button is preseed
		#print("Button down!")
		#Call the recording process whenever the button is pressed
		subprocess.call(["arecord", "-d","10","--device=plughw:1,0", "-f", "cd", "/home/pi/audio/latest.wav"])
	else:
		#Debug: Print when the button is released
		#print("Button up!")
		#This process never got called. Later to investigate
		#subprocess.call(["sudo","pkill", "arecord"])

# Setup event on pin 10 rising edge
GPIO.add_event_detect(10,GPIO.BOTH,callback=button_action, bouncetime=100) 

#Loop to keep the process running in the background
while True:
	1 = 1

#Cleaning up the GPIO
GPIO.cleanup()
