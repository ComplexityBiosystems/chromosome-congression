//subroutine to propagate MTs of the bipolar spindle
void bipolar_spindle::propagate_mts(gsl_rng *r)
{
///local variable setup
	int det_query; //detached query
	vector<int> link_pair(2); //link pair temporal 
	int i,j;//indices

	double mj=1.0/(major*major); //inverse axis
	double mn=1.0/(minor*minor);
	double mn2=1.0/(minor2*minor2);

	for(i=0;i<2*n_mt;i++){ //for each MT
		MT[i].propagate(r); //propagate
		MT[i].get_tip_coords(); //update tip coordinate info from polar to cartesian

		if(MT[i].eigen_time> 1000 ){//if eigentime 
			MT[i].detyr_level+=0.1; //increase detyr level
			MT[i].eigen_time =0;	//resert eigentime
			if(MT[i].detyr_level>1.0){//upper bound on detyr level
				MT[i].detyr_level=1.0;
//				cout << i tab "detyrosintaed completely"<<endl;
			}
		}

		if(MT[i].R < 0){// if MT collapsed,update detached info on chromosomes
			if(i > n_mt)det_query=MT[i].setup(i,r,xR,yR,zR,0.01);
			else det_query=MT[i].setup(i,r,xL,yL,zR,0.01);
			if(det_query>=0){
				link_pair[0]=det_query;
				link_pair[1]=i;
				detached_x.push_back(link_pair);
			}
			MT[i].eigen_time=0.0;
			MT[i].detyr_level=0.0;
		}
		else if( //set to depoly (state=0) when cortex is reached
			((MT[i].xt)*(MT[i].xt)*mj+
			 (MT[i].yt)*(MT[i].yt)*mn+
			 (MT[i].zt)*(MT[i].zt)*mn2 > 1.1 || 
			 MT[i].R > major
			 )
				){
			MT[i].state=0;
		}
		else if(MT[i].R > 2*major){//throw an error in case MT explodes
			cout << "WTF?!" << endl;
			cout << "MT " << i << " att2="<<MT[i].attached <<" ftip="<<MT[i].f_tip;
			cout <<" stable=" << MT[i].stable<<endl;
		}
	}

}

