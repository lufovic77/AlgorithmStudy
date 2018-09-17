#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll binom[100][100];
ll combination(int n, int k){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=min(i,k);j++){
			if(j==0 || j==i)
			binom[i][j]=1;
			else
			binom[i][j] = binom[i-1][j-1]+binom[i-1][j];	
		}		
	}
	return binom[n][k];
}

/*
ll combination(ll left, ll right){
	if(right ==0)
	return 1;
	if(left == right)
	return 1;
	return combination(left-1, right)+combination(left-1, right-1);
}*/

int main(){
	ll N;
	while(1){
		for(int i=0;i<100;i++)
		for(int j=0;j<100;j++)
		binom[i][j]=0;
		for(int i=0;i<100;i++){
		binom[i][1]=i;
		binom[i][0]=1;
		binom[i][i]=1;
		}
		cin>>N;
		if(N==0)
		exit(0);
		cout<<combination(2*N,N)/(N+1)<<endl;
	}
}
