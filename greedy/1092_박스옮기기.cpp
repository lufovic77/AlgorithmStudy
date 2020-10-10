#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <algorithm>
#define FOR(i, n) for(int i=0;i<n;i++)
using namespace std;
int main(){
	int n, m, tmp;
	vector<int> crain;
	vector<int> box;
	cin>>n;
	FOR(i, n){
		scanf("%d", &tmp);
		crain.push_back(tmp);
	}
	cin>>m;
	FOR(i, m){
		scanf("%d", &tmp);
		box.push_back(tmp);
	}
	sort(crain.begin(), crain.end(), greater<int>());
	sort(box.begin(), box.end(), greater<int>());
	if(box[0]>crain[0]){
		cout<<"-1";
		return 0;
	}
	int time=0;
	vector<int>::iterator iter, t_iter;
	while(1){
		iter = box.begin();
		for(int i=0;i<n;i++){ //crain
			if(box.empty()){
				cout<<time;
				return 0;
			}
	//		fprintf(stderr, "%d %d\n", *iter, crain[i]);	
			if(*iter <= crain[i]){
				t_iter = iter;
				box.erase(iter);
				if(t_iter==box.end())
					break;
			}
			else{
				if(iter==box.end())
					break;
				iter++;
				i--;
				continue;
			}
		}
		time++;
	}
}
