#include <iostream>
#include <cstdio>
using namespace std;

int board[65][65];
bool check(int x1,int y1, int x2, int y2){
	int temp = board[x1][y1];
	for(int i=x1;i<=x2;i++){
		for(int k=y1;k<=y2;k++){
			if(board[i][k]!=temp){
				return false;
			}
		}
	}
	if(temp ==0)
	cout<<"0";
	else
	cout<<"1";
	return true;
}
void daq(int x1,int y1, int x2, int y2){
	if(x1==x2 && y1==y2){
		if(board[x1][y1]==0)
			cout<<"0";
		else
			cout<<"1";
		return ;
	}
	bool flag = check(x1, y1, x2, y2);
	if(!flag){	//	all
		cout<<"(";
		int halfX = (x1+x2)/2;
		int halfY = (y1+y2)/2;
		
		daq(x1, y1, halfX, halfY);
		daq(x1,halfY+1,halfX , y2);
		daq(halfX+1, y1, x2, halfY);
		daq(halfX+1, halfY+1, x2, y2);		
		cout<<")";
	}
	return ;
}
int main(){
	int N;
	cin>>N;
	for(int i=1;i<=N;i++)
	for(int k=1;k<=N;k++)
	scanf("%1d", &board[i][k]);
	daq(1,1, N,N);
	return 0;	
}
