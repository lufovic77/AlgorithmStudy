#include <iostream>
#include <cstdio>
#include <vector>
//-std=c++11
//Time exceeds with iostream 
//cout<<endl; is fucxing slow
using namespace std;
void permute(int n, int m, vector<int> ret, int cur,int cnt){
	if(cnt>=m){
		for(auto a : ret)
			cout<<a<<" ";
		printf("\n");
		return ;
	}
	for(int i=cur;i<=n;i++){
			ret.push_back(i);
			permute(n, m, ret,i, cnt+1);
			ret.pop_back();
	}
}
int main(){
	int n, m;
	cin>>n>>m;
	vector <int> ret;
	permute(n, m,ret,1, 0);
}
