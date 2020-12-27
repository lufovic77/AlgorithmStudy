#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;
int dx[4] = {1, -1, 0, 0}; 
int dy[4] = {0, 0, 1, -1}; //E, W, S, N
double poss[4];
double sum=0;
int visited[30][30];
void dfs(int x, int y, int cnt,double partial, int end){
	if(visited[x][y] == 1 || partial == 0)
		return;
	if(cnt == end){
		sum+=partial;
		return ;
	}
	int newx, newy;
	FOR(i, 4){
		newx = x+dx[i];
		newy = y+dy[i];
		if(visited[newx][newy] ==0 ){
			visited[x][y] = 1;
			dfs(newx, newy, cnt+1, partial*poss[i],end);
			if(cnt != 0)
			visited[x][y] = 0;
		}
	}

}
int main(){
	int n;
	double tmp;
	cin>>n;
	FOR(i, 4){
		cin>>tmp;
		poss[i] = tmp/100;
	}
	dfs(14,14,0,1,n);
	printf("%.10lf", sum);
}
