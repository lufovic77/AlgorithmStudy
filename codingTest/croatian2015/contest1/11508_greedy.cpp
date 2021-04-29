#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define FOR(i, n) for(int i=0;i<n;i++)
using namespace std;
int main(){
	int n, in;
	cin>>n;
	vector<int> v;
	FOR(i, n){
		scanf("%d", &in);
		v.push_back(in);
	}
	sort(v.begin(), v.end(), greater<int>());
	in = 0;
	int len = v.size();
	if(len==1){
		cout<<v[in];
		return 0;
	}
	if(len==2){
		cout<<v[in]+v[in+1];
		return 0;
	}
	int ret = 0;
	while(1){
		if(in%3 !=2 ){
			ret+=v[in++];
			if(in>=len)
				break;
		}
		else
			in++;
	}
	cout<<ret;
}
