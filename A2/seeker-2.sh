#!/bin/bash
# Amelia Cui
#260824815 

if test "$#" -eq 0
then
	echo "Error missing the pattern argument."
	echo "Usage ./seeker.sh [-c] [-a] pattern [path]"
fi
touch error.txt
if test "$#" -eq 1
then
	if [ $1 == '-c' ] || [ $1 == '-a' ];
	then
		echo "Error missing the patteren argument."
		echo "Usage ./seeker.sh [-c][-a] pattern [path]"
	else
		msg=$1
		result="`ls *$msg* 2> error.txt`" 
		if [ -z "$result" ]
		then
			echo "Unable to locate any files that has pattern "$1" in its name in `pwd`"
		else
			set $result
			echo ""`pwd`"/"$1""
		fi
	fi
	exit 1
fi
if test "$#" -eq 2
then
	if ([ $1 == '-c' ] && [ $2 == '-a' ])||([ $1 == '-a' ] && [ $2 == '-c' ]);
	then
		echo "Error missing the pattern argument."
		echo "Usage ./seeker.sh [-c][-a] pattern [path]"
		exit 1
	else
		if [ $1 == '-c' ]
		then
			msg=$2
			result="`ls *$msg* 2> error.txt`"
			if [ -z "$result" ]
			then
				echo "Unable to locate any files that has pattern "$2" in its name in `pwd`"
			else
				set $result
				echo "==== Contents of:"`pwd`"/"$1"===="
				echo "`cat $1`"
			fi
		elif [ $1 == '-a' ]
		then
			msg=$2
			result="`ls *$msg* 2> error.txt`"
			if [ -z "$result" ]
			then
				echo "Unable to locate any files that has pattern "$2" in its name in `pwd`"
			else
				for a in $result; do
				echo ""`pwd`"/"$a""
			done
			fi
		else
			msg=$1
			path=$2
			if [ ! -d "$2" ]
			then
				echo "Error "$2" is not a valid directory"
				exit 1
			fi
			cd $path
			result="`ls *$msg* 2>error.txt`"
			if [ -z "$result" ]
			then
				echo "Unable to locate any files that has pattern "$1" in its name in "$2""
			else
                set $result
				echo ""$path"/"$1""
			fi
			cd /home/2020/wcui6
		fi
	fi
fi
if test "$#" -eq 3
then
	if ([ $1 == '-c' ] && [ $2 == '-a' ])||([ $1 == '-a' ] && [ $2 == '-c' ])
	then
		msg=$3
		result="`ls *$msg* 2> error.txt`"
		if [ -z "$result" ]
		then
			echo "Unable to locate any files that has pattern "$3" in its name in `pwd`"
		else
			for a in $result; do
				echo "====contents of `pwd`/$a ===="
			echo "`cat $a`"
		done
		fi
	elif [ $1 == '-c' ]
	then
		msg=$2
		if [ ! -d "$3" ]
		then
			echo "Error "$3" is not a valid directory"
			exit 1
		fi
		path=$3
		cd $path
		result="`ls *$msg* 2> error.txt`"
		if [ -z "$result" ]
		then
			echo "Unable to locate any files that has pattern "$2" in its name in "$3""
		else
			set $result
			echo "====contents of $path/$1 ===="
			echo "`cat $1`"
		fi
		cd /home/2020/wcui6
	elif [ $1 == '-a' ]
	then
		msg=$2
		if [ ! -d "$3" ]
		then
			echo "Error "$3" is not a valid directory"
			exit 1
		fi
		path=$3
		cd $path
		result="`ls *$msg* 2> error.txt`"
		if [ -z "$result" ]
		then
			echo "Unable to locate any flies that has pattern "$2" in its name in "$3""
		else
			for a in $result; do
				echo ""$3"/"$a""
			done
		fi
		cd /home/2020/wcui6
	fi
fi
if test "$#" -eq 4
then
	if ([ $1 == '-c' ] && [ $2 == '-a' ]) || ([ $1 == '-a' ] && [ $2 == '-c' ])
	then
		msg=$3
		path=$4
		if [ ! -d "$path" ]
		then
			echo "Error "$path" is not a valid directory"
			exit 1
		fi
		cd $path
		result="`ls *$msg* 2>error.txt`"
		if [ -z "$result" ]
		then
			echo "Unable to locate any files that has pattern "$3" in its name in "$4""
		else
			for a in $result; do 
				echo "==== contents of $path/$a ===="
			echo "`cat $a`"
		done
		fi
		cd /home/2020/wcui6
	else
		exit 1
	fi
fi
rm error.txt
exit 0 

