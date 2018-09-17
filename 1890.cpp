#include <iostream>
using namespace std;
typedef long long ll;
int board[104][104];
ll dp[104][104];
int n;
int count = 0;
ll gogo(int x, int y){
	if(x<0 || x>=n || y<0 || y>=n)
	return 0;
	if(x == n-1 && y==n-1)
	return 1;
	int offset = board[x][y];
	if(offset == 0)
	return 0;
	ll & ret = dp[x][y];
	if(ret !=-1)
	return ret;
	return ret=(gogo(x+offset, y)+gogo(x, y+offset));
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++)
	for(int k=0;k<n;k++)
	cin>>board[i][k];
	
	for(int i=0;i<n;i++)
	for(int k=0;k<n;k++)
	dp[i][k]=-1;
	
	gogo(0,0);
	if(dp[0][0]==-1)
	cout<<"0";
	else
	cout<<dp[0][0];	
}
