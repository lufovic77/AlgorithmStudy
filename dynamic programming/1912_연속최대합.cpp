#include <iostream>
#include <cstdio>
#include <vector>
#include <limits.h>
#include <algorithm>
#define FOR(i, n) for(int i=0;i<n;i++)
using namespace std;
int main(){
	int n, tmp, maxi;
	cin>>n;
	vector<int> arr;
	int dp[100001];
	FOR(i, n){
		scanf("%d", &tmp);
		arr.push_back(tmp);
	}
	maxi = INT_MIN;
	dp[0] = arr[0];
	for(int i=1;i<n;i++){
		if(dp[i-1] + arr[i] < 0 ){
			maxi = max(maxi, dp[i-1]);
			dp[i] = arr[i];
			if(i==n-1)
				maxi = max(maxi, dp[i]);
			continue;
		}
		if(dp[i-1]+arr[i]>0 && dp[i-1]<0){
			maxi = max(arr[i], maxi);
			dp[i] = arr[i];
			continue;
		}
		dp[i] = dp[i-1] + arr[i];
		maxi = max(maxi, dp[i]);
	}
	cout<<maxi;
}
