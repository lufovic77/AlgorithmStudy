#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
int map[1010][1010];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int m,n;
typedef struct{
	int x;
	int y;
	int day;
}POS;
queue<POS> array; 

void bfs (POS temp){
	int x = temp.x;
	int y = temp.y;
	int day = temp.day;
	for(int i=0;i<4;i++){
		int newx = x+dx[i];
		int newy = y+dy[i];
		if(map[newx][newy]==0 && newx>=0&&newy>=0&&newx<n&&newy<m){
			map[newx][newy]= day+1;
			POS temp;
			temp.x = newx;
			temp.y = newy;
			temp.day = day+1;
			array.push(temp);
		}
		
	}
}
int main(){
	cin>>m>>n;
	int a;
	int index = 0;
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++){
		cin>>a;
		if(a == 1){
			POS p = {i, j, 0};
			array.push(p);
		}
		map[i][j] = a;
	}
	
	//except case
	int flag = 1;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(map[i][j]==0){
				flag = 0;
				break;
			}
		}
	}
	if(flag == 1){
		cout<<"0";
		return 0;
	}
	//
	
	while(array.size()!=0){
		POS temp = array.front();
		array.pop();
		bfs(temp);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(map[i][j]==0){
				cout<<"-1";
				return 0;
			}
		}
	}
	int max = -1;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(max <= map[i][j])
			max = map[i][j];
		}
	}
	cout<<max;
}
