#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#define FOR(i,n) for(int i=1;i<=n;i++)
using namespace std;
int main(){
	int n, k, left, right, mid, tmp;
	cin>>n>>k;
	vector<int> square;
	FOR(i, n)
		square.push_back(pow(i, 2));
	left = 0, right = n-1;
	while(left<=right){
		mid = (left+right)/2;
		tmp = square[mid];
		if(tmp<k)
			left = mid+1;
		else if(tmp>k)
			right = mid-1;
		else{ //mid == k
			cout<<tmp;
			return 0;
		}
	}
	k -= pow(mid, 2);
	vector<int> ret;
	int cnt = k,rocol = mid+1;
	while(1){
		for(int i=1;i<rocol;i++){
			ret.push_back(i*rocol);
			ret.push_back(i*rocol);
			cnt-=2;
		}
		ret.push_back(pow(rocol,2));
		cnt--;
		if(cnt<0)
			break;
	}
	sort(ret.begin(), ret.end());
	cout<<ret[k];
}

