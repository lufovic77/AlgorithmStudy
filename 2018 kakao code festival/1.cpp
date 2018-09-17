#include <iostream>
using namespace std;
int first[7]={0,5000000, 3000000, 2000000, 500000, 300000, 100000};
int second[7] = {0,5120000, 2560000, 1280000, 640000, 320000};

int findA(int a){
	
		if( a== 0)
			return 0;
		else if(a <= 1)
			return 1;
		else if(a<=3)
			return 2;
		else if(a<=6)
			return 3;
		else if(a<=10)
			return 4;
		else if(a<=15)
			return 5;
		else if(a<=21)
			return 6;
		else 
			return 0;
}
int findB(int a){
		if( a== 0)
			return 0;
		else if(a <= 1)
			return 1;
		else if(a<=3)
			return 2;
		else if(a<=7)
			return 3;
		else if(a<=15)
			return 4;
		else if(a<=31)
			return 5;
		else 
			return 0;
	
}
int main(){
	int T;
	cin>>T;
	for(int i=0;i<T;i++){
		int a, b,index1, index2;
		cin>>a>>b;
		
		index1=findA(a);
		index2=findB(b);
		
		cout<<first[index1]+second[index2]<<endl;
	}
}
