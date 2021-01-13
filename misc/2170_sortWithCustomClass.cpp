#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#define FOR(i,n) for(int i=0;i<n;i++)
#define FOR2(i,n) for(int i=1;i<=n;i++)
using namespace std;
bool cmp(pair<int, int> u, pair<int, int> t){
	if(u.first==t.first)
		return u.second <t.second;
	return u.first<t.first;
}

int main(){
	int n, a, b;
	vector<pair<int, int> >pos;
	cin>>n;
	FOR(i, n){
		scanf("%d%d", &a, &b);
		pos.push_back(make_pair(a, b));
	}
	sort(pos.begin(), pos.end(), cmp);
	int len = 0,l, r;
	FOR(i, n){
		int f = pos[i].first;
		int s = pos[i].second;
		if(i == 0){
			l = f, r = s;
			continue;
		}
		if(f > r){ // new range		
			len += (r-l);
			l = f, r=s;
		}
		if(f <= r && s>r){
			r = s;
		}
		if(i==n-1)
			len+=(r-l);
	}
	cout<<len;
}
