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
int visited[10010];
pair<int, int> parent[10010];//index: child node, first: parent value, second: weight
vector<int> child[10010];
int ans;
void dfs(int start, int end, int cnt){
	if(start == end){
		ans = cnt;
		return ;
	}
	int p = parent[start].first;
	if(p >0 && visited[p]==0){ //go parent
		visited[p] = 1;
		dfs(parent[start].first, end, cnt+parent[start].second);
		visited[p] = 0;
	}
	for(auto node: child[start])
		if(node>0 && visited[node]==0){ //go to child
			visited[node] = 1;
			dfs(node, end, cnt+parent[node].second);
			visited[node] = 0;
		}
	return ;
}
int main(){
	int n, a, b, c, maxi = INT_MIN;
	cin>>n;
	parent[1].first = -1;
	vector<int> node;
	node.push_back(1);
	FOR(i, n-1){
		scanf("%d%d%d", &a, &b, &c);
		parent[b].first = a;
		parent[b].second = c;
		child[a].push_back(b);
		node.push_back(b);
	}
	for(int i=0;i<node.size();i++){
		for(int j=i;j<node.size();j++){
			ans = INT_MIN;
			if(i==j)
				continue;
			visited[node[i]] = 1;
			dfs(node[i], node[j], 0); 
			maxi = max(maxi,ans);
			fill(visited, visited+10010, 0);
		}
	}
	cout<<maxi;
}
