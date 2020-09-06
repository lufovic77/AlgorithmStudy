#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>
#define FOR(i, n) for(int i=1;i<=n;i++)
using namespace std;
int arr[2000];
vector<int> node [15];
void recursion(int l, int r, int depth){
	int tl, tr, mid = (l+r)/2; 
	node[depth].push_back(arr[mid]);
	if(l==r)
		return ;
	recursion(l, mid-1, depth+1);
	recursion(mid+1, r, depth+1);
}
int main(){
	int k,tmp, depth = 0, l,r, num;
	cin>>k;
	num = pow(2, k)-1;
	fill(arr, arr+2000, 0);
	FOR(i, num){
		cin>>tmp;
		arr[i] = tmp;
	}
	l = 1;
	r = num;
	recursion(l, r, depth);
	for(int i=0;i<k;i++){
		for(auto a:node [i])
			cout<<a<<" ";
		printf("\n");
	}
}
