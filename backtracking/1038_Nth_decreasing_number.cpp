#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#define FOR(i,n) for(int i=1;i<=n;i++)
using namespace std;
int cnt = 0;
int n;
void backtrack(int prev,int decimal, int index,int number[], int end){
	if(decimal == 0){
		if(cnt == n)
			for(int i=0;i<end;i++)
				cout<<number[i];	
		cnt++;
		return ;
	}
	if(prev == 0) //not done yet
		return ;
	for(int i = 0; i<prev;i++){
		number[index] = i;
		backtrack(i, decimal-1, index+1, number, end);
	}
}

int main(){
	int number[9];
	cin>>n;
	if(n>1021){
		cout<<"-1";
		return 0;
	}
	FOR(i, 9){ //자릿수
		int decimal = i;	
		for(int k=0;k<=9;k++){
			number[0] = k;
			backtrack(k,i-1,1, number, decimal);
		}
	}
}
