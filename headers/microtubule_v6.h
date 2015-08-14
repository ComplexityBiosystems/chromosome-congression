//microtubule structs
typedef struct 
{	
	//name
	int ind;
	//tip and base coordinates
	double xt;
	double yt;
	double zt;
	double xb;
	double yb;
	double zb;

	//angle and extension
	double t;
	double p;
	double R;

	//tip-force
	double f_tip;

	//stable? 1 yes 0 no
	int stable;

	//state 1 grow 0 shrink
	int state;

	//detyrosination level
	double detyr_level;
	int eigen_time;

	//attached? -1 no, else chromosome index
	int attached;
	bool wrong_kt; //1 wrong/merotelic  0 correct syntelic
	bool linked;

	//parameters
	int setup(int name,gsl_rng *r,double basex,double basey,double basez, double rmax);
	void propagate(gsl_rng *r);
	void get_tip_coords(void);
	void get_angles(double Xx_center,double Xy_center,double Xz_center);
	int try_detach(gsl_rng *);
}mt;

int mt::try_detach(gsl_rng *r)
{
	double s,t;

	s=gsl_rng_uniform(r);
//		s=1;
/*
	if(stable && (!(wrong_kt))){
//		t=0.0001*p_cat*exp(0.2*s)/(s*s+1.0);
		t=0.0;
		if(state==0) t = k4*exp(f_tip/F4);
		else  t = k3*exp(f_tip/F3);
		t=1.0;
	}
	else {
		if(state==0) t = 0.01*k4*exp(f_tip/F4);
		else  t = 0.01*k3*exp(f_tip/F3);
	}
*/
	if(stable) t=0;
	else if (wrong_kt) t=k3;
	else{
		if(f_tip>2)t=0;
		else{
		  if(state==0) t =k4*exp(f_tip/F4);
		  else  t =k3*exp(f_tip/F3);
		}
	}
	if(s < t){
		return 1;
	}
	else{
		return 0;
	}
}



void mt::propagate(gsl_rng *r)
{
	double s=sqrt(f_tip*f_tip);
	if(linked){}
	else{
	if(state==0){
	 R-=v_cat*exp(10.0*s/F_s);
	 if(attached<0 && gsl_rng_uniform(r) < p_res*exp(s/F_res)) state=1;
	}
	else{
	 R+=v_res*exp(0.1*s/F_g);
	 if(gsl_rng_uniform(r) < p_cat*exp(s/F_cat)) state=0;
	}
	}
	eigen_time++;

}
void mt::get_tip_coords(void)
{
	xt=xb+R*cos(p)*sin(t);
	yt=yb+R*sin(p)*sin(t);
	zt=zb+R*cos(t);
}

void mt::get_angles(double Xx_center,double Xy_center,double Xz_center)
{
	//get new angle from chromosome center
	double dy=Xy_center-yb,dx=Xx_center-xb,dz=Xz_center-zb;
	double atg=atan(dy/dx);
	atg=sqrt(atg*atg);
//	cout << "resetting MT " << ind << " angle phi from " << p << " to ";
	if(dx >0 && dy >0) atg=atg;
	else if(dx <0 && dy >0) atg=PI-atg;
	else if(dx <0 && dy <0) atg=PI+atg;
	else if(dx >0 && dy <0) atg=2.0*PI-atg;
//	cout << p<< " angle theta from " << t << " to ";
	p=atg;
	atg=atan(sqrt(dy*dy+dx*dx)/dz);
	atg=sqrt(atg*atg);
	if(dz >0 ) atg=atg;
	else if(dz <0 ) atg=PI-atg;
	t=atg;
}
int mt::setup(int name, gsl_rng *r,double basex,double basey,double basez, double rmax)
{	
	int l;
	l=attached;
	ind=name;
	p=2.0*PI*gsl_rng_uniform(r);
	t=PI*gsl_rng_uniform(r);
	xb=basex;
	yb=basey;
	zb=basez;
	R=rmax*gsl_rng_uniform(r) ;
	stable=0;
	state=1;
	attached=-1;
	f_tip=0.0;
	detyr_level=0.0;
	wrong_kt=false;
	eigen_time=0;
	linked=false;
	/*
	if(xb<0 && (p < 0.3*M_PI || p >1.7*M_PI) && (t>0.2*M_PI && t<0.8*M_PI )){
		detyr_level=1.0;
	}
	else if(xb>0 && (p > 0.7*M_PI && p <1.3*M_PI)  && (t>0.2*M_PI && t<0.8*M_PI ) ){
		detyr_level=1.0;
	}
	else detyr_level=0.2*gsl_rng_uniform(r);
	*/
	return l;
}
