#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n;

	int dp[100001];
	int num[100001];
	for(int i=0;i<n;i++)
	cin>>num[i];
	if(n == 1){
		cout<<num[0];
		return 0;
	}
	if(num[0]<0){
		dp[0] = 0;
	}
	else{
		dp[0] = num[0];
	}
	int max = num[0];

	for(int i=1;i<n;i++){
		
		int temp = dp[i-1] + num[i];
		if(num[i] > 0){
			dp[i] = temp;
			if (temp > max)
			max = temp;
		}
		else{
			continue;
		}
	}
	cout << max;
}
