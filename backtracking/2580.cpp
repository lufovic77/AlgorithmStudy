#include <iostream>
#include <cstdio>
#include <vector>
#include <stdlib.h>
using namespace std;
typedef struct{
	int x;
	int y;
}POS;
int len;
vector <POS> q;
bool check(int x, int y, int num, int map[][10]){
	//사각형 체크
	int a = x/3;
	int b = y/3;
	a *=3;
	b *=3;
	
	for(int i=a;i<a+3;i++){
		for(int j=b;j<b+3;j++){
			if(i == x && j == y){
			continue;
			}
			if(map[i][j]==num){
				return false;
			}		
		}
	}
	//가로 / 세로 체크 
	for(int i=0;i<9;i++){
		if( i ==y)
		continue;
		if(num == map[x][i])
		return false;
	}
	for(int i=0;i<9;i++){
		if( i ==x)
		continue;
		if( num == map[i][y])
			return false;
	}
	return true;
}
void backtracking(int map[][10],int index){
	if(index>=len){
		cout<<endl;
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++)
			cout<<map[i][j]<<" ";
			cout<<endl;
		}
		exit(0);
		return ;
	}
	POS temp ;
	temp = q[index];
	int a = temp.x;
	int b = temp.y;
	int flag = 0;
	for(int i=1;i<=9;i++){
		map[a][b] = i;
		if(check(a, b, i, map)==true){
			flag =1;
			backtracking(map,index+1);
			map[a][b]=0;
			
		}
		else{
			map[a][b]=0;
			continue;
		}
	}
	return ;
	
}
int main(){
	int a;
	int map[10][10];
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			cin>>a;
			if(a == 0){
				POS temp ;
				temp.x = i;
				temp.y = j;
				q.push_back(temp);
			}
			map[i][j] = a;
		}
	}
	len = q.size();
	backtracking(map,0);
}
