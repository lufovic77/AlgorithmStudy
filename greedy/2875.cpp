#include <iostream>
using namespace std;
int main(){
	int N,M,K;
	cin>>N>>M>>K;
	while(K!=0){
		if(N>2*M){
			N--;K--;
		}
		else if (N<2*M){
			M--;K--;
		}
		else{//equal case
			M--;K--;
		} 
	}	
	int count = 0;
	while(1){
		N-=2;M--;
		if(N<0 || M<0)
		break;
		count++;
	}
	cout<<count;
}
