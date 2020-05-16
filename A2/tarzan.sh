#!/bin/bash
#Amelia Cui 
#260824815 
if test "$#" -lt 2   
then
	echo "Usage ./tarzan.sh filename tarfile";
	exit 1;
fi
tarfile=$2
filename=$1
if [ ! -f "$tarfile" ] 
then
	echo "Error cannot find tar file "$tarfile""; 
	exit 1;
else
	result="`tar -tvf "$tarfile" | grep -i "$filename"`"
	
fi

if [ -z "$result" ]
then 
	echo " "$filename" does not exist in "$tarfile"";
else
	echo " "$filename" exists in "$tarfile"";
fi


