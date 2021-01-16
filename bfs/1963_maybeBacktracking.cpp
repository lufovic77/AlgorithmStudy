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
int sieve[10010];
int visited[10010];
int pl[4] = {1000, 100, 10, 1};
int mi[4] = {-1000, -100, -10, -1};
int main(){
	FOR2(i, 10010)
		sieve[i] = i;
	for(int i=2; i<sqrt(10010);i++)
		if(sieve[i] !=0 )
			for(int k=pow(i, 2);k<=10010;k+=i)
				sieve[k] = 0;
	int t, a, b, tmp, cnt = 0, mini = INT_MAX, iter, total;
	queue<int> q;
	cin>>t;
	FOR(i, t){
		bool flag = false;
		scanf("%d%d", &a, &b);
		cnt = 1, mini = INT_MAX, total = 0;
		q.push(a);
		fill(visited, visited+10010, 0);
		while(!q.empty()){ //bfs
			iter=0;
			FOR(index, cnt){
				tmp = q.front();
				if(tmp == b){	
					flag = true;
					printf("%d\n", total);
					while(!q.empty())
						q.pop();  //initialize
					break;
				}
				q.pop();
				int deci, shift;
				shift = tmp;
				FOR(m, 4){
					deci = shift/pow(10, 3-m);
					shift -= deci*pow(10, 3-m);
					for(int j=1;j<=9-deci;j++){
						int news = tmp+pl[m]*j;
						if(news>=1000 && news<10000 &&visited[news]==0 && sieve[news] !=0){
							visited[news] = 1;
							q.push(news);
							iter++;
						}
					}
				}
				shift = tmp;
				FOR(m, 4){
					deci = shift/pow(10, 3-m);
					shift -= deci*pow(10, 3-m);
					for(int j=deci;j>=1;j--){
						int news = tmp+mi[m]*j;
						if(news>=1000 && news<10000 &&visited[news]==0 && sieve[news] !=0){
							visited[news] = 1;
							q.push(news);
							iter++;
						}
					}
				}
			}
			cnt = iter;
			total++;
		}
		if(!flag)
			cout<<"Impossible"<<endl;
	}
}
