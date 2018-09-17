#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
int n,v; 
int relation[1010][1010];
int visited[1010];
queue <int> array;
void dfs(int node, int count){
	if(count == n)
	return ;
	if(node == v && count!=0)
	return ;
	printf("%d ", node);
	visited[node]=1;
	for(int i=1;i<=n;i++){
		if(i==node)
		continue;
		if(relation[node][i]==1 && visited[i]!=1)
		dfs(i, count+1);
	}	
}
void bfs(int node){
	for(int i=1;i<=n;i++){
		if(i==node)
		continue;
		if(relation[node][i]==1 && visited[i]!=1){
			array.push(i);
			visited[i]=1;			
		}
	}
}
int main(){
	int m;
	cin>>n>>m>>v;
	
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		relation[a][b]=1;
		relation[b][a]=1;
	}
	
	dfs(v, 0);
	cout<<endl;
	for(int i=0;i<=n;i++)
	visited[i]=0;
	
	
	visited[v]=1;
	array.push(v);
	while(array.size()!=0){
		int temp = array.front();
		bfs(temp);
		cout<<temp<<" ";
		array.pop();
	}
}
