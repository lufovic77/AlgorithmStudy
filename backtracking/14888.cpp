#include <cstdio>
#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#define FOR(i, b) for(int i=0;i<b;i++)
using namespace std;
vector<int> arr;
int maxi = INT_MIN;
int mini = INT_MAX;
void backtrack(int n, vector<int> calc, int ret, int cnt){
	if(cnt == n){
		maxi = max(maxi, ret);
		mini = min(mini, ret);
		return ;
	}
	int op, a, b;
	FOR(i, 4){
		if(calc[i]!=0){
			op = i;
			calc[i]-=1;
		}
		else continue;
		if(cnt ==1){
			a = arr[0];
			b = arr[1];
		}
		else{
			a = ret;
			b = arr[cnt];
		}
		if(op ==0)
			backtrack(n, calc, a+b, cnt+1);
		else if(op ==1)
			backtrack(n, calc, a-b, cnt+1);
		else if(op ==3){
			if(a < 0){
				a *= -1;
				a /= b;
				a *= -1;
			}
			else
				a /=b;
			backtrack(n, calc, a, cnt+1);
		}
		else
			backtrack(n, calc, a*b, cnt+1);
		calc[i]+=1;
	}
}
int main(){
	int n;
	vector<int> calc;
	int tmp;
	cin>>n;
	FOR(i, n){
		scanf("%d", &tmp);
		arr.push_back(tmp);
	}
	FOR(i, 4){
		scanf("%d", &tmp);
		calc.push_back(tmp);
	}
	backtrack(n, calc, 0, 1);
	cout<<maxi<<endl<<mini;
}
