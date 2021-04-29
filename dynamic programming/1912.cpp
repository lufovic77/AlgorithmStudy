#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	
	int dp[100001];
	int num[100001];
	for(int i=0;i<n;i++)
	cin>>num[i];
	int max = -1001;
	dp[0] = num[0];
	for(int i=1;i<n;i++){
		
		int temp = dp[i-1] + num[i];
		if(temp > num[i]){
			dp[i] = temp;
		}
		else{
			continue;
		}
	}
	for(int i=0;i<n;i++){
		cout<< dp[i]<<endl;
		if(max < dp[i])
		max = dp[i];
	}
	cout<<max;
}
