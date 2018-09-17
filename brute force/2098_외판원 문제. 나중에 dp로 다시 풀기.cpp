#include <iostream>
#include <algorithm>
using namespace std;
int map[17][17];	//not available: zero, available: cost 
int N;

int gogosing(int visited[],int curCity, int curLength){
	int flag=1;
	for(int i=1;i<=N;i++){
		if(visited[i]==0)
		flag=0;
	}
	if(flag==1)//visited all cities;
	return curLength;
	
	int minimum = 2100000000;
	for(int i=1;i<=N;i++){
		if(visited[i]==0 && map[curCity][i]!=0){ // where to go?
			visited[i]=1;
			minimum=min(minimum,gogosing(visited, i,curLength+map[curCity][i]));				
			visited[i]=0;
		}
	}
	return minimum;
}

int main(){
	cin>>N;
	int visited[20];
	for(int i=0;i<20;i++)
	visited[i]=0;
	for(int i=1;i<=N;i++){
		for(int k=1;k<=N;k++){
			cin>>map[i][k];
		}
	}
	//visited.assign(N+1, false);
	int cost=gogosing(visited, 1,0);
	cout<<cost;
}
