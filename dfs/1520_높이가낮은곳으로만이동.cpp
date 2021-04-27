#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <queue>
#define FOR(i,n) for(int i=0;i<n;i++)
#define FOR2(i,n) for(int i=1;i<=n;i++)
int dx[4] = {-1, 0, 1, 0}; 
int dy[4] = {0, 1, 0, -1};
using namespace std;
int ret = 0, m, n;
int dp[510][510];
int visited[510][510];
int map[510][510];
/*
나는 항상 기준이
  -> 요기가 y 
   ---------------
요 |			  |
기 |			  |
가 |			  |
x  ---------------
 */
int dfs(int x, int y){
	if (x == m-1 && y == n-1 )
		return 1;
	if(dp[x][y]!=0){
		return dp[x][y];
	}
	FOR(i, 4){
		int newX = x + dx[i];
		int newY = y + dy[i];
		if(newX >= 0 && newX<m && newY>=0 && newY <n && visited[newX][newY] == 0 && map[x][y] > map[newX][newY]){
			visited[newX][newY] = 1;
			dp[x][y] += dfs(newX, newY);
			visited[newX][newY] = 0;
		}
	}
	return dp[x][y];
}
int main(){
	ios::sync_with_stdio(false);//Should not combine iostream with cstdio furthur
	int tmp;
	cin>>m>>n;
	FOR(i, m){
		FOR(k, n){
			cin>>tmp;
			map[i][k] = tmp;
		}
	}
	visited[0][0] = 1;
	int ret = dfs(0, 0);
	cout<<dp[0][0];
}
