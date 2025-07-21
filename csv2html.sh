#!/bin/bash
if [[ $# != 2 ]] #Checks for valid number of arguments
then
	echo Usage fixformat.sh '<dirname> <opfile>'
	exit 1
fi
IFS=$'\n' #Makes field seperator a new line. This is done so that it will not print a new line each time there is a space. Source: https://askubuntu.com/questions/344407/how-to-read-complete-line-in-for-loop-with-spaces
file=$(cat $1) #Initializes the variable to the concatenation of the input file
{ #The next commands will be stored to the output file
echo '<TABLE>' #Echoes table at the beginning
for i in $file #For each line of the variable
do
	echo "$i" | sed -e 's/^/<TR><TD>/' -e 's\,\</TD><TD>\g' -e 's\$\</TD></TR>\' #Will add the corresponding information to the correct spot
done 
echo '</TABLE>' #Finally, echoes this to complete the HTML conversion
} > $2
