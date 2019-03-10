#include <iostream>
using namespace std;
int gcd(int a,int b){
	if (b==0)return a;
	else return gcd(b,a%b);
}
int main(){
	int a1,b1,a2,b2;
	cin>>a1>>b1>>a2>>b2;
	int a3 = a1*b2+a2*b1, b3= b1*b2;
	int temp;
	while((temp=gcd(a3,b3))!=1){
		a3=a3/temp;
		b3=b3/temp;
	}
	cout<<a3<<" "<<b3;
}
