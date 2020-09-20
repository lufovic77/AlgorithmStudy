#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>
#define FOR(i, n) for(int i=0;i<n;i++)
using namespace std;
int main(){
	vector<char> ans;
	vector<int> seq;
	stack<int> s;
	int n, tmp, element = 2, index=0;
	cin>>n;
	FOR(i, n){
		scanf("%d", &tmp);
		seq.push_back(tmp);
	}
	for(element=1;element<=n;element++){
		s.push(element);
		ans.push_back('+');
		while(s.top()>=seq[index]){
			if(s.top()==seq[index])
				index++;
			s.pop();
			ans.push_back('-');
			if(s.empty())
				break;
		}
	}
	if(index <n){
		cout<<"NO";
		return 0;
	}
	for(auto a: ans){
		printf("%c\n", a);
	}
	return 0;
}
