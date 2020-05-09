#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;
#define FOR(i, k) for(int i=1;i<=k;i++)
int ability[22][22];
int n;
int mini = INT_MAX;
void backtrack(bool flag[],int cur, int cnt){
	if(cnt == n/2){
		vector <int> start;
		vector <int> link;
		start.push_back(0);
		link.push_back(0);
		FOR(i, n){
			if(flag[i])
				start.push_back(i);
			else
				link.push_back(i);
		}
		int stotal=0, ltotal=0, t1,i1, i2;
			FOR(a, start.size()){
				FOR(b, start.size()){
					if(a==b)
						continue;
					i1 = start[a];
					i2 = start[b];
					t1 = ability[i1][i2];
					stotal+=(t1);
				}
			}
			FOR(a, link.size()){
				FOR(b, link.size()){
					if(a==b)
						continue;
					i1 = link[a];
					i2 = link[b];
					t1 = ability[i1][i2];
					ltotal+=(t1);
				}
			}
			mini = min(mini, abs(stotal-ltotal));
		return ;
	}
	for(int i=cur;i<=n;i++){
		if(!flag[i]){	
			flag[i] = true;
			backtrack(flag,i,cnt+1);
			flag[i] = false;
		}
	}
	return ;
}
int main(){
	int tmp;
	cin >> n;
	FOR(i, n)
		FOR(j, n){
			scanf("%d",&tmp);
			ability[i][j] = tmp;
		}
	bool flag[22];
	fill(flag, flag+21, false);
	flag[1] = true;
	backtrack(flag,2, 1);
	cout<<mini;
}
