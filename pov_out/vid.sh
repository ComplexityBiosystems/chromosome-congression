#!/bin/bash

#j=1
#while [ $j -le $1 ]; do
#	echo "set terminal png enhanced size 1280,1024; set output 'slice$j.png'; set xrange [0: 100]; set yrange [-0.3: 2.0]; plot 'line$j.dat' using 1:2:3:4:5 with vectors nohead lw 2 lc rgb variable" | gnuplot
#	j=$(($j+1))
#done

~/ffmpeg -f image2 -i slice%d.png -s 800x600 -y moveo.avi

#rm *dat
#rm *png

#vlc video.avi
