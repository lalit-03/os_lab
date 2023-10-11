#!/bin/bash

if [ $# -eq 0 ]; then
	echo "Arguments not provided."
fi

echo $1 | rev

