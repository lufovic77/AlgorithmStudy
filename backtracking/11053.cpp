#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;
int maxi = INT_MIN;
int n;
vector <int> arr;
void backtrack(int index,int len,int cur){
	if(index == n){
		maxi = max(maxi, len);
		return ;
	}
	if(arr[index] > cur){
		backtrack(index+1, len+1, arr[index]);
	}
	backtrack(index+1, len, cur);
	return ;
}
int main(){
	int tmp;
	cin>>n;
	FOR(i, n){
		cin>>tmp;
		arr.push_back(tmp);
	}
	backtrack(0,0,-1);
	cout<<maxi;
}
