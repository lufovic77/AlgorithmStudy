#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <queue>
#define FOR(i,n) for(int i=0;i<n;i++)
#define FOR2(i,n) for(int i=1;i<=n;i++)
using namespace std;
typedef unsigned long long ull;
int k;
pair<ull, ull> dp1[100]; //alpha = 0;
pair<ull, ull> dp2[100]; // alpha, depth
pair<ull, ull> p;
void recursive(int alpha, int depth){ //0은 A, 1은 B
	if(alpha==0){
		if(dp1[depth].first!=0 || dp1[depth].second!=0){
			p.first+=dp1[depth].first;
			p.second+=dp1[depth].second;
			return ;
		}
	}
	else{
		if(dp2[depth].first!=0||dp2[depth].second!=0){
			p.first+=dp2[depth].first;
			p.second+=dp2[depth].second;
			return ;
		}
	}
	if(depth == k){
		if(alpha == 0)
			p.first +=1;
		else
			p.second+=1;
		return ;
	}

	if(alpha == 0){
		recursive(1, depth+1);
		dp1[depth] = p;
	}
	else{
		recursive(1, depth+1);
		recursive(0, depth+1);
		dp2[depth] = p;
	}
	return;
}
int main(){
	ios::sync_with_stdio(false);//Should not combine iostream with cstdio furthur
	p.first = p.second = 0;
	cin>>k;
	recursive(0, 0); 
	cout<<p.first<<" "<<p.second;
}
