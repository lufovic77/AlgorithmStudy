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
int depth[50010];
int par[50010];
vector<int> edge[50010];
int main(){
	int n, m, a, b;
	vector<int> ret;
	vector<int> tree[50010];
	cin>>n;
	ios::sync_with_stdio(false);
	depth[1] = 1; //node number 1's depth: 1
	par[1] = -1;
	FOR(i, n-1){
		cin>>a>>b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	/* 정말 주의할 점은 자식과 부모 정보가 주어지지 않은 노드도 먼저 나올 수 있다는 것!
	 * */
	queue<int> q;
	q.push(1);
	while(!q.empty()){
		int node = q.front();
		q.pop();
		for(auto n: tree[node]){
			if(depth[n] == 0){
				par[n] = node;
				depth[n] = depth[node] +1;
				q.push(n);
			}
		}
	} //tree formation finished.
	cin>>m;
	FOR(i, m){
		int inA, inB;
		cin>>inA>>inB;
		a = inA;
		b = inB;
		if(depth[a] > depth[b])
			FOR(j, depth[inA]-depth[inB])
				a = par[a];
		else
			FOR(j, depth[inB]-depth[inA])
				b = par[b];
		while(a!=b){
			a = par[a];
			b = par[b];
		}
		ret.push_back(a);
	}
	for(auto ans: ret)
		cout<<ans<<endl;
}
