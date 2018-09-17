#include <iostream>
using namespace std;

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
