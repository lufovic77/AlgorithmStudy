#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#define FOR(i,n) for(int i=0;i<n;i++)
typedef unsigned long ul;
using namespace std;
ul hashing(const string key, int num_partitions) { 
     unsigned long hash = 5381; 
     int c;
	 int i=0;
     while ((c = key[i]) != '\0'){
     	hash = hash * 33 + c; 
		i++;
	 }
     return hash % num_partitions; 
}
bool CMP(string a, string b){return a>b;};
pair<int, string> arr[1000002];
int main(){
	int n;
	string name, stat;
	cin>>n;
	ul hash;
	FOR(i,n){
		cin>>name>>stat;
		hash = hashing(name, 1000001);
		if(stat[0] == 'e'){
			arr[hash].first = 1;
			arr[hash].second = name;
		}
		else
			arr[hash].first = 0;
	}
	vector<string> v;
	FOR(i, 1000000){
		if(arr[i].first == 1)
			v.push_back(arr[i].second);
	}
	sort(v.begin(), v.end(), CMP);
	for(auto a: v)
		printf("%s\n", a.c_str());
}
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
