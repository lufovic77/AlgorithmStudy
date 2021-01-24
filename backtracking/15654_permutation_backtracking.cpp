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
int ret[10];
int visited[10];
vector<int> v;
int n;
void backtrack(int index,int rem, int len){
	if(rem==0){
		FOR(i, len)
			printf("%d ", ret[i]);
		printf("\n");
		return ;
	}
	FOR(i, n){
		if(visited[i]==0){
			visited[i] = 1;
			ret[index] = v[i];
			backtrack(index+1, rem-1, len);
			visited[i] = 0;
		}
	}
	return ;
}
int main(){
	int m, tmp;
	cin>>n>>m;
	FOR(i, n){
		cin>>tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	backtrack(0,m, m);
}
