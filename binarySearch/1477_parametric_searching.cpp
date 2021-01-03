#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <queue>
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;
int main(){
	int n, m, l, tmp, ret;
	vector<int> pos;
	cin>>n>>m>>l;
	FOR(i, n){
		scanf("%d", &tmp);
		pos.push_back(tmp);
	}
	sort(pos.begin(), pos.end());
	int low=1, high = l;
	while(low<=high){
		int mid = (low+high)/2;
		int built = 0;
		if(mid < pos[0])
			built++;
		if(pos[n-1] + mid <l)
			built++;
		FOR(i, n-1){
			built+=(pos[i+1] - pos[i]-1)/mid;
		}
		if(built > m)
			low = mid+1;
		else if (built<=m){
			high = mid-1;
			ret = min(ret, mid);
		}
	}
	cout<<ret;
}
