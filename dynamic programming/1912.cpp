#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int dp[100001];
	int num[100001];
	for(int i=0;i<n;i++)
	cin>>num[i];
	int max =-1;
	for(int i=0;i<n;i++){
		if(max<num[i])
		max = num[i];
		dp[i]=num[i];
	}
	
	for(int i=1;i<n;i++){//�̰� offset���� �����ϱ�
		for(int k=0;k<n;k++){  
			if(i+k>=n)
			break;
			dp[k]+=num[k+i];
			if(max<dp[k])
			max = dp[k];
		}
	}
	cout<<max;
}
