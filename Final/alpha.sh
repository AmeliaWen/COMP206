#!/bin/bash
#bash script to find the required alphabet
#[]is used for matching one of the char in [], -i is ignore case 
#the ()before| is to list all filenames in current directory but not subdirectory names
final=`(ls -p | grep -v /)| grep -i '[pqrxyx]'`
#loop through all file lists and print out seperately
for f in $final
do
	echo "$f"
done


