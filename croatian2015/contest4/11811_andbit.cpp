#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define FOR(i, n) for(int i=1;i<=n;i++)
using namespace std;
int main(){
	int n, t;
	int map[1010][1010];
	vector<int> ret;
	cin>>n;
	FOR(i, n)
		FOR(j, n)
			scanf("%d", &map[i][j]);
	FOR(i, n){
		t = 0;
		FOR(a, i)
			if(a!=i)
			t |= map[a][i];
		for(int b = i;b<=n;b++)
			if(b!=i)
			t |= map[i][b];
		ret.push_back(t);
	}
	for(auto a: ret)
		cout<<a<<" ";
}
