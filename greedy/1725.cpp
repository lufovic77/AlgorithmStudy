#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool DCR(int a, int b){return a>=b;};
int find(vector<int> input, int height){
	int maxi = -1;
	for(int i=0;i<input.size();i++){
		int len = 1;
		if(input[i] >= height ){
			int l = i-1;
			while(l >= 0){
				if(input[l]>= height){
					len++;
					l--;
				}
				else
					break;
			}
			int r = i+1;
			while(r < input.size()){
				if(input[r]>=height){
					len++;
					r++;
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
		cin>>t;
		input.push_back(t);
		toSort.push_back(t);
	}
	sort(toSort.begin(), toSort.end(), DCR);
	int maxi = -1;
	for(auto a: toSort){
		maxi = max(maxi, find(input, a));
	}
	cout<<maxi;
}
