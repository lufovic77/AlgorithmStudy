#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main(){
	vector<pair<int, int>> v1;
	int N,M;
	cin>>N>>M;
	string temp;
	for(int i=0;i<N;i++){
		cin>>temp;
		if(temp.compare("order")==0){
			int a, b;
			cin>>a>>b;
			v1.push_back(pair<int,int>(b,a));
		//	v1.push_back(make_pair(b,a));
		}
		else if(temp.compare("sort")==0){
			sort(v1.begin(),v1.end());
		}
		else{//complete
			int a;
			cin>>a;
			int temp;
			for(vector<pair<int,int>>::iterator it = v1.begin();it!=v1.end();it++){
				if(it->second==a){
					v1.erase(it);
					break;
				}				
			}
		}
		if(v1.size()==0){
			cout<<"sleep"<<endl;
			continue;
		}
		for(vector<pair<int,int>>::iterator it = v1.begin();it!=v1.end();it++)
		cout<<it->second<<" ";
		cout<<endl;
	}
	return 0;
}
