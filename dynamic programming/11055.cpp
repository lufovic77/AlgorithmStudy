#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define FOR(i, n) for(int i=0;i<n;i++)
using namespace std;
int dp[1010];
int main(){
	vector <int> arr;
	int n, tmp, maxi;
	cin>>n;
	FOR(i, n){
		cin>>tmp;
		arr.push_back(tmp);
	}
	FOR(i, n){
		maxi = 0;
		FOR(j, i){
			if(arr[j]<arr[i])
				maxi = max(maxi, dp[j]);	
		}
		dp[i] += maxi+arr[i];
	}
	maxi = -1;
	for(auto a: dp)
		maxi = max(maxi, a);
	cout<<maxi;
}
