#include <iostream>
using namespace std;
typedef unsigned long long int ull;
int main(){
	int n;
	cin>>n;
	ull dp[100];
	dp[0] = 0;
	dp[1] = 1;
	for(int i=2;i<=n;i++)
		dp[i] = dp[i-1]+dp[i-2];
	cout<<dp[n];
}