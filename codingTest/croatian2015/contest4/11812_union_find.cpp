#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int ull;
#define FOR(i, n) for(ull i=0;i<n;i++)
ull uf(ull n, ull x, ull y, ull k){
	ull ret = 0;
	while(1){
		if(x==y)
			return ret;
		if(x>y)
			swap(x, y);
		y = (y+(k-2))/k;
		ret++;
	}
}
int main(){
	ull n, k, q, x, y, ans;
	cin>>n>>k>>q;
	FOR(i, q){
		scanf("%lld%lld", &x, &y);
		if(k==1){
			printf("%lld\n", abs(x-y));
			continue;
		}
		ans = uf(n, x, y, k);
		printf("%lld\n",ans);
	}
}
