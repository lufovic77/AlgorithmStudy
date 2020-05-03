#include <iostream>
#include <vector>
//-std=c++11
using namespace std;
void permute(int n, int m, bool flag[], vector<int> ret, int cnt){
	if(cnt>=m){
		for(auto a : ret)
			cout<<a<<" ";
		cout<<endl;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(flag[i]==false){
			flag[i] = true;
			ret.push_back(i);
			permute(n, m, flag, ret, cnt+1);
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
	permute(n, m, flag, ret, 0);
}
