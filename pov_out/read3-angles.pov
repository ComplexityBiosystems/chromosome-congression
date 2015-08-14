//Povray rendering of Chromosomes and Microtubules by Zsolt Bertalan

//Files with predefined colors and textures
#include "colors.inc"
//#include "glass.inc"
//#include "golds.inc"
//#include "metals.inc"
//#include "stones.inc"
//#include "woods.inc"
#include "shapes.inc"
#include "math.inc"


#fopen MyFile "angle.dat" read
#read(MyFile,i1, i2, i3)

camera { 
   orthographic
    angle 10
   location < i1 , i2 , i3 >
   look_at <0,0,0>
}



//Ambient light to "brighten up" darker pictures
global_settings { ambient_light White }

//Place a light--you can have more than one!
//light_source {
//	 <0,15,20>   //Change this if you want to put the light at a different point
//	 color White*2         //Multiplying by 2 doubles the brightness
//}
light_source {
	 <20,20,10>   //Change this if you want to put the light at a different point
	 color White*2         //Multiplying by 2 doubles the brightness
}
light_source {
	 <-20,20,-10>   //Change this if you want to put the light at a different point
	 color White*2         //Multiplying by 2 doubles the brightness
}
light_source {
	 <20,-20,10>   //Change this if you want to put the light at a different point
	 color White*2         //Multiplying by 2 doubles the brightness
}
light_source {
	 <-20,-20,-10>   //Change this if you want to put the light at a different point
	 color White*2         //Multiplying by 2 doubles the brightness
}

//Set a background color
background { color Black }




#fopen MyFile "file.dat" read

//CENP-ECHROMOSOMES
	#read(MyFile,n)
	#declare i=1;
	#while (i<=n)
		#declare i=i+1;
       		#read (MyFile,vectori,theta,theta1)
		#declare vector=<vectori.x,vectori.y,vectori.z>;
	        sphere {<0,0,0> .15  translate vector pigment {color BrightGold} }
		#declare theta=theta*360./6.28;
		#declare theta1=theta1*360./6.28;
		#declare theta1=0.0;

		object{ //Round_Cylinder(A,B,Radius,EdgeRadius,Merge)
		 Round_Cylinder(<0,-0.9,0>,<0,0.9,0>,0.1,0.80,1)
		 texture{ pigment{ color Green} } // end of texture
		 rotate<theta1,theta1,10+theta>
		 translate vector
		}

		object{
		 //Round_Cylinder(A,B,Radius,EdgeRadius,Merge)
		 Round_Cylinder(<0,-0.9,0>,<0,0.9,0>,0.1,0.80,1)
		 texture{ pigment{ color Green} } // end of texture
		 rotate<theta1,theta1,-10+theta>
		 translate vector
		}
	#end
//DYNEIN CHROMOSOMES
	#read(MyFile,n)
	#declare i=1;
	#while (i<=n)
		#declare i=i+1;
       		//#read (MyFile,vector,theta,theta1)
       		#read (MyFile,vectori,theta,theta1)
		#declare vector=<vectori.x,vectori.y,vectori.z>;
	        sphere {<0,0,0> .15  translate vector pigment {color BrightGold} }
		#declare theta=theta*360./6.28;
		#declare theta1=theta1*360./6.28;
		#declare theta1=0.0;

		object{ //Round_Cylinder(A,B,Radius,EdgeRadius,Merge)
		 Round_Cylinder(<0,-0.9,0>,<0,0.9,0>,0.1,0.80,1)
		 texture{ pigment{ color Green} } // end of texture
		 rotate<theta1,theta1,10+theta>
		 translate vector
		}

		object{
		 //Round_Cylinder(A,B,Radius,EdgeRadius,Merge)
		 Round_Cylinder(<0,-0.9,0>,<0,0.9,0>,0.1,0.80,1)
		 texture{ pigment{ color Green} } // end of texture
		 rotate<theta1,theta1,-10+theta>
		 translate vector
		}
	#end
//no MP CHROMOSOMES
	#read(MyFile,n)
	#declare i=1;
	#while (i<=n)
		#declare i=i+1;
       	//	#read (MyFile,vector,theta,theta1)
       		#read (MyFile,vectori,theta,theta1)
		#declare vector=<vectori.x,vectori.y,vectori.z>;
	        sphere {<0,0,0> .15  translate vector pigment {color BrightGold} }
		#declare theta=theta*360./6.28;
		#declare theta1=theta1*360./6.28;
		#declare theta1=0.0;

		object{ //Round_Cylinder(A,B,Radius,EdgeRadius,Merge)
		 Round_Cylinder(<0,-0.9,0>,<0,0.9,0>,0.1,0.80,1)
		 texture{ pigment{ color Green} } // end of texture
		 rotate<theta1,theta1,10+theta>
		 translate vector
		}

		object{
		 //Round_Cylinder(A,B,Radius,EdgeRadius,Merge)
		 Round_Cylinder(<0,-0.9,0>,<0,0.9,0>,0.1,0.80,1)
		 texture{ pigment{ color Green} } // end of texture
		 rotate<theta1,theta1,-10+theta>
		 translate vector
		}
	#end


#read (MyFile,n)
#declare i=1;
#while (i<=n)
  #declare i=i+1;
  #read (MyFile,vector1i,vector2i)
 #declare vector1=<vector1i.x,vector1i.y,vector1i.z>;
 #declare vector2=<vector2i.x,vector2i.y,vector2i.z>;
  cylinder{vector1, vector2, .071  texture{pigment{ color Red }}}
#end

#read (MyFile,n)
#declare i=1;
#while (i<=n)
  #declare i=i+1;
  #read (MyFile,vector1i,vector2i)
 #declare vector1=<vector1i.x,vector1i.y,vector1i.z>;
 #declare vector2=<vector2i.x,vector2i.y,vector2i.z>;
  cylinder{vector1, vector2, .071  texture{pigment{ color Orange }}}
#end
#read (MyFile,n)
#declare i=1;
#while (i<=n)
  #declare i=i+1;
  #read (MyFile,vector1i,vector2i)
 #declare vector1=<vector1i.x,vector1i.y,vector1i.z>;
 #declare vector2=<vector2i.x,vector2i.y,vector2i.z>;
  cylinder{vector1, vector2, .02  texture{pigment{ color Red }}}
#end
