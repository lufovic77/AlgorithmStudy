#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <limits.h>
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;
vector<int> house;
int mini = INT_MIN;
void BS(int l, int r, int c){
	if(l==r){
		mini = max(mini, l);
		return ;
	}
	int mid = (l+r)/2;
	int prev = 0, rem = c-1, ret = INT_MAX;
	for(int i=1;i<house.size();i++){
		int tmp = house[i]-house[prev];
		if(tmp>=mid){
			prev = i;
			ret = min(ret, tmp);
			rem--;
		}
	}
	if(l==r){
		if(rem==0)
			mini = max(mini,ret);
		return ;
	}
	if(rem>0)
		BS(l, mid-1, c);
	else if(rem ==0){
		mini = max(mini, ret);
		return ;
	}
	else{ //suits the case yet not sure it's optimal
		mini = max(mini, ret);
		BS(mid+1, r, c);
	}
	return ;
}
int main(){
	int n, c, tmp;
	cin>>n>>c;
	FOR(i, n){
		scanf("%d", &tmp);
		house.push_back(tmp);
	}
	sort(house.begin(), house.end());
	BS(1, house[house.size()-1]-house[0], c);
	cout<<mini;
}

