#include <iostream>
using namespace std;
int main(){
	int N, div, temp;
	cin>>N;
	div = N/5;
	while(div>=0){
		temp = N-5*div;
		if(temp%3==0){
			cout<<div+temp/3;
			return 0;
		}
		else
			div--;
	}
	cout<<-1;
}
