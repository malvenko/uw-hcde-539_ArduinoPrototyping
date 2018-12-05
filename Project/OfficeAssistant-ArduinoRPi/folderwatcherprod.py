#!/usr/bin/python
import time
import sys
import logging
import subprocess
from watchdog.observers import Observer
from watchdog.events import PatternMatchingEventHandler
from watchdog.events import LoggingEventHandler

from watchdog.events import FileSystemEventHandler

sys.stdout


# Handler to send the WAV to speech services
class MyHandler(PatternMatchingEventHandler):
    
    #Look for whenever the new file is created
    patterns = ["*latest.wav"] # ["*.xml", "*.txt", "*.wav"]

    def process(self, event):
        """
        event.event_type 
            'modified' #| 'created' | 'moved' | 'deleted'
        event.is_directory
            True | False
        event.src_path
            path/to/observed/file
        """
        # the file will be processed there
        # print for debug
        #print event.src_path, event.event_type  
	
        # TODO: figure out how to know when the transcription is completely output to the file -- creation & transcription happen async
        time.sleep(15)

	# send the wav file to Azure Speech API and obtain a transcription
	# create transcription file
	f = open("/home/pi/audio/latest.txt", "w")
    #Call the bash process to submit the CURL request to transcribe the audio file
	subprocess.call(["sh", "/home/pi/Documents/code/transcriptionprod.sh", "/home/pi/audio/latest.wav"],stdout=f) 
	
	# TODO: figure out how to know when the transcription is completely output to the file -- creation & transcription happen async
	time.sleep(15)

	# copy the file to AzStorage using subsription details and the specific container
	subprocess.call(["python", "/home/pi/Documents/code/azure_upload.py", "/home/pi/Documents/code/acctdetailsprod.txt", "[AzureStorageContainer]", "/home/pi/audio/latest.wav"])
	subprocess.call(["python", "/home/pi/Documents/code/azure_upload.py", "/home/pi/Documents/code/acctdetailsprod.txt", "[AzureStorageContainer]", "/home/pi/audio/latest.txt"])

    #Specifiy the event to carry out on new file created
    def on_created(self, event):
        self.process(event)

#Create the Watchdog Observer
observer = Observer()

#Create event handler 
event_handler = MyHandler()

#Set the path to observe
observer.schedule(event_handler, path='/home/pi/audio')
observer.start()

# sleep until keyboard interrupt, then stop + rejoin the observer
try:
    while True:
        time.sleep(1)
except KeyboardInterrupt:
    observer.stop()

observer.join()
