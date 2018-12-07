#!/bin/bash

#program running in the background that detects when a recording is kicked off, then kills the recording after 13 secs, and resets the python code for the recording button to reset it for the next recording 

while true; do
  if pgrep -f arecord
  then
#	echo sleep13
	sleep 13;
#	echo sleep13done
#	echo killarecord
	sudo pkill arecord
#	echo killedarecord
#	echo killbuttonprod
	sudo pkill -9 -f buttonprod.py
#	echo killedbuttonprod
#	echo sleep1 
	sleep 1
#	echo slept1
#	echo runbuttonprod
	sudo python /home/pi/Documents/code/buttonprod.py &
#	echo ranbuttonprod
  fi
done
