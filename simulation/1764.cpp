#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
unsigned long hashStr(string str){
	unsigned long hash = 5381;
	int c, i;
	i = 0;
	while (c = str[i++])
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
	return hash%700000;
}
int arr[700000];
int main(){
	int n, m;
	cin>>n>>m;
	string tmp1, tmp2;
	for(int i=0;i<n;i++){
		cin>>tmp1;
		arr[hashStr(tmp1)] = 1;
	}
	int index;
	vector <string> ret;
	for(int i=0;i<m;i++){
		cin>>tmp2;
		index = hashStr(tmp2);
		if (arr[index]==1)
			ret.push_back(tmp2);
	}
	sort(ret.begin(), ret.end());
	cout<<ret.size()<<endl;
	for(auto a: ret)
		cout<<a<<endl;
}
