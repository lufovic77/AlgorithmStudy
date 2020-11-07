#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define FOR(i, n) for(int i=0;i<n;i++)
using namespace std;
int uf(int n, int x, int y, int k){
	int ret = 0;
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
	int n, k, q, x, y, ans;
	cin>>n>>k>>q;
	FOR(i, q){
		scanf("%d%d", &x, &y);
		ans = uf(n, x, y, k);
		printf("%d\n",ans);
	}
}
