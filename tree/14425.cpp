#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#define FOR(i, n) for(int i=0;i<n;i++)
using namespace std;
int main(){
	set <string> tree;
	int n, m, cnt=0;
	string tmp;
	cin>>n>>m;
	FOR(i, n){
		cin>>tmp;
		tree.insert(tmp);
	}
	FOR(i, m){
		cin>>tmp;
		if(tree.find(tmp)!=tree.end())
			cnt++;
	}
	cout<<cnt;
}
