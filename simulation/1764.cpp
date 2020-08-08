#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int main(){
	int n, m;
	cin>>n>>m;
	string tmp1, tmp2;
	set <string> s;
	for(int i=0;i<n;i++){
		cin>>tmp1;
		s.insert(tmp1);
	}
	vector <string> ret;
	for(int i=0;i<m;i++){
		cin>>tmp2;
		auto a = s.find(tmp2);
		if (a!=s.end())
			ret.push_back(tmp2);
	}
	sort(ret.begin(), ret.end());
	cout<<ret.size()<<endl;
	for(auto a: ret)
		cout<<a<<endl;
}
