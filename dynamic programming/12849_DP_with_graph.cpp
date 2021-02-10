#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef unsigned long long ull;
ull dp[8][100001];
vector <int> map[8];
ull dfs(int node, int time, int n){
	if(dp[node][n-time]!=0){
		return dp[node][n-time];
	}	
	if(node==0 && time == n){
		return dp[node][n-time] = 1;
	}
	for(auto a: map[node]){
		if(time<n)
			dp[node][n-time] += dfs(a, time+1, n)%1000000007;
	}
	return dp[node][n-time];
}
int main(){
	map[0] = {1,2};
	map[1] = {0,2,3};
	map[2] = {0,1,3,4};
	map[3] = {1,2,4,5};
	map[4] = {2,3,5,6};
	map[5] = {3,4,7};
	map[6] = {4,7};
	map[7] = {5,6};
	int n;
	cin>>n;
	ull ret = dfs(0, 0, n);
	cout<<dp[0][n];
}
