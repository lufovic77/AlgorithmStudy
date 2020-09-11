#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int N, M, K;
int ret = 0;
int main(){
	char map[60][60];
	cin>>N>>M;
	for(int i=0;i<N;i++)
		scanf("%s", map[i]);		
	cin>>K;
	int maxi=0;
	for(int i=0;i<N;i++){
		int cnt=0;
		int cnt2=0;
		for(int k=0;k<M;k++)
		if(map[i][k]=='0')cnt2++;
		
		if(cnt2<=K && K%2 == cnt2%2){
			for(int k=0;k<N;k++){
				if(strcmp(map[i], map[k])==0)
				cnt++;				
			}
		}
		maxi = max(maxi, cnt);
	}	
	cout<<maxi;
}
