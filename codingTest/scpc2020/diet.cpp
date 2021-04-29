#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;
#define FOR(i, n) for(int i=0;i<n;i++)
int main(){
	int t, n, k;
	cin>>t;
	FOR(i, t){
		vector <int> a, b;
		cin>> n>>k;
		int tmp;
		FOR(j, n){
			cin>>tmp;
			a.push_back(tmp);
		}
		FOR(j, n){
			cin>>tmp;
			b.push_back(tmp);
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		int maxi = INT_MIN;
		int m = 0, n = k-1;
		FOR(j, k){
			maxi = max(maxi, a[m]+b[n]);
			m++;n--;
		}
		printf("Case #%d\n%d\n", i+1, maxi);
	}
}
