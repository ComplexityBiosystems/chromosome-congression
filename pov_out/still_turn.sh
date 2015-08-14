#!/bin/sh
i=$2
j=0
a1=0
tot=$1
rad=120
#for file in `ls BPX* `
while [ $j -le $tot ]
do

###################top to left###############

#	a1=$(echo "scale=2; $rad*s(0.1+1.57*$j/$tot)" |bc -l)
#	a2=$(echo "scale=2; $rad*c(1.57*$j/$tot)" |bc -l)
#	a3=0

##################left to front##############

#	a1=$(echo "scale=2; $rad*c(1.57*$j/$tot)" |bc -l)
#	a2=0
#	a3=$(echo "scale=2; $rad*s(1.57*$j/$tot)" |bc -l)

################# 360 #######################

	a1=$(echo "scale=2; $rad*s(6.28*$j/$tot)" |bc -l)
	a2=0
	a3=$(echo "scale=2; $rad*c(6.28*$j/$tot)" |bc -l)


################# v360v #######################

#	a1=$(echo "scale=2; $rad*s(0.1+1.57*$j/$tot)" |bc -l)
#	a2=$(echo "scale=2; $rad*c(0.1+1.57*$j/$tot)" |bc -l)
#	a3=0

	echo "$a1, $a2, $a3" > angle.dat

	povray -d +W600 +H600 read3-angles.pov
#	povray -d +W300 +H240 read3-angles.pov
	mv read3-angles.png slice$i.png
#	mv read3-angles.png kslice$i.png
	i=$(($i+1))
	j=$(($j+1))
done
