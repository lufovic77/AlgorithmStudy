#include <iostream>
#include <algorithm>
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;
int main(){
	int n, m, arr[100], sum, maxi;
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	maxi = -1;
	FOR(i,n){
		FOR(j,n){
			if(i==j)
				continue;
			FOR(k,n){
				if(k==i || k==j)
					continue;
				sum = arr[i]+arr[j]+arr[k];
				if(sum<=m)
					maxi = max(maxi, sum);
			}
		}
	}
	cout<<maxi;
}
