//STRUCT for chromosome

typedef struct
{
	//GENERAL PARAMETERS
	int ind; //index-name
	double x; //position
	double y;
	double z;
	double R; //chromatin - size
	double rc; //kinetochore-size

	//force on left and right kinetochores
	double fxp;
	double fxm;
	double fyp;
	double fym;
	double fzp;
	double fzm;


	//K-PULL Parameters
	int nkmt_max; //maximum number of kMTs per "side"
	int n_attached;
	vector <int> kmt_index; //indices of kMTs
	vector <double> stresses;
	vector <int> free_kmts; //indices of kMTs
		
	//crawlers
	int crawler_index;
	int motor_protein; //dynein 0 CENPE 1 -1 none
	double crawl_timer;
	int stable;
	int bi_oriented;
	bool central_plate;
	
	void disconnect(int);
	void setup(int,gsl_rng *, double,vector<double>);
	int evolve(vector <mt> &MT,gsl_rng *r);

	void get_square(vector< vector <double> >&coords,double);

}chromosome;
//evolve subroutine
#include "X_evolve.h"


///dummy routine 
void chromosome::get_square(vector<vector <double> > &coords,double rm){
	int i=0;
	double ph,th;
	coords.resize(8);
	
	for(i=0;i<8;i++)coords[i].resize(3);
	th=0.25*PI;
	for(i=0;i<4;i++){
		ph=(1.25+i*0.5)*PI;
		coords[i][0]=x+rm*cos(ph)*sin(th);
		coords[i][1]=y+rm*sin(ph)*sin(th);
		coords[i][2]=z+rm*cos(th);
	}
	th=0.75*PI;
	for(i=0;i<4;i++){
		ph=(1.25+i*0.5)*PI;
		coords[i+4][0]=x+rm*cos(ph)*sin(th);
		coords[i+4][1]=y+rm*sin(ph)*sin(th);
		coords[i+4][2]=z+rm*cos(th);
	}
}

//setup a single chromosome
void chromosome::setup(int index , gsl_rng *r, double size,vector<double> ps)
{
	ind=index;
	x=ps[0];y=ps[1];z=ps[2];
	R=size;
	rc=lk;
	crawl_timer=0.0;
	crawler_index=-1;
	nkmt_max=2*kmt;
	n_attached=0;
	kmt_index.resize(nkmt_max);
	stresses.resize(nkmt_max);
	free_kmts.resize(0);
//	if(sqrt(x*x)<0.5*MAJR && sqrt(y*y)<0.5*MINR && sqrt(z*z)<0.5*MINR2) motor_protein=0;
//	if(sqrt(x*x)>0.5*MAJR && sqrt(y*y)>0.5*MINR && sqrt(z*z)>0.5*MINR2) motor_protein=0;
	motor_protein=0;
	for(int i=0;i<nkmt_max;i++) {
		kmt_index[i]=-1;
		free_kmts.push_back(i);
	}
	bi_oriented=0;

}

//decouple collapsed MTs from kinetochores
void chromosome::disconnect(int index)
{
	for(int i=0;i<nkmt_max;i++){
		if(kmt_index[i]==index){
			kmt_index[i]=-1;
			free_kmts.push_back(i);
	//		cout << "disconneted collapsed MT "<<index<< " from slot " << i <<endl;
			break;
		}
	}
}
