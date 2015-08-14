#define abs(t) sqrt(t*t)
#define rho(t,s) sqrt(t*t+s*s)
#define max(aa,bb) aa>bb ? aa : bb
#define min(aa,bb) aa>bb ? bb : aa

//TIME STEP will always be TAU, = 10^-5 seconds
double dt=0.01;//dt' = dt/\gamma
double dtp=0.0001;//dt' = dt/\gamma


double PI=M_PI;

double lc=1.0;//chromosome size in um
double ks=5.0; //kinetochore-chromatid attachmnt stiffness
double lk=0.3;//size of the kinetochore array (my estimate 30% of chromatid, "reach")
double lksq=lk*lk;
int kmt=25; //kinetochore slots

double FPEF=1.0;//pN kinesin13 walkers
double FDYN=-40.0;//pN dynein motor force
double FCEN=45.0;//pN dynein motor force

//double p_cat=5.4e-4; //per tau !! CONTROL
double p_cat=1.0*5.4e-4; //per tau !! foure the rte
double p_res=4.5e-4;
double v_res=2.0e-3; //per tau !!
double v_cat=12.0e-3;

//FROM AKIYOSHI 2010 WE'LL TAKE the EXPONENTS
double F_g=6.0;		//in pN
double F_s=-2.0;

double F_cat=-2.3;	//IN pN
double F_res=2.4;

double k3=1.1e-6;		//per hour 0.4
double k4=3.4e-4;		//per hour125 rescue!

double F3=3.8;		//detachment during assembly
double F4=-4.0;		//detachment during DISSass


double x_center;
double x_mtcurve;


#define p_aurora 0.4 //per second
#define A_aurora 2.1 //aurora exponent
double R_AURORA_A=0.1;//Aurora A radius it phosophorises CENP-E and strips Dynein, should definitely be smaller than lk

char black[]="0x000000",red[]="0xff0000",white[]="0xffffff",blue[]="0x0033CC",yellow[]="0xFFFF00";
char orange[]="0xFF6600";
char green[]="0x00CC00";
