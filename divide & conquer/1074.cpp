#include <iostream>
#include <math.h>
using namespace std;
long long order=0;
int N, r, c;
void traverse(int ux, int uy, int dx, int dy){
	if(ux==dx && uy==dy){
		if(ux == r && uy ==c){
			cout<<order;
			exit(0);
		}
		order++;
		return ;
	}
	int halfX = (ux+dx)/2;
	int halfY = (uy+dy)/2;
	traverse(ux, uy, halfX, halfY);
	traverse(ux,halfY+1,halfX , dy);
	traverse(halfX+1, uy, dx, halfY);
	traverse(halfX+1, halfY+1, dx, dy);	
	return ;
}

int main(){
	cin>>N>>r>>c;
	long long total = pow(2,2*N);
	int ux = 0, uy =0, dx = pow(2,N)-1, dy=pow(2,N)-1;
	
	int halfX = (ux+dx)/2;
	int halfY = (uy+dy)/2;
	
	if(r>=ux &&r<=halfX && c>=0 && c<=halfY){	//1사분면 
		order = 0;
		traverse(0,0,halfX, halfY);
	}
	else if(r>=0 &&r<=halfX && c>=halfY+1 && c<=dy){	//2사분면 
		order = total/4;
		traverse(0,halfY+1,halfX, dy);
	}
	else if(r>=halfX+1 &&r<=dx && c>=0 && c<=halfY){	//3사분면 
		order = 2*total/4;
		traverse(halfX+1,0,dx, halfY);
	}
	else if(r>=halfX+1 &&r<=dx && c>=halfY+1 && c<=dy){	//4사분면 
		order = 3*total/4;
		traverse(halfX+1,halfY+1,dx, dy);
	}
	
}
