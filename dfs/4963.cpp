#include <iostream>
#include <cstdio>
#define FOR(i, n) for(int i=0;i<n;i++)
using namespace std;
int sum;
int map[50][50];
int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
void dfs(int r, int c, int w, int h){
	map[r][c] = 0;
	FOR(i, 8){
		int newr = r+dx[i];
		int newc = c+dy[i];
		if(newr<h && newr>=0 && newc<w && newc>=0 && map[newr][newc]==1){
			map[newr][newc] = 0;
			dfs(newr, newc, w, h);		
		}
	}
	return ;
}	
int main(){
	int w, h;
	while(1){
		sum = 0;
		cin>>w>>h;
		if(w==0 && h==0)
			return 0;
		FOR(i, h){
			FOR(j, w){
				cin>>map[i][j];
			}
		}
		FOR(i, h){
			FOR(j, w){
				if(map[i][j]==1){
					dfs(i, j, w, h);
					sum++;
				}
			}
		}
		printf("%d\n", sum);
	}
}
