#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int answer[700];
int map[30][30];
int visited[30][30];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int n,cnt =0;;
void find(int x, int y){
	if(x<0 || y<0 || x>n||y>n || visited[x][y]==1 ||map[x][y]==0)
		return ;
	visited[x][y]=1;
	cnt++;
	for(int i=0;i<4;i++){
		int newx = x + dx[i];
		int newy = y + dy[i];
		find(newx, newy);
	}
	return ;
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%1d", &map[i][j]);
		}
	}
	int index = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<30;j++){
				cnt =0;
				find(i,j);
				if(cnt != 0)
				answer[index++] = cnt;
			
		}
	}
	sort(answer, answer+index);
	cout<<index<<endl;
	for(int i=0;i<index;i++)
	cout<<answer[i]<<endl;
}
