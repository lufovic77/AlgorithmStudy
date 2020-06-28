#include <iostream>
#include <queue>
#include <vector>
#define FOR(i, n) for(int i=0;i<n;i++)
using namespace std;
int main(){
	int n, pair, t1, t2, cnt, cur;
	int visited[11];
	fill(visited, visited+10, 0);
	vector<int> map[11];
	cin>>n>>pair;
	FOR(i, pair){
		cin>>t1>>t2;
		map[t1].push_back(t2);
	}
	cnt = 0;
	queue<int> q;
	q.push(1);
	while(!q.empty()){
		cur = q.back();
		q.pop();
		if(visited[cur] == 1)
			continue;
		visited[cur] = 1;		
		for(auto a: map[cur])
			q.push(a);
		cnt++;
	}
	cout<<cnt;
}
