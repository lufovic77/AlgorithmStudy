#include <iostream>
#include <vector>
#include <cstdio>
#define FOR(i,n) for(int i=1;i<=n;i++)
using namespace std;
int n;
void permute(int arr[], int ret[], int depth){
	if(depth == n+1){
		FOR(i, n)
			printf("%d ", ret[i]);
		printf("\n");
		return;
	}
	FOR(i, n)
		if(arr[i]==0){
			arr[i] = 1;
			ret[depth] = i;
			permute(arr, ret, depth+1);
			arr[i] = 0;
		}
}
int main(){
	int arr[10], ret[10];
	fill(arr, arr+10,0);
	cin>>n;
	permute(arr, ret,1);
}
