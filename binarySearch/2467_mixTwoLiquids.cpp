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
	pair<int, int> mini;
	vector<int> v;
	cin>>n;
	FOR(i, n){
		cin>>tmp;
		v.push_back(tmp);
	}
	FOR(i, n){
		int left = 0, right = v.size()-1, mid;
		int start = 0, end = v.size()-1;
		unsigned long long sum, rsum, lsum;
		bool rflag, lflag;
		num = v[i];
		while(left<=right){
			mid = (left+right)/2;
			rflag = lflag = false;
			sum = num+v[mid];
			if(mid+1==end){ //오른쪽 구간 확인.
				rsum = num+v[mid+1];
				rflag = true;
			}
			if(mid-1==0){
				lsum = num+v[mid-1];
				lflag = true;
			}

			if(abs())

		}
	}
}
