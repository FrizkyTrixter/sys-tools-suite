#!/bin/bash
if [[ $# != 2 ]] #Checks if the program received two files as input
then
	echo Usage fixformat.sh '<dirname> <opfile>'
	exit 1
fi
if [[ ! -d $1 ]] #Checks if $1 is a valid directory
then
	echo Error $1 is not a valid directory
	exit 1
fi
{ #Open bracket here because everything outputted will be sent to the file
echo User Email, Name '(Original Name),Lab,Total Duration (Minutes)'
for i in $(find $1 -iname lab-*.csv) #For file in given directory hierarchy
do
	k=$(echo $(basename $i) | sed -e 's/[Ll][Aa][Bb]-//' -e 's/.csv//') #This gets the lab letter
	awk 'BEGIN {k = "Nothing"; FS = ","} #Initializes field seperator to comma and k to "Nothing"
	{if($0 == "Name (Original Name),User Email,Total Duration (Minutes),Guest") #If this is the first line, then k will become that
	{k = "Name (Original Name),User Email,Total Duration (Minutes),Guest"}
else if($0 == "Name (Original Name),User Email,Join Time,Leave Time,Duration (Minutes),Guest")
	{k = "Nothing"}
else if (k == "Name (Original Name),User Email,Total Duration (Minutes),Guest") #If K is equal to this
	{print $2","$1","$3} #Prints this
	else
	{print $2","$1","$5} 
	}' < $i | sed -e "s/[,]/,$k,/g2" #Places the lab letter in the correct spot 
done
}> $2
