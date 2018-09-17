#include <iostream>
using namespace std;
int n,m;
int mark[510];
int visited[510];
int friends[510][510];
void invite(int who, int depth){
	if(depth>=2 || visited[who]==1)
	return ;
	visited[who]=1;
	for(int i=1;i<=n;i++)
	if(friends[who][i]==1 && visited[i]!=1){
		mark[i]=1;
		invite(i, depth+1);
	}
	return ;	
}
int main(){
	cin>>n>>m;
	for(int i=0;i<510;i++)
	mark[i]=0;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		friends[a][b]=1;
		friends[b][a]=1;
	}
	invite(1, 0);
	int count=0;
	for(int i=1;i<=n;i++)
	if(mark[i]==1){
	count++;
	}
	cout<<count;
}
