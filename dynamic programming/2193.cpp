#include <iostream>
using namespace std;
typedef long long ll;
ll dp[2][100];
ll recursive(int prev, int left){
	if(left == 1)
	return 1;
	ll & ret = dp[prev][left];
	if(ret != 0)
	return ret;
	if(prev == 1)
	return ret = recursive(0,left -1);
	else
	return ret = recursive(0,left -1)+recursive(1,left-1);
}
int main(){
	int n;
	cin>>n;
	ll answer = recursive(1, n);
	cout<<answer;
}
