#!/bin/bash
#this is the function for gcd
function div(){
	local result
	#temp stores the smaller number passed
	temp=$2
	if [[ $1 -lt $2 ]]
	then
		temp=$1
	fi
	#if the smaller number is 1 gcd is 1
	if [[ $temp -eq 1 ]]
	then
		echo "Largest divider of $1 and $2 is 1"
		return
	fi
	#else divide both X and Y with N, check if remainder is zero, if not, decrement N by 1 and continue this process.
	result=1
	while [[ $temp -gt 1 ]]
	do
	if [[ ($(( $1%$temp )) -eq 0) && ($(( $2%$temp )) -eq 0 ) ]]
	then
		result=$temp
	fi
	temp=$(($temp-1))
done
echo "Largest divider of $1 and $2 is $result"
}

cont=true
#use cont as boolean var to check loop or not
while [ $cont = true ]
do
	echo "Enter first number: "
	read first
	echo "Enter second number: "
	read second
	div $first $second
	echo "Do you wish to continue ?"
	read conti
	if [[ $conti = y ]]
	then
		cont=true
	fi
	if [[ $conti = n ]]
	then
		cont=false
		break;
	fi
done
exit 0



