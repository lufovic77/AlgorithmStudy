#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
// -std=c++11
bool DCR(int a, int b){return a>=b;};
int traverse(vector<int> input, int height){
	int maxi = -1;

	bool flag[1000001];
	fill(flag, flag+1000001,false);
	for(int i=0;i<input.size();i++){
		int len = 1;
		if(input[i] >= height ){
			if(flag[i])
				continue;
			int l = i-1;
			while(l >= 0){
				if(input[l]>= height){
					len++;
					l--;
					flag[l] = true;
				}
				else
					break;
			}
			int r = i+1;
			while(r < input.size()){
				if(input[r]>=height){
					len++;
					r++;
					flag[l] = true;
				}
				else
					break;
			}
		}
		maxi = max(maxi, len*height);
	}
	return maxi;
}
int main(){
	int N;
	cin>>N;
	vector <int> input;
	vector <int> toSort;
	int t;
	for(int i=0;i<N;i++){
		scanf("%d", &t);
		input.push_back(t);
		toSort.push_back(t);
	}
	sort(toSort.begin(), toSort.end(), DCR);
	int maxi = -1;
	for(auto a: toSort){
		maxi = max(maxi, traverse(input, a));
	}
	cout<<maxi;
}
