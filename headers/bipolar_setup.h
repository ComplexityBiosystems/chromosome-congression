//setup a bioplar spindle, with major axes centered on the x axis in a rhs orientation 
//input:
//n:	 number of MTs
//xpos:	position on x-axis of a pole
//l0: pole separation
//r: random number generator
void bipolar_spindle::setup(int n, double xpos, double l0, gsl_rng *r)
{
	n_mt=n;
	MT.resize(2*n);
	init_l0=l0;
	
//ellipsoid cortex
	major=l0;
	minor=0.9*l0;
	minor2=0.5*l0;

//thickness of central plate
	x_center=0.2*l0;


//pole coordinates
	xL=-0.5*l0;
	xR=0.5*l0;
	yR=0.0;
	yL=0.0;
	zR=0.0;
	zL=0.0;

	double x_tmp,y_tmp,z_tmp;

//setup MTs

	for(int i=0; i<n;i++)MT[i].setup(i,r,xL,yL,zL,minor*gsl_rng_uniform(r));
	for(int i=n; i<2*n;i++)MT[i].setup(i,r,xR,yR,zR,minor*gsl_rng_uniform(r));

//how many MTs form stable scaffold
	int n_link=(int)floor(0.11*n);

//setup scaffold, link MTs from opposing poles and set counters accordingly
	for(int i=0;i<n_link;i++){
		MT[i].linked=true;
		MT[i+n].linked=true;
		MT[i].state=1;
		MT[i+n].state=1;

		x_tmp=x_center*(-1.0+2.0*gsl_rng_uniform(r));
		y_tmp=0.7*minor*(-1.0+2.0*gsl_rng_uniform(r));
		z_tmp=0.7*minor2*(-1.0+2.0*gsl_rng_uniform(r));

//		cout << "link " << i << " at " << x_tmp tab y_tmp tab z_tmp<<endl;

		MT[i].xt=MT[i+n].xt=x_tmp;
		MT[i].yt=MT[i+n].yt=y_tmp;
		MT[i].zt=MT[i+n].zt=z_tmp;
		MT[i].detyr_level=MT[i+n].detyr_level=0.6;

		double dy=y_tmp-yL,dx=x_tmp-xL,dz=z_tmp-zL;
		double atg=atan(dy/dx);
		atg=sqrt(atg*atg);
		if(dx >0 && dy >0) atg=atg;
		else if(dx <0 && dy >0) atg=PI-atg;
		else if(dx <0 && dy <0) atg=PI+atg;
		else if(dx >0 && dy <0) atg=2.0*PI-atg;
		MT[i].p=atg;
		atg=atan(sqrt(dy*dy+dx*dx)/dz);
		atg=sqrt(atg*atg);
		if(dz >0 ) atg=atg;
		else if(dz <0 ) atg=PI-atg;
		MT[i].t=atg;
		MT[i].R=sqrt(dx*dx+dy*dy+dz*dz);

		dy=y_tmp-yR,dx=x_tmp-xR,dz=z_tmp-zR;
		atg=atan(dy/dx);
		atg=sqrt(atg*atg);
		if(dx >0 && dy >0) atg=atg;
		else if(dx <0 && dy >0) atg=PI-atg;
		else if(dx <0 && dy <0) atg=PI+atg;
		else if(dx >0 && dy <0) atg=2.0*PI-atg;
		MT[i+n].p=atg;
		atg=atan(sqrt(dy*dy+dx*dx)/dz);
		atg=sqrt(atg*atg);
		if(dz >0 ) atg=atg;
		else if(dz <0 ) atg=PI-atg;
		MT[i+n].t=atg;
		MT[i+n].R=sqrt(dx*dx+dy*dy+dz*dz);

	}
	
}
