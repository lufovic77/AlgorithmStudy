#include <iostream>
#include <queue>
#include <vector>
#define FOR(i, n) for(int i=0;i<n;i++)
using namespace std;
int main(){
	int n, pair, t1, t2, cnt, cur;
	int visited[101];
	fill(visited, visited+100, 0);
	vector<int> map[101];
	cin>>n>>pair;
	FOR(i, pair){
		cin>>t1>>t2;
		map[t1].push_back(t2);
		map[t2].push_back(t1);
	}
	cnt = 0;
		queue<int> q;
		q.push(1);
		while(!q.empty()){
			cur = q.front();
			q.pop();
			if(visited[cur] == 1)
				continue;
			visited[cur] = 1;		
			for(auto a: map[cur])
				q.push(a);
			if(cur != 1)
			cnt++;
		}
	cout<<cnt;
}
