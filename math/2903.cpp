#include <iostream>
using namespace std;
int main(){
	int n, init, add, rec, sub;
	init = 9;
	rec = 4;
	cin>>n;
	for(int i=1;i<n;i++){
		add = 5*rec;
		sub = 0;
		for(int j=1;j<=2*i-1;j++)
			sub +=1;
		add = add - 4*sub;
		init += add;
		rec*=4;
	}
	cout<<init;
}
