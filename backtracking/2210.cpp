#include <iostream>
#include <string>
using namespace std;
int map[6][6];
int check[1000000];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
void start(int x, int y, string temp,int count){
	if(x<0 || y<0 || x>=5 || y>=5)
	return ;
	if(count ==6){
		int a = stoi(temp);
		check[a]=1;
		return;
		//convert string to integer
	}
	for(int i=0;i<4;i++){
		int newx = x+dx[i];
		int newy = y+dy[i];
		
		temp.push_back(map[newx][newy]);
		start(newx, newy, temp, count+1);
		temp.pop_back();
	}
	
}
int main(){
	for(int i=0;i<5;i++){
		for(int k=0;k<5;k++){
			cin>>map[i][k];
		}
	}
	for(int i=0;i<5;i++){
		for(int k=0;k<5;k++){
			string temp;
			temp.push_back(map[i][k]);
			start(i,k,temp, 1);
		}
	}
	
}
