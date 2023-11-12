#!/bin/bash
#script to check files in directory

arg1="$1"
arg2="$2"
arg@="$@"
if [arg@ -gt 2]
then
	echo Too many arguments
	exit
else
	if [ -d arg1 ]
	then
		for file in arg1
		do
			if [ $file == arg2 ]
			then
				echo Invalid file exists
				break
			fi
		echo $file
		if [[ $arg2 == *$file* ]]
		then
			echo "Warning: Danger detected in name " + $file
		fi
	fi
fi

