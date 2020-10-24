#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int visited[100001];
int main(){
	int n, m, ret=0;
	cin>>n>>m;
	if(m<=n){
		cout<<n-m;
		return 0;
	}
	queue <pair<int, int> > q;
	q.push(make_pair(n, ret));
	while(!q.empty()){
		n = q.front().first;
		ret = q.front().second;
		q.pop();
		if(n>100000 || n<0)
			continue;
		if(visited[n])
			continue;
		visited[n] = 1;
		if(n==m){
			cout<<ret;
			return 0;
		}
		q.push(make_pair(n-1,ret+1));
		q.push(make_pair(n+1,ret+1));
		q.push(make_pair(n*2,ret+1));
	}
}
