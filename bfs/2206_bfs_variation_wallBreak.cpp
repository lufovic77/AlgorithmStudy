#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <queue>
#define FOR(i,n) for(int i=0;i<n;i++)
#define FOR2(i,n) for(int i=1;i<=n;i++)
using namespace std;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int map[1010][1010]; //just for zero initialization
int mini = INT_MAX;
int n,m;
void recursion(queue<pair< pair<int, int> ,pair<int, int> > > q, vector<vector<int>> visited){
	while(!q.empty()){
			int newx, newy;
			int x = q.front().first.first, y = q.front().first.second;
			int attempt = q.front().second.first, cnt = q.front().second.second;
			q.pop();
			FOR(i, 4){
				newx = x+dx[i];
				newy = y+dy[i];
				if(newx == n && newy == m){
					mini = min(mini, cnt+1);
					return ;
				}
				if(visited[newx][newy] == 0 && newx>=1&&newy>=1&&newx<=n&&newy<=m &&map[newx][newy]==0){
					visited[newx][newy] = 1;
					q.push(make_pair(make_pair(newx, newy), make_pair(attempt, cnt+1)));
				}
			}
	}
}
int main(){
	vector<vector<int>> visited;
	FOR(i, 1010){
		vector<int> tmp;
		tmp.assign(1010, 0);
		visited.push_back(tmp);
	}
	queue<pair< pair<int, int> ,pair<int, int> > > q; //(x,y) , (break wall, cnt)
	cin>>n>>m;
	FOR2(i, n)
		FOR2(j, m){
			scanf("%1d", &map[i][j]);
		}
	if(n==1 && m==1){
		cout<<"1";
		return 0;
	}
	q.push(make_pair(make_pair(1, 1), make_pair(1, 1)));
	visited[1][1] = 1;
	while(!q.empty()){
			int newx, newy;
			int x = q.front().first.first, y = q.front().first.second;
			//cout<<x<<" "<<y<<" "<<visited[1][10]<< endl;
			int attempt = q.front().second.first, cnt = q.front().second.second;
			q.pop();
			FOR(i, 4){
				newx = x+dx[i];
				newy = y+dy[i];
				if(newx == n && newy == m){
					mini = min(mini, cnt+1);
					continue;
				}
				if(visited[newx][newy] == 0 && newx>=1&&newy>=1&&newx<=n&&newy<=m ){
					if(map[newx][newy]==1){ //is wall
						if(attempt==1){
							visited[newx][newy] = 1;
							queue<pair< pair<int, int> ,pair<int, int> > > newq;
							newq.push(make_pair(make_pair(newx, newy), make_pair(0, cnt+1)));
							/*int newmap[1010][1010];
							FOR2(a, n)
								FOR2(b, m)
								newmap[a][n] = visited[a][b];*/
							recursion(newq,visited);
						}
					}
					else{ //no wall
							visited[newx][newy] = 1;
							q.push(make_pair(make_pair(newx, newy), make_pair(attempt, cnt+1)));
					}
				}
			}
		}
	if(mini == INT_MAX)
		cout<<"-1";
	else
		cout<<mini;
}
