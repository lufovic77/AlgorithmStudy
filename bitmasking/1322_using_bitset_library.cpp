#include <iostream>
#include <cstdio>
#include <bitset>
#include <vector>
#include <algorithm>
#define FOR(i, n) for(int i=0;i<n;i++)
using namespace std;
typedef bitset<50> BTS;
typedef unsigned long long ull;
int main(){
	BTS tmp;
 	ull x, y, t, add, k,cnt=0;
	cin>>x;
	cin>>k;
	y = 0;
	while(cnt<k){
		y++;
		t = y & x;
		t = ~t;
		tmp = t;
		if(tmp.all()) //is all bit 1?
			cnt++;
	}
	cout<<y;
}
