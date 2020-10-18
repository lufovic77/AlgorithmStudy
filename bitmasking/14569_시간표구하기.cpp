#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define FOR(i, n) for(int i=0;i<n;i++)
using namespace std;
int stu [10001][51];
vector<int> sub[51];
int main(){
	int n, m, tmp, in;
	cin>>n;
	FOR(i, n){
		scanf("%d", &tmp);
		FOR(j, tmp){
			scanf("%d", &in);
			sub[i].push_back(in);
		}
	}
	cin>>m;
	FOR(i, m){
		scanf("%d", &tmp);
		FOR(j, tmp){
			scanf("%d", &in);
			stu[i][in] = 1;
		}
	}
	int index, total;
	bool flag;
	FOR(i, m){
		total = 0;
		FOR(j, n){
			flag = true;
			for(auto a: sub[j]){
				if(stu[i][a] == 0){
					flag = false;
					break;
				}
			}
			if(flag)
				total++;
		}
		printf("%d\n", total);
	}
}
