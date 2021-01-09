#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <limits.h>
#define FOR(i,n) for(int i=0;i<n;i++)
#define FOR2(i,n) for(int i=1;i<=n;i++)
using namespace std;
int sx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int sy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int map[201][201];
int w, h; //(h, w) is the end point
int total = INT_MAX;
int visited[201][201];
void dfs(int x, int y, int cnt, int k){
	if(x == h && y == w){
		total = min(total, cnt);
		return ;
	}
	int newx, newy;
	if(k>0){
		FOR(i, 8){
			newx = x+sx[i];
			newy = y+sy[i];
			if(newx <= h && newx >0 && newy<=w && newy>0 && visited[newx][newy] == 0 && \
					map[newx][newy] == 0){
				visited[newx][newy] = 1;
				dfs(newx, newy, cnt+1, k-1);
				visited[newx][newy] = 0;
			}
		}
	}
	FOR(i, 4){
		newx = x+dx[i];
		newy = y+dy[i];
		if(newx <= h && newx >0 && newy<=w && newy>0 && visited[newx][newy] == 0 && \
			map[newx][newy] == 0){
			visited[newx][newy] = 1;
			dfs(newx, newy, cnt+1, k);
			visited[newx][newy] = 0;
		}
	}	
	return ;
}
int main(){
	int k, tmp;
	cin>>k>>w>>h;
	FOR2(i, h)
		FOR2(j, w){
			scanf("%d", &tmp);
			map[i][j] = tmp;
		}
	visited[1][1] = 1;
	dfs(1, 1, 0, k);
	if(total < INT_MAX)
		cout<<total;
	else
		cout<<"-1";
	return 0;
}
