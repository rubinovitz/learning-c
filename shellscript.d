#!/bin/bash
# find full date (month, day, year)
fulldate=`date +%m/%d/%Y`
# find current time hour:minutes:seconds
newtime=`date +%k:%M:%S`
# find am or pm of time
ampm=`date +%p`
# find host name
HOSTNAME=`/bin/hostname`
# print user, host, hours:min: sec with am or pm, and the month,day,year
echo "$USER is running this script on $HOSTNAME at $newtime $ampm on 
$fulldate:" 
echo " "
# Ask for line1, line2, line3, line4
echo -n "Please enter 4 lines of text:"
echo " "
# read each response
read line1
read line2 
read line3 
read line4
# set line1 as the longest line
longestline=$line1
# if the length of line2 is longer than the default longest line, line1
if [ ${#longestline} -lt ${#line2} ]
then
# then line2 is the longest line
longestline=$line2
fi
# if the longest line has less characters than line3...
if [ ${#longestline} -lt ${#line3} ]
then
# line3 is the longest line
longestline=$line3
fi
# if the longest line is less than line 4...
if [ ${#longestline} -lt ${#line4} ]
then
# line4 is the longest line
longestline=$line4
fi
# print longest line
echo " "
echo "The longest line you entered was:"
echo " $longestline"
echo " "
echo "I'm now putting the four lines you entered into a text file called 
\"mylines.txt\"..."
# put lines 1-4 into homework1.txt as their each line
echo $line1$'\n'$line2$'\n'$line3$'\n'$line4 >> mylines.txt
echo " "
echo "I'm now going to reverse sort the \"mylines.txt\" file and save the 
reserved sorted lines in a new file called 
\"mylines_sorted_backwards.txt\". And now I'm going to display that file 
for you:"
echo "---------------------------------------------"
# reverse sort the 4 lines
reversed=`cat ./mylines.txt | sort -d -r | head -n 4`
# put the reversed lines into my_lines_sorted_backwards.txt
echo $reversed >> my_lines_sorted_backwards.txt
# print the reversed lines
echo "$reversed"
echo "---------------------------------------------"
echo ""
echo "Now I'm going to show you only the lines that have \"light\" in them 
from your original four lines (not the sorted lines):"
echo "---------------------------------------------"
# find lines with the word light in them in mylines.txt and print them
cat mylines.txt | grep -i light
echo "---------------------------------------------"

