#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#define FOR(i, n) for(int i=0;i<n;i++)
using namespace std;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
int map[51][51];
int visited[51][51];
int main(){
	int r, c, pr, pc, wr, wc,spot=0, tmp, cnt=1, tmp2;
	cin>>r>>c;
	// . for 0(clear), * for 1(water) and X for 2(stone)
	char ch;
	queue<pair<int, int> > pos;
	queue<pair<int, int> > water;
	FOR(i, r)
		FOR(j, c){
			cin>>ch; //better use cin than scanf due to buffer manipulation.
			switch(ch){
				case '.':
					break;
				case '*':
					spot++;
					water.push(make_pair(i, j));
					map[i][j] = 1;
					break;
				case 'X':
					map[i][j] = 2;
					break;	
				case 'D':
					map[i][j] = 3; //final destination
					break;
				case 'S':
					visited[i][j] = 1;
					pos.push(make_pair(i, j));
				default:
					break;
			}	
		}
	int ret = 0;

	while(1){
		tmp2=0;
		FOR(i, cnt){
			pr = pos.front().first;
			pc = pos.front().second;
			pos.pop();
			if(map[pr][pc]==3){
				cout<<ret;
				return 0;
			}
			if(map[pr][pc] == 1){ //water
				continue;
			}
			FOR(j, 4){
				int nr = pr+dr[j], nc = pc+dc[j];
				if(nr<0 || nr>=r || nc<0 || nc>=c) //out of range
					continue;
				if(map[nr][nc]==1 || map[nr][nc]==2 || visited[nr][nc])
					continue;
				pos.push(make_pair(nr, nc));
				visited[nr][nc] = 1;
				tmp2++;
			}	
		}
		if(pos.empty())
			break;
		cnt = tmp2;
		tmp = 0;
		//spreading water
		FOR(i, spot){
			wr = water.front().first;
			wc = water.front().second;
			water.pop();
			FOR(j, 4){
				int nr = wr+dr[j], nc = wc+dc[j];
				if(nr<0 || nr>=r || nc<0 || nc>=c) //out of range
					continue;
				if(map[nr][nc]==1 || map[nr][nc]==2 || map[nr][nc]==3)
					continue;
				map[nr][nc] = 1;
				water.push(make_pair(nr, nc));
				tmp++;
			}
		}
		spot = tmp;
		ret ++;
	}
	cout<<"KACTUS";
	return 0;
}
