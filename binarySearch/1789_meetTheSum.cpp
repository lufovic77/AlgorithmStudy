#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef unsigned long long ull;
int main(){
	ull s, left, right, mid, cnt, sub, ret, tmp;
	cin>>s;
	right = (int)sqrt(2*s);
	left = 1;
	ret = 0; //can't be -1. If set, it is transformed to very high number due to overflow. 
	while(left <= right){
		mid = (left+right)/2;
		tmp = s;
		cnt = mid; //개수
		sub = 1;
		while(cnt>1){
			tmp-=sub;
			sub++;
			cnt--;	
		}
		if(tmp<=0)
			right = mid-1;
		else if(tmp>0){
			if(tmp>=sub)
				ret = max(ret, mid);
			left = mid+1;	
		}
	}
	cout<<ret;	
}

