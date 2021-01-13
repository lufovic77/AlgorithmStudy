#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits.h>
#define FOR(i,n) for(int i=0;i<n;i++)
#define FOR2(i,n) for(int i=1;i<=n;i++)
using namespace std;
int mini = INT_MAX;
int sieve[10010];
int visited[10010];
int pm[8] = {1000, 100, 10, 1, -1000, -100, -10, -1};
int canary=0;
void backtrack(int s, int e,int cnt){
	if(s==e){
		mini = min(cnt, mini);
		return ;
	}
	FOR(i, 8){
		for(int j=1;j<=9;j++){
			int news = s+pm[i]*j;
			if(news>=10000 || news<1000)
				break;
			if(news>=1000 && news<10000 && visited[news] == 0 && sieve[news] !=0){
				visited[news] = 1;
				backtrack(news, e, cnt+1);
				visited[news] = 0;
			}
		}
	}
}
int main(){
	FOR2(i, 10010)
		sieve[i] = i;
	for(int i=2; i<sqrt(10010);i++)
		if(sieve[i] !=0 )
			for(int k=pow(i, 2);k<=10010;k+=i)
				sieve[k] = 0;
	int t, a, b;
	cin>>t;
	FOR(i, t){
		scanf("%d%d", &a, &b);
		visited[a] = 1;
		backtrack(a, b, 0);
		if(mini == INT_MAX)
			cout<<"Impossible"<<endl;
		else
			cout<<mini<<endl;
		fill(visited, visited + 10010, 0);
		mini = INT_MAX;
	}
}
