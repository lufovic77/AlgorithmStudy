#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#define FOR(i, n) for(int i=0;i<n;i++)
using namespace std;
int main(){
	multimap <int, int > mm; //first height, second position
	multimap <int, int> ::iterator it;
	int n, tmp, max = -1, ret=0;
	mm.insert(make_pair(-1, -1));
	cin>>n;
	FOR(i, n){
		scanf("%d", &tmp);
		if(tmp>max || mm.find(tmp+1)==mm.end()){
			if(tmp>max)
				max = tmp;
			ret++;
			mm.insert(make_pair(tmp,i));
			continue;
		}
		it = mm.lower_bound(tmp+1);
		int pos = it->second;
		mm.erase(it);
		mm.insert(make_pair(tmp, pos));
	}
	cout<<ret;
}
