#include <iostream>
#include <cstdio>
using namespace std;

char board[50][50];
int visited[8][8];
int temp[8][8];
int N,M;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int count=0;
void copy(int x,int y){
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if(board[i+x][j+y]=='B')
			temp[i][j]=0;
			else
			temp[i][j]=1;	//white: 1
		}
	}
}
void clear(){
	for(int i=0;i<8;i++)
	for(int j=0;j<8;j++)
	visited[i][j]=0;
}
void compare(int x, int y, int prev){
	if(x<0||y<0||x>=8||y>=8 || visited[x][y]==1)
	return ;
	if(temp[x][y]==prev){
		temp[x][y]=!prev;
		count++;
	}
	visited[x][y]=1;
	for(int i=0;i<4;i++){
		compare(x+dx[i], y+dy[i], temp[x][y]);
	}
	return ;
}
int main(){
	cin>>N;
	cin>>M;
	for(int i=0;i<N;i++)
		scanf("%s", board[i]);
	
	int min=INT_MAX;
	for(int i=0;i<=N-8;i++){
		for(int j=0;j<=M-8;j++){
			clear();
			copy(i,j);
						
			compare(0,0,temp[0][0]);
			if(min>count)
				min=count;
			count=0;
		
		
			clear();
			copy(i,j);
			compare(0,0,!temp[0][0]);
			if(min>count)
				min=count;
			count=0;
		}
	}
	cout<<min;
}
