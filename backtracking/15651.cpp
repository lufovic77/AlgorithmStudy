#include <iostream>
#include <cstdio>
#include <vector>
//-std=c++11
//Time exceeds with iostream 
//cout<<endl; is fucxing slow
using namespace std;
void permute(int n, int m, vector<int> ret, int cnt){
	if(cnt>=m){
		for(auto a : ret)
			cout<<a<<" ";
		printf("\n");
		return ;
	}
	for(int i=1;i<=n;i++){
			ret.push_back(i);
			permute(n, m, ret, cnt+1);
			ret.pop_back();
	}
}
int main(){
	int n, m;
	cin>>n>>m;
	vector <int> ret;
	permute(n, m,ret, 0);
}
