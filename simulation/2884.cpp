#include <iostream>
#include <cstdio>
using namespace std;
/*
 * Revision*/
int main(){
	int h,m,rem;
	cin>>h>>m;
	if(m>=45)
		printf("%d %d", h, m-45);
	else{
		rem = 45-m;
		rem = 60-rem;
		if(h == 0)
			printf("23 %d",rem);
		else
			printf("%d %d", h-1, rem);
	}
}

/* 
int main(){
	int H,M;
	cin>>H>>M;
	int minute=H*60+M;
	minute-=45;
	if(minute<0){	//전날로 넘어감 
		cout<<"23 "<<60+minute;
	}
	else if (minute==0){
		cout<<"0 00";
	} 
	else{//common case
		cout<<minute/60<<" "<<minute%60;
	}
}
*/
