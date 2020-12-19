#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;
int main(){
	int a, b, constant;
	vector<pair<int, int> > pos;
	FOR(i, 3){
		cin>>a>>b;
		pos.push_back(make_pair(a, b));
	}
	float grad1, grad2;
	if(pos[1].first != pos[0].first && pos[2].first!=pos[1].first){
		grad2 = (float)((pos[2].second - pos[1].second) / (pos[2].first - pos[1].first));
		grad1 = (float)((pos[1].second - pos[0].second) / (pos[1].first - pos[0].first));
	}
	else{
		if(pos[1].first == pos[0].first)
			grad1 = 0;
		if(pos[1].first == pos[2].first)
			grad2 = 0;
	}
	if(grad1 == grad2){
		cout<< 0;
		return 0;
	}
	constant = pos[0].second - pos[0].first*grad1;
	if(pos[0].first<pos[1].first){
		if(constant + grad1*pos[2].first >pos[2].second)
			cout<<"-1";
		else
			cout<<"1";
	}
	else if (pos[0].first>pos[1].first){
		if(constant + grad1*pos[2].first >pos[2].second )
			cout<<"-1";
		else
			cout<<"1";
	}
	else{ //vertical
		if(pos[1].second > pos[0].second){
			if(pos[2].first >pos[1].first )
				cout<<"-1";
			else
				cout<<"1";
		}
		else{
			if(pos[2].first > pos[1].first)
				cout<<"1";
			else
				cout<<"-1";
		}
	}
}

