Chromosome-congression 
Copyright 2015 (c) Zsolt Bertalan

This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License 2 as published by  the Free Software Foundation.
    
The softwre is part of the paper "Role of the Number of Microtubules in Chromosome Segregation during Cell Division"
(Zsolt Bertalan, Zoe Budrikis, Caterina A. M. La Porta, Stefano Zapperi, PLOS ONE 2015)

############ Congression Simulation

The program requires the Gnu Scientific Library (GSL)
https://www.gnu.org/software/gsl/

Parameter values are set in the header file headers/constants.h

Compile with 
g++ -o CONGRESS congression.cpp -lgsl -lgslcblas -L/path/to/gsl-lib/ -I/path/to/gal

where the paths for the -I and -L commands should be substituted with 
the location of the gsl library files on your computer (can be omitted if
they are in the standard locations searched by g++)

Run with
./CONGRESS n m

where n is the IDnumber and m is the number of MTs, ex: ./CONGRESS 1 10000


############ 3D Rendering

Povray rendering script, requires povray
http://www.povray.org/

Run with: 
./run_povray

Good luck!
