#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#define FOR(i,n) for(int i=1;i<=n;i++)
#define gr(x1, x2, y1, y2) (y1-y2)/(x1-x2);
using namespace std;
int main(){
	long long tower[51];
	long long n, tmp, pos, cnt,maxi = -1;
	double grad, con, height;
	cin>>n;
	FOR(i, n){
		cin>>tmp;
		tower[i] = tmp;
	}
	FOR(a, n){
		pos = -1;
		height = -1;
		cnt = 0;
		for(int b = a-1;b>=1;b--){
			grad = (double)(tower[a] - tower[b])/(double)(a-b);
			con = tower[a] - grad*(double)a;
			if (pos == -1)
				cnt++;
			else if(grad*pos + con > height){ //okay
				//cout<<b<<" ";
				cnt++;
			}
			if(tower[b] >= height){
				pos = b;
				height = tower[b];
			}
		}
		pos = -1;
		height = -1;
		for(int b = a+1;b<=n;b++){
			grad = (double)(tower[a] - tower[b])/(double)(a-b);
			con = tower[a] - grad*(double)a;
			if(pos == -1){
				cnt++;
			}
			else if(grad*pos + con > height){ //okay
				//cout<<b<<" ";
				cnt++;
			}
			if(tower[b] >= height){
				pos = b;
				height = tower[b];
			}
		}
		//cout<<cnt<<endl;
		maxi = max(cnt, maxi);
	}
	cout<<maxi;
}
