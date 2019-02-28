#include <iostream>
using namespace std;
int main(){
	int a,b,c;
	cin>>a>>b>>c;
	int cnt=0;
	while(c!=b){
		bool flag1=false, flag2=false;
		if(b%2==1)//odd
		flag1=true;
		if(c%2==1)//odd
		flag2=true;
		b=b/2;
		c=c/2;
		if(flag1)
		b++;
		if(flag2)
		c++;
		cnt++;
	}	
	cout<<cnt;
}
