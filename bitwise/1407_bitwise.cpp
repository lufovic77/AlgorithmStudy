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
int main(){
	ull a, b, cnt, s, e;
	cin>>a>>b;
	cnt = (b-a)/2+1;
	if(a%2==0 && b%2==0)
		cnt--;
	if(a%2==1)
		s = a+1;
	else
		s = a;
	if(b&2==1)
		e = b-1;
	else 
		e = b;
	for(ull i = s;i<=e;i+=2){
		ull rem, jisu=0, tmp = i;
		while(1){
			rem = tmp%2;
			if(rem == 0)
				jisu++;
			else
				break;
			tmp=tmp>>1;
		}
		cnt+=pow(2, jisu);
	}
	cout<<cnt;
}
