#include <iostream>
#include <cstdio>
#include <vector>
//-std=c++11
//Time exceeds with iostream 
//cout<<endl; is fucxing slow
using namespace std;
void permute(int n, int m, bool flag[], vector<int> ret, int cnt, int cri){
	if(cnt>=m){
		for(auto a : ret)
			cout<<a<<" ";
		printf("\n");
		return ;
	}
	for(int i=cri;i<=n;i++){
		if(flag[i]==false){
			flag[i] = true;
			ret.push_back(i);
			permute(n, m, flag, ret, cnt+1, i);
			flag[i] = false;
			ret.pop_back();
		}
	}
}
int main(){
	int n, m;
	cin>>n>>m;
	bool flag[10];
	fill(flag, flag+10, false);
	vector <int> ret;
	permute(n, m, flag, ret, 0, 1);
}
