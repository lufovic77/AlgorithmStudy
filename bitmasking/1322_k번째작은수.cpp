#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <queue>
#include <bitset>
#define FOR(i,n) for(int i=0;i<n;i++)
#define FOR2(i,n) for(int i=1;i<=n;i++)
using namespace std;
bitset<35> biX;
bitset<35> biK;
int main(){
	ios::sync_with_stdio(false);//Should not combine iostream with cstdio furthur
	unsigned long long ret=0;
	int x,k, index = 0;
	cin>>x>>k;
	while(x>0){
		if(x%2 == 1)
			biX.set(index,true);
		else
			biX.set(index, false);
		x /= 2;
		index++;
	}
	vector <int> zeroIndex, oneIndex;
	FOR(i, 35){
		if(biX[i]==0)
			zeroIndex.push_back(i);
		else
			oneIndex.push_back(i);
	}
	//사실 zeroIndex만 있으면 되긴 함. 
	index = 0;
	while(k>0){
		if(k%2 == 1)
			biK.set(index,true);
		else
			biK.set(index, false);
		k /= 2;
		index++;
	}
	biX = ~biX;
	index = 0;
	for(auto a: zeroIndex){
		if(biK[index] == 1)
			biX.set(a,true);
		else
			biX.set(a,false);
		index++;
	}
	FOR(i, 35)
		ret+=biX[i]*pow(2, i);
	cout<<ret;
}
