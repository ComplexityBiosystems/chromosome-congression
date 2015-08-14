//print output into gnuplot format

void bipolar_spindle::print_x(vector<chromosome> XXX,int c)
{
FILE *fil;
//float l=(float)L_cutoff+1;
double XT,YT,ZT;
int j,jj;
char filename[100],PATH[]="./";
vector<vector<double> > eck;

	sprintf(filename,"%sraw/xs%d.dat",PATH,c);
	fil=fopen(filename,"w");

	vector<int> crwls;


	for(int i=0;i<XXX.size();i++){
		if(XXX[i].crawler_index>-1)crwls.push_back(XXX[i].crawler_index);


		XXX[i].get_square(eck,lk);
		j=0;
		jj=1;	
 		fprintf(fil,"%lf        %lf	%lf	%lf        %lf    %lf	%s\n", 
				eck[j][0],eck[j][1],eck[j][2],eck[jj][0]-eck[j][0],eck[jj][1]-eck[j][1],eck[jj][2]-eck[j][2],green);
		jj=3;	
 		fprintf(fil,"%lf        %lf	%lf	%lf        %lf    %lf	%s\n", 
				eck[j][0],eck[j][1],eck[j][2],eck[jj][0]-eck[j][0],eck[jj][1]-eck[j][1],eck[jj][2]-eck[j][2],green);
		jj=4;	
 		fprintf(fil,"%lf        %lf	%lf	%lf        %lf    %lf	%s\n", 
				eck[j][0],eck[j][1],eck[j][2],eck[jj][0]-eck[j][0],eck[jj][1]-eck[j][1],eck[jj][2]-eck[j][2],green);
		j=2;
		jj=1;	
 		fprintf(fil,"%lf        %lf	%lf	%lf        %lf    %lf	%s\n", 
				eck[j][0],eck[j][1],eck[j][2],eck[jj][0]-eck[j][0],eck[jj][1]-eck[j][1],eck[jj][2]-eck[j][2],green);
		jj=3;	
 		fprintf(fil,"%lf        %lf	%lf	%lf        %lf    %lf	%s\n", 
				eck[j][0],eck[j][1],eck[j][2],eck[jj][0]-eck[j][0],eck[jj][1]-eck[j][1],eck[jj][2]-eck[j][2],green);
		jj=6;	
 		fprintf(fil,"%lf        %lf	%lf	%lf        %lf    %lf	%s\n", 
				eck[j][0],eck[j][1],eck[j][2],eck[jj][0]-eck[j][0],eck[jj][1]-eck[j][1],eck[jj][2]-eck[j][2],green);
		j=5;
		jj=1;	
 		fprintf(fil,"%lf        %lf	%lf	%lf        %lf    %lf	%s\n", 
				eck[j][0],eck[j][1],eck[j][2],eck[jj][0]-eck[j][0],eck[jj][1]-eck[j][1],eck[jj][2]-eck[j][2],green);
		jj=4;	
 		fprintf(fil,"%lf        %lf	%lf	%lf        %lf    %lf	%s\n", 
				eck[j][0],eck[j][1],eck[j][2],eck[jj][0]-eck[j][0],eck[jj][1]-eck[j][1],eck[jj][2]-eck[j][2],green);
		jj=6;	
 		fprintf(fil,"%lf        %lf	%lf	%lf        %lf    %lf	%s\n", 
				eck[j][0],eck[j][1],eck[j][2],eck[jj][0]-eck[j][0],eck[jj][1]-eck[j][1],eck[jj][2]-eck[j][2],green);
		j=7;
		jj=3;	
 		fprintf(fil,"%lf        %lf	%lf	%lf        %lf    %lf	%s\n", 
				eck[j][0],eck[j][1],eck[j][2],eck[jj][0]-eck[j][0],eck[jj][1]-eck[j][1],eck[jj][2]-eck[j][2],green);
		jj=4;	
 		fprintf(fil,"%lf        %lf	%lf	%lf        %lf    %lf	%s\n", 
				eck[j][0],eck[j][1],eck[j][2],eck[jj][0]-eck[j][0],eck[jj][1]-eck[j][1],eck[jj][2]-eck[j][2],green);
		jj=6;	
 		fprintf(fil,"%lf        %lf	%lf	%lf        %lf    %lf	%s\n", 
				eck[j][0],eck[j][1],eck[j][2],eck[jj][0]-eck[j][0],eck[jj][1]-eck[j][1],eck[jj][2]-eck[j][2],green);
	XXX[i].get_square(eck,lc);
		j=0;
		jj=1;	
 		fprintf(fil,"%lf        %lf	%lf	%lf        %lf    %lf	%s\n", 
				eck[j][0],eck[j][1],eck[j][2],eck[jj][0]-eck[j][0],eck[jj][1]-eck[j][1],eck[jj][2]-eck[j][2],green);
		jj=3;	
 		fprintf(fil,"%lf        %lf	%lf	%lf        %lf    %lf	%s\n", 
				eck[j][0],eck[j][1],eck[j][2],eck[jj][0]-eck[j][0],eck[jj][1]-eck[j][1],eck[jj][2]-eck[j][2],green);
		jj=4;	
 		fprintf(fil,"%lf        %lf	%lf	%lf        %lf    %lf	%s\n", 
				eck[j][0],eck[j][1],eck[j][2],eck[jj][0]-eck[j][0],eck[jj][1]-eck[j][1],eck[jj][2]-eck[j][2],green);
		j=2;
		jj=1;	
 		fprintf(fil,"%lf        %lf	%lf	%lf        %lf    %lf	%s\n", 
				eck[j][0],eck[j][1],eck[j][2],eck[jj][0]-eck[j][0],eck[jj][1]-eck[j][1],eck[jj][2]-eck[j][2],green);
		jj=3;	
 		fprintf(fil,"%lf        %lf	%lf	%lf        %lf    %lf	%s\n", 
				eck[j][0],eck[j][1],eck[j][2],eck[jj][0]-eck[j][0],eck[jj][1]-eck[j][1],eck[jj][2]-eck[j][2],green);
		jj=6;	
 		fprintf(fil,"%lf        %lf	%lf	%lf        %lf    %lf	%s\n", 
				eck[j][0],eck[j][1],eck[j][2],eck[jj][0]-eck[j][0],eck[jj][1]-eck[j][1],eck[jj][2]-eck[j][2],green);
		j=5;
		jj=1;	
 		fprintf(fil,"%lf        %lf	%lf	%lf        %lf    %lf	%s\n", 
				eck[j][0],eck[j][1],eck[j][2],eck[jj][0]-eck[j][0],eck[jj][1]-eck[j][1],eck[jj][2]-eck[j][2],green);
		jj=4;	
 		fprintf(fil,"%lf        %lf	%lf	%lf        %lf    %lf	%s\n", 
				eck[j][0],eck[j][1],eck[j][2],eck[jj][0]-eck[j][0],eck[jj][1]-eck[j][1],eck[jj][2]-eck[j][2],green);
		jj=6;	
 		fprintf(fil,"%lf        %lf	%lf	%lf        %lf    %lf	%s\n", 
				eck[j][0],eck[j][1],eck[j][2],eck[jj][0]-eck[j][0],eck[jj][1]-eck[j][1],eck[jj][2]-eck[j][2],green);
		j=7;
		jj=3;	
 		fprintf(fil,"%lf        %lf	%lf	%lf        %lf    %lf	%s\n", 
				eck[j][0],eck[j][1],eck[j][2],eck[jj][0]-eck[j][0],eck[jj][1]-eck[j][1],eck[jj][2]-eck[j][2],green);
		jj=4;	
 		fprintf(fil,"%lf        %lf	%lf	%lf        %lf    %lf	%s\n", 
				eck[j][0],eck[j][1],eck[j][2],eck[jj][0]-eck[j][0],eck[jj][1]-eck[j][1],eck[jj][2]-eck[j][2],green);
		jj=6;	
 		fprintf(fil,"%lf        %lf	%lf	%lf        %lf    %lf	%s\n", 
				eck[j][0],eck[j][1],eck[j][2],eck[jj][0]-eck[j][0],eck[jj][1]-eck[j][1],eck[jj][2]-eck[j][2],green);

//		if(XXX[i].x < xL || XXX[i].x > xR){
//		for(int m=0;m<XXX[i].push_list.size();m++){
//			jj=XXX[i].push_list[m];
//		 fprintf(fil,"%lf        %lf	%lf	%lf     %lf     %lf     %s\n",
//						MT[jj].xb,MT[jj].yb,MT[jj].zb,MT[jj].xt-MT[jj].xb,MT[jj].yt-MT[jj].yb,MT[jj].zt-MT[jj].zb,red);
//
//		}
//		}

	}




	fclose(fil);
	sprintf(filename,"%sraw/bs%d.dat",PATH,c);
	fil=fopen(filename,"w");
	sprintf(filename,"%sraw/obs%d.dat",PATH,c);
	FILE *fil2=fopen(filename,"w");
	
	sort(crwls.begin(),crwls.end());

	for(int i=0;i<2*n_mt;i++){
//		MT[i].get_tip_coords();
		XT=MT[i].xb;
		YT=MT[i].yb;
		ZT=MT[i].zb;
//		if(MT[i].attached>=0){
//		if(MT[i].detyr_level >0.3){

		if( binary_search(crwls.begin(),crwls.end(),i) ){
				
		 fprintf(fil,"%lf        %lf	%lf	%lf     %lf     %lf     %s\n",
						XT,YT,ZT,MT[i].xt-XT,MT[i].yt-YT,MT[i].zt-ZT,orange);
				
		}

		if(MT[i].attached >-1){
		 fprintf(fil,"%lf        %lf	%lf	%lf     %lf     %lf     %s\n",
						XT,YT,ZT,MT[i].xt-XT,MT[i].yt-YT,MT[i].zt-ZT,red);
		}
		else if(i%10==0){
		 fprintf(fil,"%lf        %lf	%lf	%lf     %lf     %lf     %s\n",
					XT,YT,ZT,MT[i].xt-XT,MT[i].yt-YT,MT[i].zt-ZT,red);
		}
		if(MT[i].linked){
		 fprintf(fil2,"%lf        %lf	%lf	%lf     %lf     %lf     %s\n",
						XT,YT,ZT,MT[i].xt-XT,MT[i].yt-YT,MT[i].zt-ZT,blue);
		}

		if(MT[i].detyr_level >0.9){
		 fprintf(fil2,"%lf        %lf	%lf	%lf     %lf     %lf     %s\n",
						XT,YT,ZT,MT[i].xt-XT,MT[i].yt-YT,MT[i].zt-ZT,black);
//		 abort();
		}
		else{
		 fprintf(fil2,"%lf        %lf	%lf	%lf     %lf     %lf     %s\n",
						XT,YT,ZT,MT[i].xt-XT,MT[i].yt-YT,MT[i].zt-ZT,green);
		}
 
	}
	fclose(fil);
	fclose(fil2);
	fil=popen("gnuplot","w");
	if(fil!=0){
		fprintf(fil,"set terminal png enhanced size 1200,400; set output 'raw/slice%d.png';",c);
		fprintf(fil,"set multiplot layout 1,3\n");
		fprintf(fil,"set xrange [%f: %f]; set yrange [%f: %f];",-major-1.0,major+1,-major-1.0,major+1.0);
		fprintf(fil,"set zrange [%f: %f];" ,-minor2-1.0,minor2+1.0);
		fprintf(fil,"set view 0,0; set view equal xyz;");
		fprintf(fil,"splot 'raw/bs%d.dat' using 1:2:3:4:5:6:7 with vectors nohead lw 2 lc rgb variable, 'raw/xs%d.dat' using 1:2:3:4:5:6:7 with vectors nohead lw 2 lc rgb variable\n",c,c);
		fprintf(fil,"set xrange [%f: %f]; set yrange [%f: %f];",-major-1.0,major+1,-major-1.0,major+1.0);
		fprintf(fil,"set zrange [%f: %f];" ,-minor2-1.0,minor2+1.0);
		fprintf(fil,"set view 90,0; set view equal xyz;");
		fprintf(fil,"splot 'raw/bs%d.dat' using 1:2:3:4:5:6:7 with vectors nohead lw 2 lc rgb variable, 'raw/xs%d.dat' using 1:2:3:4:5:6:7 with vectors nohead lw 2 lc rgb variable\n",c,c);
		fprintf(fil,"set xrange [%f: %f]; set yrange [%f: %f];",-major-1.0,major+1,-major-1.0,major+1.0);
		fprintf(fil,"set zrange [%f: %f];" ,-minor2-1.0,minor2+1.0);
		fprintf(fil,"set view 90,90; set view equal xyz;");
		fprintf(fil,"splot 'raw/bs%d.dat' using 1:2:3:4:5:6:7 with vectors nohead lw 2 lc rgb variable, 'raw/xs%d.dat' using 1:2:3:4:5:6:7 with vectors nohead lw 2 lc rgb variable\n",c,c);
		fprintf(fil,"unset multiplot\n");
	}
	fflush(fil);
	pclose(fil);

}

