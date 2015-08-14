#!/bin/bash

for file in `ls out*$1`
do
	awk '/./{line=$0} END{print line}' $file
done
