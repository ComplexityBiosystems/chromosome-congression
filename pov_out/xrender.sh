#!/bin/bash
if [ -f angle.dat ]
then echo " "
else echo "0,0,120" > angle.dat
fi


	povray -d +W1200 +H1200 read3-angles.pov
#	wait
#	eog read3-angles.png
