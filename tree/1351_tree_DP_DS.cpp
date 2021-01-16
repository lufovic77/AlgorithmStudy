#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <queue>
#define FOR(i,n) for(int i=0;i<n;i++)
#define FOR2(i,n) for(int i=1;i<=n;i++)
using namespace std;
typedef unsigned long long ull;
ull dp[1000000];
ull p,q;
ull BT(ull node){
	//cout<<node<<endl;
	if(node == 0)
		return 1;
	if(node <1000000 && dp[node]!=0)
		return dp[node];
	if(node < 1000000)
		return dp[node] = BT(node/p) + BT(node/q); 
	else 
		return BT(node/p) + BT(node/q);
}
int main(){
	ull n;
	dp[0] = 1;
	dp[1] = 2;
	cin>>n>>p>>q;
	cout<<BT(n);
}
