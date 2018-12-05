#!/bin/bash	

	#use the file specified as parameter
	if [ -z $1 ] ; then
	echo "Please, specify a file to transcribe." && exit 2;
	fi

	#variable to store file to be transcribed
	filename=$1

	#create the base URL for the CURL request
	request_url="https://westus.stt.speech.microsoft.com/speech/recognition/dictation/cognitiveservices/v1?language=en-US"

	#create the variable to use as the string to contain the transcribed message including all CURL params required by the Azure Speech API
	output=$(curl -s -X POST $request_url \
	-H "Ocp-Apim-Subscription-Key: [INSERT SUBSCRIPTION KEY]" \
	-H "Content-type: audio/wav; codec=audio/pcm; samplerate=16000" --data-binary @$1  | jq '.DisplayText') #cat date +%F_%T --utc

	#adding additional datetime attributes to debug
	#datetime=$(date +%F_%T --utc)

echo $output
