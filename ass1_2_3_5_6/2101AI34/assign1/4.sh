#!/bin/bash

count=0

for filename in $1/$2; do
	echo $filename
	let count++
	mv $filename "$1/$3_$count"
	echo $filename "changed to" "$3_$count"
done
