//////// Chromosome subroutine to evolve it /////////
int chromosome::evolve(vector <mt> &MT,gsl_rng *r)
{

	double fX,fY,fZ,aa,bb,cc,tmp,rt,pefx,pullx;
	fX=fY=fZ=0.0;
	int ii,jj,kk,nn;
	vector<int> pef_list,crawl_list,pull_list;
	bool need_new_crawler;
	ii=0; jj=MT.size()-1;
	double rcl=sqrt((MT[ii].xb-x)*(MT[ii].xb-x)+ (MT[ii].yb-y)*(MT[ii].yb-y)+(MT[ii].zb-z)*(MT[ii].zb-z));
	double rcr=sqrt((MT[jj].xb-x)*(MT[jj].xb-x)+ (MT[jj].yb-y)*(MT[jj].yb-y)+(MT[jj].zb-z)*(MT[jj].zb-z));
	//NEED NEW CRAWLER OR NO?
	if(crawler_index>-1  ){
	//chromosome had a crawler
	int i=crawler_index;
	aa=MT[i].R*MT[i].R;
	bb=2.0*((MT[i].xt-MT[i].xb)*(MT[i].xb-x)+(MT[i].yt-MT[i].yb)*(MT[i].yb-y)+(MT[i].zt-MT[i].zb)*(MT[i].zb-z));
	cc=(MT[i].xb-x)*(MT[i].xb-x)+ (MT[i].yb-y)*(MT[i].yb-y)+(MT[i].zb-z)*(MT[i].zb-z);
//	cout << "X = " <<ind << " has crawler " << i <<"; discr="<<bb*bb-4.0*aa*(cc-lk*lk)  <<endl;
	 //is it still valid?
	 rt=lk;
	 if(bb*bb-4.0*aa*(cc-rt*rt) >0 &&
		 (MT[i].xt-MT[i].xb)*(x-MT[i].xb)>0 &&
		 (MT[i].yt-MT[i].yb)*(y-MT[i].yb)>0 &&
		 (MT[i].zt-MT[i].zb)*(z-MT[i].zb)>0 &&
		 sqrt(cc)<MT[i].R
	 ){
	  //yes
	  need_new_crawler=false;
//	  cout << "	re-assigning" <<"\033[1;31m OLD\033[0m crawler "  << crawler_index << "; motor="<<motor_protein<< endl;
	  crawler_index=i; crawl_timer=0.0;
	 }
	 else{
	  //no
	  need_new_crawler=true;
	  crawler_index=-1; crawl_timer=0.0;
//	  cout <<"	but needs a new one " <<endl;
	 }
	}
	else{
	 //had no crawler
	 if(central_plate || motor_protein < 0) need_new_crawler=false;
	 else need_new_crawler=true;
	}

	//2) build lists
	for(int i=0;i<MT.size();i++){
 	 aa=MT[i].R*MT[i].R;
	 bb=2.0*((MT[i].xt-MT[i].xb)*(MT[i].xb-x)+(MT[i].yt-MT[i].yb)*(MT[i].yb-y)+(MT[i].zt-MT[i].zb)*(MT[i].zb-z));
	 cc=(MT[i].xb-x)*(MT[i].xb-x)+ (MT[i].yb-y)*(MT[i].yb-y)+(MT[i].zb-z)*(MT[i].zb-z);
	 rt=(motor_protein ? lk : 3.0*lk);
	 if(need_new_crawler && bb*bb-4.0*aa*(cc-rt*rt) >0 &&
	  (MT[i].xt-MT[i].xb)*(x-MT[i].xb)>0 &&
	  (MT[i].yt-MT[i].yb)*(y-MT[i].yb)>0 &&
	  (MT[i].zt-MT[i].zb)*(z-MT[i].zb)>0 &&
	  sqrt(cc)<MT[i].R
	 ){
	  //needed new crawler and this MT was good
//	  if(motor_protein==1 && gsl_rng_uniform(r)<=MT[i].detyr_level)crawl_list.push_back(i);
//	  else if(motor_protein==0){
	   crawl_list.push_back(i);
//	  }
//	  cout << "X = " <<ind << " adding " << i << " to crawler; discr="<< bb*bb-4.0*aa*(cc-lk*lk)<<endl;
	 }//end crawl
	 else{
	  //didn't need new crawler or was not good
	  //a) build kfibre list
 	  if(
		sqrt((x-MT[i].xt)*(x-MT[i].xt)+ (y-MT[i].yt)*(y-MT[i].yt)+(z-MT[i].zt)*(z-MT[i].zt))<lk &&
		motor_protein!=0 &&
		MT[i].attached<0 &&
		free_kmts.size()>0 && 
		!(MT[i].linked) &&
		sqrt((x-MT[i].xb)*(x-MT[i].xb)+ (y-MT[i].yb)*(y-MT[i].yb)+(z-MT[i].zb)*(z-MT[i].zb))>0.2*MAJR
		){
		pull_list.push_back(i);
// 	 cout << "X = " <<ind << " MT_pull=" << i tab motor_protein << endl;
	  }
	 }
  	if(
		bb*bb-4.0*aa*(cc-lc*lc) >0 && 
		(MT[i].xt-MT[i].xb)*(x-MT[i].xb)>0 &&
		(MT[i].yt-MT[i].yb)*(y-MT[i].yb)>0 &&
		(MT[i].zt-MT[i].zb)*(z-MT[i].zb)>0 &&
		sqrt(cc)<MT[i].R 
	  ){
	   pef_list.push_back(i);
//	   cout << (MT[i].xt-MT[i].xb)*(x-MT[i].xb) tab (MT[i].yt-MT[i].yb)*(y-MT[i].yb) tab (MT[i].zt-MT[i].zb)*(z-MT[i].zb) tab ind << endl;
	  }//endPEF
	}//end MT list 
	
	//3) process lists & gather forces
	//3a) PEF
	pefx=0.0;
	if(pef_list.size()>1){
		int pef_ct=0;
//		cout << "################################"<<endl;
//		cout <<pef_list.size();
		while(pef_ct<35 && pef_list.size()>1){
			ii=(int)floor(gsl_rng_uniform(r)*pef_list.size());
			jj=pef_list[ii];
			tmp=FPEF/MT[jj].R;
			if(sqrt(x*x)<x_mtcurve){
			 fX+=FPEF*(MT[jj].xt-MT[jj].xb)/sqrt((MT[jj].xt-MT[jj].xb)*(MT[jj].xt-MT[jj].xb));
			 pefx+=FPEF*(MT[jj].xt-MT[jj].xb)/sqrt((MT[jj].xt-MT[jj].xb)*(MT[jj].xt-MT[jj].xb));
			}
			else{
			 fX+=(MT[jj].xt-MT[jj].xb)*tmp;
			 pefx+=(MT[jj].xt-MT[jj].xb)*tmp;
			 fY+=(MT[jj].yt-MT[jj].yb)*tmp;
			 fZ+=(MT[jj].zt-MT[jj].zb)*tmp;
			}
			pef_list.erase(pef_list.begin()+ii);
//			cout << "\t" << pef_ct tab fX <<endl;
			pef_ct++;
//			cout << "X = " <<ind << " getting PEF from " << jj << endl;
		}
		
	}
	//3b) crawler
	if(crawl_list.size() >= 1 && need_new_crawler ){
	 ii=(int)floor(gsl_rng_uniform(r)*crawl_list.size());
	 jj=crawl_list[ii];
	 crawler_index=jj;
 //	 cout << "X = " <<ind << " assigning new crawler " << jj <<endl;
	}
	if(motor_protein>-1){
	 if(crawler_index > -1){
//	  if(motor_protein==1){
//		tmp=FCEN*MT[crawler_index].detyr_level/MT[crawler_index].R;///MT[crawler_index].R;//
//	  }
//	  else if (motor_protein==0){
		tmp=1.0/MT[crawler_index].R*( FDYN + FCEN*MT[crawler_index].detyr_level );
//	  }
	  fX+=tmp*(MT[crawler_index].xt-MT[crawler_index].xb);
	  fY+=tmp*(MT[crawler_index].yt-MT[crawler_index].yb);
	  fZ+=tmp*(MT[crawler_index].zt-MT[crawler_index].zb);
//	  tmp=x*x/(MAJR*MAJR)+y*y/(MINR*MINR)+z*z/(MINR2*MINR2);
//	  cout << ind tab motor_protein tab fX tab fY tab fZ tab crawler_index tab need_new_crawler <<endl;
	 }
//	 else{
//	  if(central_plate){}
//	  else if(rcl > 10.0*R_AURORA_A && rcr > 10.0*R_AURORA_A && crawler_index<0){
//	   motor_protein=0;
//	   crawl_timer=0.0;
//	  }	
//	 }
	}
	//3c) KMT
	tmp=0;
	pullx=0.0;
	while(free_kmts.size()>0 && pull_list.size()>0 && tmp<500){
	 //choose an mt from list
	 ii=(int)floor(gsl_rng_uniform(r)*pull_list.size());
	 jj=pull_list[ii];
	 kk=(int)floor(gsl_rng_uniform(r)*free_kmts.size());
	 nn=free_kmts[kk];
	 tmp++;
	 if((MT[jj].xt<x && nn<nkmt_max/2) || (MT[jj].xt>x && nn>=nkmt_max/2)  ){
		 //attach to left X			attach to right X
		 kmt_index[nn]=jj;
		 MT[jj].attached=ind;
		 pull_list.erase(pull_list.begin()+ii);
		 free_kmts.erase(free_kmts.begin()+kk);
		 MT[jj].state=0;
//		 cout << " attaching MT " << jj << " to X " <<ind<< "; fkmt.size="<<free_kmts.size() << "; motprot="<<motor_protein <<endl;
	 }
	}
	for(int i=0;i<nkmt_max;i++){
	 ii=kmt_index[i];
	 bool pull_q;
	 if(ii>=0){
	     if(MT[ii].try_detach(r) || sqrt((x-MT[ii].xt)*(x-MT[ii].xt)+(y-MT[ii].yt)*(y-MT[ii].yt)+(z-MT[ii].zt)*(z-MT[ii].zt)) > 5.0*lk){
		     MT[ii].attached=-1;
		     MT[ii].stable=0;
		     MT[ii].f_tip=stresses[i]=0.0;
		     free_kmts.push_back(i);
		     kmt_index[i]=-1;
//		     cout << ind tab ii tab MT[ii].f_tip tab MT[ii].detyr_level <<endl;
	     }
	     else{
	     tmp=sqrt((MT[ii].xb-x)*(MT[ii].xb-x)+ (MT[ii].yb-y)*(MT[ii].yb-y)+(MT[ii].zb-z)*(MT[ii].zb-z));
	     if(tmp > MT[ii].R) {
		     pull_q=true;
		     MT[ii].wrong_kt=false;
	     }
	     else {
		     pull_q=false;
		     MT[ii].wrong_kt=true;
	     }
	     tmp=sqrt((x-MT[ii].xt)*(x-MT[ii].xt)+(y-MT[ii].yt)*(y-MT[ii].yt)+(z-MT[ii].zt)*(z-MT[ii].zt));
	     if(pull_q && tmp< 2.0){
		if(sqrt(x*x)<x_mtcurve){
	 	 fX+=-ks*(x-MT[ii].xt);
		 pullx+=-ks*(x-MT[ii].xt);
		}
		else{
	 	 fY+=-ks*(y-MT[ii].yt);
	 	 fZ+=-ks*(z-MT[ii].zt);
	 	 fX+=-ks*(x-MT[ii].xt);
		}
		MT[ii].f_tip=ks*tmp;
		stresses[i]=MT[ii].f_tip;
	     }
	     else{
		MT[ii].f_tip=stresses[i]=0.0;
	     }
	     
//	     cout << "X " << ind <<" pull from " << ii <<" f="<<pull_q tab tmp tab ks*(x-MT[ii].xt) tab fX <<endl;
	     }
	 }
	}
	//4) evolve
	double xtmp=x+dtp*fX;
	double ytmp=y+dtp*fY;
	double ztmp=z+dtp*fZ;
	crawl_timer++;
	tmp=xtmp*xtmp/(MAJR*MAJR)+ytmp*ytmp/(MINR*MINR)+ztmp*ztmp/(MINR2*MINR2);
	if(tmp<0.9){
	 x=xtmp; y=ytmp; z= ztmp;
	}
	
	//5) post process
	if(sqrt(x*x)<x_center && y*y/(MINR*MINR)+z*z/(MINR2*MINR2) < 0.8){
	 central_plate=true;
	 motor_protein=-1;
	 crawl_timer=0.0;
	}
	else{
	 central_plate=false;
	}

	if( (rcl < R_AURORA_A || rcr < R_AURORA_A))
	{
		for(int i=0;i<nkmt_max;i++){
		 ii=kmt_index[i];
		 if(ii>=0){
		     MT[ii].attached=-1;
		     MT[ii].stable=0;
		     MT[ii].f_tip=0.0;
		     free_kmts.push_back(i);
		     kmt_index[i]=-1;
		 }
		}
	}

	if(crawler_index>-1){
	 if( gsl_rng_uniform(r) < 0.1*(1.0-MT[crawler_index].detyr_level) ){
	  crawler_index=-1;
	  motor_protein=0;
	  crawl_timer=0;
	}}

	double lft=0.0, rgt=0.0;
	for(int i=0;i<nkmt_max/2;i++){
	 lft+=stresses[i];	
	 rgt+=stresses[i+nkmt_max/2];	
	}
	if(sqrt(lft*lft) >2.5 && sqrt(rgt*rgt)>2.5){
		for(int i=0;i<nkmt_max;i++){
		 if(kmt_index[i]>-1)MT[kmt_index[i]].stable=1;
		}
		bi_oriented=1;
	}
	else{
		bi_oriented=0;
		for(int i=0;i<nkmt_max;i++){
		 if(kmt_index[i]>-1)MT[kmt_index[i]].stable=0;
		}
	}

//	if(lft >0 || rgt >0 )cout << ind tab lft tab rgt <<endl;
//	if(sqrt(pefx*pefx)>0 || sqrt(pullx*pullx) >0) cout << x tab pefx tab pullx tab ind tab motor_protein <<endl;
//	if(crawl_timer> 5000){
//	 cout << " I (" << ind<<") got stuck! WTF" <<endl; abort();
//	}

}
/*
NOTE: RAY - SPHERE intersection:

two points on a line:
xb (base of mt) and xt (tip of MT) stored in MT[i].xb and MT[i].xt
centre of the sphere stored as chromosome.x,y,z, radius of chromatid = RC, of kinetochore rc

condtion for meeting: exist sol for line param

\sum_i [xb(i) + t(xt(i)-xb(i)) - x(i)]^2 = r*r

discriminant delta= b*b - 4ac
with

a = \sum_i [xt(i)-xb(i)]^2
b = \sum_i 2[xt(i)-xb(i)][xb(i)-x(i)]
c = \sum_i [xb(i)-x(i)]^2-r*r



*/
