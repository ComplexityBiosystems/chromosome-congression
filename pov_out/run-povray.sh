#!/bin/sh
#i=1
i=$1
a1=0
tot=$1

if [ -f angle.dat ]
then echo "E ang.dat"
else echo "0,0,120">angle.dat
fi
for file in `ls BPX* `
do 
	if [ -f slice$i.png ]
	then
		echo "slice$i.png exists already"
		i=$(($i+1))
	else
	cp $file file.dat

#	a1=$(echo "scale=0; 80*$i/(2*$tot)" |bc)
#	a2=$(echo "scale=0; 10-10*$i/$tot" |bc)
#	a3=$(echo "scale=0; 150*($i-1)/$tot" |bc)

#	echo "$a1, $a2, $a3" > angle.dat

	povray -d +W600 +H600 read3-angles.pov
	mv read3-angles.png slice$i.png
	i=$(($i+1))
	fi
done
