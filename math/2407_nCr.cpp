#include <iostream>
using namespace std;
typedef unsigned long long ull;
ull dp[110][110];
ull combi(int n, int r){
	if(dp[n][r]!=0)
		return dp[n][r];
	if(n==r)
		return 1;
	return dp[n][r] = (combi(n-1, r-1) + combi(n-1, r));
}
int main(){
	int n, r;
	cin>>n>>r;
	for(int i=1;i<=100;i++)
		dp[i][1] = i;
	ull ans = combi(n, r);
	cout<<ans;
}
