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
int main(){
	ios::sync_with_stdio(false);
	int n, tmp, num;
	pair< long long, pair<int, int> > mini = make_pair(INT_MAX, make_pair(0, 0));
	vector<int> v;
	cin>>n;
	FOR(i, n){
		cin>>tmp;
		v.push_back(tmp);
	}
	FOR(i, n){
		int left = 0, right = v.size()-1, mid;
		int start = 0, end = v.size()-1;
		long long sum, rsum, lsum;
		num = v[i];
		while(left<=right){
			mid = (left+right)/2;
			sum = abs(num+v[mid]);
			if(sum<=mini.first && v[mid]!=num){
				mini.first = sum;
				mini.second.first = min(num, v[mid]);
				mini.second.second = max(num, v[mid]);
			}			
			lsum = num+v[mid-1];
			rsum = num+v[mid+1];
			if(abs(lsum) < abs(rsum))
				right = mid-1;
			else 
				left = mid+1;
		}
	}
	cout<<mini.second.first<<" "<<mini.second.second;
}
