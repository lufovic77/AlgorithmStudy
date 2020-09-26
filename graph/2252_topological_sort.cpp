#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
vector<int> topo[32001];
vector<int> tree[32001];
int d;
int visited[32001];
void dfs(int node, int depth){
	if(visited[node])
		return ;
	topo[depth].push_back(node);
	visited[node] = 1;
	d = max(d, depth);
	for(auto a :tree[node])
		dfs(a, depth+1);
	return ;
}
int main(){
	map<int, int> root;
	int n, m, a, b;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		scanf("%d%d", &a, &b);
		if(root.find(b)!=root.end())
			root.erase(b);
		root.insert(make_pair(a, a));
		tree[a].push_back(b);
	}
	for(auto r = root.begin(); r!=root.end();r++)
		dfs(r->first, 1);
	for(int i=1;i<=d;i++){
		for(auto r: topo[i])
			printf("%d ", r);
	}
}
