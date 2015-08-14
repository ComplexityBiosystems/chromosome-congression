///struct for bipolar spindle
typedef struct
{
	//left and right pole coordinates
	double xL;
	double xR;
	double yL;
	double yR;
	double zL;
	double zR;

	double focal;
	double major;
	double minor;
	double minor2;

	double init_l0;

	int n_mt;	

	vector< vector<int> > detached_x;

	vector<mt> MT;
	void setup(int n, double xpos, double l0, gsl_rng *r);
	void propagate_mts(gsl_rng *r);
	void print_x(vector<chromosome> XXX,int c);
	void print_pov(vector<chromosome> XXX,int c);
	void check_collapsed(vector<chromosome> &XXX);

}bipolar_spindle;



void bipolar_spindle::check_collapsed(vector<chromosome> &XXX)
{
	for(int o=0;o<detached_x.size();o++){ 
		int mm=detached_x[o][0];
		int nn=detached_x[o][1];
		XXX[mm].disconnect(nn);
	}
	detached_x.resize(0);
}

#include "bipolar_setup.h"
#include "bipolar_print.h"
#include "bipolar_mts.h"
#include "bipolar_pov.h"
