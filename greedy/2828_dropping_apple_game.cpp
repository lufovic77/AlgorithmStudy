#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define FOR(i, n) for(int i=0;i<n;i++)
using namespace std;
int main(){
	int n, m, j, tmp, l, r, ret=0;
	cin>>n>>m>>j;
	l = 1, r = m; 
	FOR(i, j){
		cin>>tmp;
		if(l<=tmp && tmp<=r)
			continue;
		if(tmp<l){
			ret += (l-tmp);
			r-=(l-tmp);
			l-=(l-tmp);
		}
		else if(r<tmp){
			ret += (tmp-r);
			l+=(tmp-r);
			r+=(tmp-r);
		}
	}
	cout<<ret;
}
