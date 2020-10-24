#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#define FOR(i, n) for(int i=0;i<n;i++)
using namespace std;
int normal[101][101];
int vn[101][101];
int disable[101][101];
int vd[101][101];
/*
 * R for 0
 * G for 1
 * B for 2
 * */
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int main(){
	int n;
	char c;
	cin>>n;
	FOR(i, n){
		FOR(j, n){
			cin>>c;
			switch(c){
				case 'R':
					break;
				case 'G':
					normal[i][j] = 1;
					break;
				case 'B':
					normal[i][j] = 2;
					disable[i][j] = 2;
					break;
				default:
					continue;
			}

		}
	}
	queue<pair<int, int> > q;
	int x, y, dist = 0, tmp, cnt=0;
	//for normal
	FOR(i, n){
		FOR(j, n){
			if(vn[i][j]!=1){
				q.push(make_pair(i, j));
				tmp = normal[i][j];
				vn[i][j] = 1;
				while(!q.empty()){
					x = q.front().first;
					y = q.front().second;
					q.pop();
					FOR(k, 4){
						int nx = x+dx[k], ny = y+dy[k];
						if(vn[nx][ny])
							continue;
						if(nx<0||nx>=n||ny<0||ny>=n)
							continue;
						if(normal[nx][ny] != tmp)
							continue;
						q.push(make_pair(nx, ny));
						vn[nx][ny] = 1;
						/*
						 * IF, visiting statement is not here, 
						 * queue will explode in the case where
						 * all elements on the map are same*/
					}
				}
				dist++;
			}
		}
	}
	cout<<dist<<" ";
	dist = 0;
	while(!q.empty())
		q.pop();
	//for disabled. precisely, they are not disabled. 
	FOR(i, n){
		FOR(j, n){
			if(vd[i][j]!=1){
				q.push(make_pair(i, j));
				tmp = disable[i][j];
				vd[i][j] = 1;
				while(!q.empty()){
					x = q.front().first;
					y = q.front().second;
					q.pop();
					FOR(k, 4){
						int nx = x+dx[k], ny = y+dy[k];
						if(vd[nx][ny])
							continue;
						if(nx<0||nx>=n||ny<0||ny>=n)
							continue;
						if(disable[nx][ny] != tmp)
							continue;
						q.push(make_pair(nx, ny));
						vd[nx][ny] = 1;
					}
				}
				dist++;
			}
		}
	}
	cout<<dist;
}
