#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;
int remote[10];
int cnt, n;
void backtrack(int index, int length, int button[]){
	if(index == length){
		int tmp = 0;
		for(int i=0;i<length;i++)
			tmp +=pow(10, length-i-1)*button[i];
		tmp = abs(tmp-n)+length;
		cnt = min(cnt, tmp);
		return ;
	}
	FOR(i, 10)
		if(remote[i] == 1){
			button[index] = i;
			backtrack(index+1, length, button);
		}
	return ;
}
int main(){
	fill(remote, remote+10, 1);
	int m,tmp, len;
	int button[10];
	cin>>n>>m;
	len = (int)(log10(n)+1); //how to get the number of digits
	FOR(i, m){
		cin>>tmp;
		remote[tmp] = 0;
	}
	cnt = abs(n-100);
	backtrack(0, len,button);
	cout<<cnt;
}
