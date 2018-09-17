#include <iostream>
#include <algorithm>
using namespace std;
int dp[1000001];
int divide(int n, int count){
	if(n == 1){	
		return count;
	}//43338, 43339
	if(n<1)
	return 210000000;
	int & ret = dp[n];
	if(ret != 210000000)
	return ret;
	if(n%3==0 && n%2 ==0){
		ret = min(ret, divide(n/3, count+1));
		ret = min(ret, divide(n/2, count+1));
		ret = min(ret, divide(n-1, count+1));
		return ret;
	}
	if(n%3==0){
		ret = min(ret, divide(n/3, count+1));
		ret = min(ret, divide(n-1, count+1));
		return ret;
		
	}
	if(n&2 ==0){
		ret = min(ret, divide(n/2, count+1));
		ret = min(ret, divide(n-1, count+1));
		return ret;
		
	}
	return ret = min(ret, divide(n-1, count+1));	
}
int main(){
	int N;
	cin>>N;
	if(N==1){
		cout<<"0";
		return 0;
	}
	for(int i=1;i<=N;i++)
	dp[i]=210000000;
	divide(N, 0);
	cout<<dp[N];
}
