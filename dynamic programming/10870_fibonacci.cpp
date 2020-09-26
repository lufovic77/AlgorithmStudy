#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define FOR(i, n) for(int i=0;i<n;i++)
using namespace std;
int main(){
	int dp[30];	int n;
	dp[0] = 0;
	dp[1] = 1;
	for(int i=2;i<=20;i++)
		dp[i] = dp[i-1] + dp[i-2];
	cin>>n;
	cout<<dp[n];
}
