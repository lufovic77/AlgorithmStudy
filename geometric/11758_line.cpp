#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#define FOR(i,n) for(int i=0;i<n;i++)
#define EPSILON 0.000001
using namespace std;
int main(){
	float a, b, constant;
	vector<pair<float, float> > pos;
	FOR(i, 3){
		cin>>a>>b;
		pos.push_back(make_pair(a, b));
	}
	float grad1, grad2;
	if(pos[1].first != pos[0].first)
		grad1 = ((pos[1].second - pos[0].second) / (pos[1].first - pos[0].first));
	else
		grad1 = 0;

	if(pos[2].first != pos[1].first)
		grad2 = ((pos[2].second - pos[1].second) / (pos[2].first - pos[1].first));
	else
		grad2 = 0;
	if(abs(grad1-grad2) < EPSILON){
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

