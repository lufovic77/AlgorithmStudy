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
	return u.second<=t.second;
}

int main(){
	int n, a, b;
	vector<pair<int, int> >pos;
	FOR(i, n){
		scanf("%d%d", &a, &b);
		pos.push_back(make_pair(a, b));
	}
	sort(pos.begin(), pos.end(), cmp);
}
