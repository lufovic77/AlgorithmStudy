#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#define FOR(i, n) for(int i=0;i<n;i++)
using namespace std;
int main(){
	int t, n,a,b;
	cin>>t;
	while(t--){
		cin>>n;
		int tree[10010];
		fill(tree, tree+10010, 0);
		set<int> l, r;
		FOR(i, n-1){
			cin>>a>>b;
			tree[b] = a;
		}
		cin>>a>>b;
		int index = a;
		while(1){
			l.insert(index);
			index = tree[index];
			if(index == 0)
				break;
		}	
		index = b;
		while(1){
			if(l.find(index)!=l.end()){
				printf("%d\n", index);
				break;
			}
			index = tree[index];
		}	
	}
}
