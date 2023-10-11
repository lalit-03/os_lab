#!/bin/bash

count=0
for item in $(cat $1)
do 
	let count++
done

echo "There are $count lines"

if [ $count -lt $2 ]; then
	rm "$1"
fi
