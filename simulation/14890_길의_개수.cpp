#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <queue>
#define FOR(i,n) for(int i=0;i<n;i++)
#define FOR2(i,n) for(int i=1;i<n;i++)
using namespace std;
int map[110][110];
int main(){
	ios::sync_with_stdio(false);//Should not combine iostream with cstdio furthur
	int n, l, tmp, index = 0, cnt = 0, len = 0;
	cin>>n>>l;
	vector<int> v[2*n+1];
	FOR(i, n){
		FOR(j, n){
			cin>>tmp;
			map[i][j] = tmp;
			v[index].push_back(tmp);
		}
		index++;
	}
	FOR(i, n){
		FOR(j, n){
			v[index].push_back(map[j][i]);
		}
		index++;
	}
	FOR(i, 2*n){
		int prev = v[i][0];
		bool flag = true;
		len = 1;
		FOR2(j, n){ //index 1부터 시작
			if(v[i][j] == prev){
				prev = v[i][j];
				len++;
				continue;
			}
			if(abs(v[i][j]-prev) >= 2){ //경사로의 높이는 1임. 2이상 차이가 나면 그 길은 버림.
				flag = false;
				break;
			}
			if(v[i][j] > prev) {//오르막길
				if(len>=l){
					prev = v[i][j];
					len = 1;
					continue;
				}
				else{
					flag = false;
					break;
				}
			}
			if(v[i][j]<prev){//내리막길
				prev = v[i][j];
				for(int k = 1;k<l;k++){
					if(j+k>=n){//범위를 넘으면
						flag = false;
						break;
					}
					if(v[i][j+k]!=prev){
						flag = false;
						break;
					}
					prev = v[i][j+k];
				}
				if(flag == false)
					break;
				j+=(l-1);
				len = 0;
			}
		}
		if(flag){
			cnt++;
		}
	}
	cout<<cnt;
}
