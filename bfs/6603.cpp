#include <iostream>
using namespace std;
int n;
int array[15];
void bfs(int index, int count, int visited[]){
	if(count ==6){
		//print
		for(int i=0;i<n;i++)
		if(visited[i]==1)
		cout<<array[i]<<" ";
		cout<<endl;
		return ;
	}
	if(index == n)return;
	visited[index]=1;
	bfs(index+1, count+1, visited);
	visited[index]=0;
	bfs(index+1, count, visited);
	return ;	
}
int main(){
	while(1){
		cin>>n;
		if(n==0)
		return 0;
		for(int i=0;i<n;i++)
		cin>>array[i];
		int visited[15];
		for(int i=0;i<15;i++)
		visited[i]=0;
		bfs(0, 0,visited);
	}
	return 0;	
}
