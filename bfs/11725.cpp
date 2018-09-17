#include <iostream>
#include <cstdio>
using namespace std;
int info[1010][1010];
int check[1010];
int cnt = 0;
bool visit(){
	for(int i=0;i<1010;i++){
		if(check[i]==1)
			return false;
	}
	return true;
}
void bfs(int node){
	check[node]=0;
	for(int i=0;i<1010;i++){
		if(info[node][i]==1 && check[i]==1)
			bfs(i);
	}
	return ;
}
int main(){
	int n, m;
	cin >>n>>m;
	int num = 0;
	for(int i=0;i<m;i++){
		int a, b;
		cin>>a>>b;
		check[a] = check[b]= info[b][a]= info[a][b] = 1;
	}
	for(int i=0;i<1010;i++)
	if(check[i]==1)
	num++;
	while(1){
		for(int i=1;i<=n;i++){
			if(check[i]==1){
				bfs(i);
				break;
			}
		}
		cnt++;
		if(visit()){
			cout<<cnt+n-num;
			return 0;
		}
	}
	
}
