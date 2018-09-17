#include <iostream>
#include <math.h>
using namespace std;
bool check(int num){
	int half = sqrt(num);
	int j=3;
	for(int i=2;i<=half, j<=half;i+=2, j+=3)
	if(num%i==0 || num%j==0)
	return true;
	return false;
}
int main(){
	int k;
	cin>>k;
	int count = 0, num = 2;
	if(k == 1){
		cout<<"2";
		return 0;
	}
	while(1){
		if(!check(num)){
			count++;
		}
		if(count==k){
			cout<<num;
			exit(0);
		}
		num++;
	}
}
