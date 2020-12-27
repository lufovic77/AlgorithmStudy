#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;
int remote[10];
int cnt, n;
int button[8];
void backtrack(int index, int length, bool flag){
	if(index == length){
		bool chk = true;
		int tmp = 0, len= 0;
		for(int i=0;i<length;i++){
			if(button[i]!=0)
				chk = false;
			if(!chk)
				len++;
			tmp +=pow(10, length-i-1)*button[i];
		}
		if(tmp == n)
			tmp = len;
		else
			tmp = abs(tmp-n)+len;
		cnt = min(cnt, tmp);
		return ;
	}
	FOR(i, 10){
		if(i!=0)
			flag = false;
		if(remote[i] == 1 || (i==0 && flag)){
			button[index] = i;
			backtrack(index+1, length, flag);
		}
	}
	return ;
}
int main(){
	fill(remote, remote+10, 1);
	int m,tmp, len;
	fill(button, button+8, 0);
	cin>>n>>m;
	len = (int)(log10(n)+1); //how to get the number of digits
	if(n == 0)
		len = 1;
	FOR(i, m){
		cin>>tmp;
		remote[tmp] = 0;
	}
	cnt = abs(n-100);
	if(m==0){
		cout<<min(len,cnt);
		return 0;
	}
	backtrack(0, len+1, true);
	cout<<cnt;
}
