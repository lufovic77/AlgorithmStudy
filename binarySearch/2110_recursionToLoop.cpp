#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <limits.h>
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;
vector<int> house;
int main(){
	int n, c, tmp;
	cin>>n>>c;
	FOR(i, n){
		scanf("%d", &tmp);
		house.push_back(tmp);
	}
	sort(house.begin(), house.end());
	int l = 1, r = house[house.size()-1], mid, prev, cnt, ret;
	while(l<=r){
		mid = (l+r)/2;
		prev = 0;
		cnt = 1;
		for(int i=1;i<house.size();i++){
			tmp = house[i] - house[prev];
			if(tmp >= mid){
				prev = i;
				cnt++; //pick house to launch device
			}
		}
		if(cnt<c)
			r = mid-1;
		else{	
			ret = mid;
			l = mid+1;
		}
	}		
	cout<<ret;
}

