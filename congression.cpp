using namespace std;
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <cmath>
#include <vector>
#include <algorithm>
#include <unistd.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_randist.h>
#define tab << "\t" <<
#define tb << " " <<

double MAJR=0.0;
double MINR=0.0;
double MINR2=0.0;
#include "headers/constants.h"
#include "headers/microtubule_v6.h"
#include "headers/chromosome_v7.h"
#include "headers/spindle_v7.h"



int main (int argc, char **argv)
{
///////////////SEED RANDOM///////////
	gsl_rng * r = gsl_rng_alloc(gsl_rng_mt19937);
	unsigned long int Seed = floor(45217.6*getpid()/33.0);
	gsl_rng_set(r,Seed);


/////////////SETUP CONSTANTS & OPEN OUTPUT FILES//////////////
	char fname[200];		//dummy char array
	
	int run_no=1;			//ID number of the run
	
	sscanf(argv[1],"%d",&run_no);	// scan ID from first arg

	double t=0.0;
////number of chromosomes nx, number of MTs nm///////////////
	int nx=46,nm=9200;

	sscanf(argv[2],"%d",&nm);	//scan nm from second input arg

/////////////////////////////////open files//////////////////
	sprintf(fname,"final_xpos_N%d_pcat%1.4lf_v%d.dat",nm,1000.0*p_cat,run_no);
	FILE *oput=fopen(fname,"a"),*oput2;
	sprintf(fname,"final_MTdist%d_pcat%1.4lf_v%d.dat",nm,1000.0*p_cat,run_no);

////////////////////////setup bipolar spindle////////////////
	bipolar_spindle BP;
	BP.setup(nm,4,10,r);
	MAJR=BP.major; MINR=BP.minor; MINR2=BP.minor2;
	vector<chromosome> xsome;
	xsome.resize(nx);

	vector<int> MT_hist;
	MT_hist.resize((int)floor(MAJR*20.0));

///////////////////Arrange chromosomes randomly in NE////////
	for(int i=0;i<nx;i++){
		vector<double>posx(3);
		double setr=MAJR;
		do{
			posx[0]=setr*(-1.0+2.0*gsl_rng_uniform(r));
			posx[1]=setr*(-1.0+2.0*gsl_rng_uniform(r));
			posx[2]=setr*(-1.0+2.0*gsl_rng_uniform(r));
			
		}while(posx[0]*posx[0]/(0.85*MAJR*MAJR)+posx[1]*posx[1]/(0.6*MINR*MINR)+posx[2]*posx[2]/(0.6*MINR2*MINR2)>0.9 );
		xsome[i].setup(i,r,lc,posx);
	}

	int ct=1,t_print=100;		 ///print helpers

///////////////////////MAIN LOOP//////////////////////////////////
	int sac;
	for(int i=0;i<100000;i++){
		//propagate MTs
	 BP.propagate_mts(r);
	 sac=0;//reset sac counter
	 for(int ii=0;ii<nx;ii++){//for all chromosomes
		xsome[ii].evolve(BP.MT,r);//propagate
		//check SAC in two ways. uncomment only ONE of the two following lines
//		if(xsome[ii].x*xsome[ii].x < 0.9*x_center*x_center) sac++;	//sac counter advances due to spatial criterion
		sac+=xsome[ii].bi_oriented;					//sac advances due to chromosome biorientation
	 }
	 if(i%t_print==0){//print every t_print
		fprintf(oput,"%lf	%d\n",i*dt,sac);
//		 for(int ii=0;ii<nx;ii++){
//			fprintf(oput,"%d	%1.2lf	%d	%lf	%d\n",xsome[ii].ind,xsome[ii].x,xsome[ii].bi_oriented,xsome[ii].crawl_timer,xsome[ii].free_kmts.size());
//	 	}
	 }
	 if(sac==nx){	//check if SAC reached ... when all chromosomes contribute to sac
		fprintf(oput,"%lf	%d\n",i*dt,sac);
	  	BP.print_pov(xsome,ct); ct++;
		return 1;
	 }
	///MT lenght distribution output
	 if(i%t_print==1){
	  int sz;
	  for(int k=0;k<2*BP.n_mt;k++){
	   if(!(BP.MT[k].linked)){
		  sz=(int)floor(10.0*BP.MT[k].R);
		  MT_hist[sz]++;
	   }
	  }
	  oput2=fopen(fname,"w");
	  for(int k=0;k<MT_hist.size();k++){
		fprintf(oput2,"%1.2lf	%d\n",0.1*k,MT_hist[k]);
	  }
	  fclose(oput2);
//	  cout << i*dt tab sac<<endl;
	  //output in povray format
//	  BP.print_pov(xsome,ct); ct++;
	 }
	}
	fclose(oput);


//main end
}


