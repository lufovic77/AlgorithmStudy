
/*
 * Using map STL. Time exceeding.
 * Revise with using hash map. 
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdio>
#include <stack>
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;
int main(){
	string name, stat;
	int n;
	cin>>n;
	map<string, bool> m;
	FOR(i,n){
		cin>>name>>stat;
		if(stat == "enter")
			m.insert(make_pair(name, true));
		else
			m.erase(name);
	}
	stack <string> s;
	for(auto it = m.begin(); it!=m.end() ;it++ )
		s.push(it->first);
	while(!s.empty()){
		cout<<s.top()<<endl;
		s.pop();
	}
}
*/
