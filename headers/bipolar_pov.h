//print output into a pov file

void bipolar_spindle::print_pov(vector<chromosome> XXX,int c)
{
FILE *fil;
int nx=XXX.size();
double XT,YT,dx,dy,dz,atg,ZT,tet;
char fname[100];
		
	if(c<10)sprintf(fname,"pov_out/BPX00%d.dat",c);
	else if(c<100)sprintf(fname,"pov_out/BPX0%d.dat",c);
	else sprintf(fname,"pov_out/BPX%d.dat",c);

	fil=fopen(fname,"w");
//	fprintf(fil,"%d,\n",nx);
	vector<int> dync,cenc,noc;


	for(int i=0;i<nx;i++){
		if(XXX[i].motor_protein==1) cenc.push_back(i);
		else if(XXX[i].motor_protein==-1) noc.push_back(i);
		else if(XXX[i].motor_protein==0) dync.push_back(i);
	}

	fprintf(fil,"%d,\n",cenc.size());
	for(int j=0;j<cenc.size();j++){
		int i=cenc[j];
		if(XXX[i].x<0) {XT=MT.front().xb;YT=MT.front().yb;ZT=MT.front().zb;}
		else {XT=MT.back().xb; YT=MT.back().yb;ZT=MT.back().zb;}
		dx=XXX[i].x-XT;
		dy=XXX[i].y-YT;
		dz=XXX[i].z-ZT;
		atg=atan(dy/dx); atg=sqrt(atg*atg);
		if(dx >0 && dy >0) atg=atg;
	        else if(dx <0 && dy >0) atg=PI-atg;
	        else if(dx <0 && dy <0) atg=PI+atg;
		else if(dx >0 && dy <0) atg=2.0*PI-atg;
		tet=atan(sqrt(dy*dy+dx*dx)/dz);
		tet=sqrt(atg*atg);
		if(dz >0 ) tet=tet;
		else if(dz <0 ) tet=PI-tet;
		fprintf(fil,"<%lf , %lf , %lf> , %lf , %lf ,\n",XXX[i].x,XXX[i].y,XXX[i].z,atg+PI,tet);
//		fprintf(fil,"<%lf , %lf , %lf> , %lf , %lf ,\n",XXX[i].x,XXX[i].y,0.0,atg+PI,tet);
	}
	fprintf(fil,"%d,\n",dync.size());
	for(int j=0;j<dync.size();j++){
		int i=dync[j];
		if(XXX[i].x<0) {XT=MT.front().xb;YT=MT.front().yb;ZT=MT.front().zb;}
		else {XT=MT.back().xb; YT=MT.back().yb;ZT=MT.back().zb;}
		dx=XXX[i].x-XT;
		dy=XXX[i].y-YT;
		dz=XXX[i].z-ZT;
		atg=atan(dy/dx); atg=sqrt(atg*atg);
		if(dx >0 && dy >0) atg=atg;
	        else if(dx <0 && dy >0) atg=PI-atg;
	        else if(dx <0 && dy <0) atg=PI+atg;
		else if(dx >0 && dy <0) atg=2.0*PI-atg;
		tet=atan(sqrt(dy*dy+dx*dx)/dz);
		tet=sqrt(atg*atg);
		if(dz >0 ) tet=tet;
		else if(dz <0 ) tet=PI-tet;
		fprintf(fil,"<%lf , %lf , %lf> , %lf , %lf ,\n",XXX[i].x,XXX[i].y,XXX[i].z,atg+PI,tet);
//		fprintf(fil,"<%lf , %lf , %lf> , %lf , %lf ,\n",XXX[i].x,XXX[i].y,0.0,atg+PI,tet);
	}
	fprintf(fil,"%d,\n",noc.size());
	for(int j=0;j<noc.size();j++){
		int i=noc[j];
		if(XXX[i].x<0) {XT=MT.front().xb;YT=MT.front().yb;ZT=MT.front().zb;}
		else {XT=MT.back().xb; YT=MT.back().yb;ZT=MT.back().zb;}
		dx=XXX[i].x-XT;
		dy=XXX[i].y-YT;
		dz=XXX[i].z-ZT;
		atg=atan(dy/dx); atg=sqrt(atg*atg);
		if(dx >0 && dy >0) atg=atg;
	        else if(dx <0 && dy >0) atg=PI-atg;
	        else if(dx <0 && dy <0) atg=PI+atg;
		else if(dx >0 && dy <0) atg=2.0*PI-atg;
		tet=atan(sqrt(dy*dy+dx*dx)/dz);
		tet=sqrt(atg*atg);
		if(dz >0 ) tet=tet;
		else if(dz <0 ) tet=PI-tet;
		fprintf(fil,"<%lf , %lf , %lf> , %lf , %lf ,\n",XXX[i].x,XXX[i].y,XXX[i].z,atg+PI,tet);
//		fprintf(fil,"<%lf , %lf , %lf> , %lf , %lf ,\n",XXX[i].x,XXX[i].y,0.0,atg+PI,tet);
	}



	vector<vector <double> > attmts;
	vector<vector <double> > cramts;
	vector<vector <double> > pefmts;
	vector<double> mtc(6);
	for(int i=0;i<2*n_mt;i+=1){
	  if(MT[i].attached>=0){
		 mtc[0]=MT[i].xb;
		 mtc[1]=MT[i].yb;
		 mtc[2]=MT[i].zb;
		 mtc[3]=MT[i].xt;
		 mtc[4]=MT[i].yt;
		 mtc[5]=MT[i].zt;
		 attmts.push_back(mtc);
	  }

//	  if(!MT[i].linked){
	  int aa=i;
	  mtc[0]=MT[aa].xb;
	  mtc[1]=MT[aa].yb;
	  mtc[2]=MT[aa].zb;
	  mtc[3]=MT[aa].xt;
	  mtc[4]=MT[aa].yt;
	  mtc[5]=MT[aa].zt;
	  pefmts.push_back(mtc);//}
	}
	for(int qq=0;qq<XXX.size();qq++){
	  if(XXX[qq].crawler_index>=0){
		 int aa=XXX[qq].crawler_index;
		 mtc[0]=MT[aa].xb;
		 mtc[1]=MT[aa].yb;
		 mtc[2]=MT[aa].zb;
		 mtc[3]=MT[aa].xt;
		 mtc[4]=MT[aa].yt;
		 mtc[5]=MT[aa].zt;
		 cramts.push_back(mtc);

	  }
	}
		 
	fprintf(fil,"%d,\n",attmts.size());
	for(int i=0;i<attmts.size();i++){
		 fprintf(fil,"<%lf , %lf , %lf>, <%lf , %lf , %lf>,\n", 
				 attmts[i][0],attmts[i][1],attmts[i][2],attmts[i][3],attmts[i][4],attmts[i][5]);
	}
	fprintf(fil,"%d,\n",cramts.size());
	for(int i=0;i<cramts.size();i++){
		 fprintf(fil,"<%lf , %lf , %lf>, <%lf , %lf , %lf>,\n", 
				 cramts[i][0],cramts[i][1],cramts[i][2],cramts[i][3],cramts[i][4],cramts[i][5]);
	}
	fprintf(fil,"%d,\n",pefmts.size());
	for(int i=0;i<pefmts.size();i++){
		 fprintf(fil,"<%lf , %lf , %lf>, <%lf , %lf , %lf>,\n", 
				 pefmts[i][0],pefmts[i][1],pefmts[i][2],pefmts[i][3],pefmts[i][4],pefmts[i][5]);
	}

	fclose(fil);

	dync.clear();
	noc.clear();
	cenc.clear();

}

