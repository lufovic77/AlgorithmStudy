#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;
float sum = 0, cnt = 0;
int number[10][5][3] = {
	{{1,1,1},
	 {1,0,1},
	 {1,0,1},
	 {1,0,1},
	 {1,1,1}},
	{{0,0,1},
	 {0,0,1},
	 {0,0,1},
	 {0,0,1},
	 {0,0,1}},
	{{1,1,1},
	 {0,0,1},
	 {1,1,1},
	 {1,0,0},
	 {1,1,1}},
	{{1,1,1},
	 {0,0,1},
	 {1,1,1},
	 {0,0,1},
	 {1,1,1}},
	{{1,0,1},
	 {1,0,1},
	 {1,1,1},
	 {0,0,1},
	 {0,0,1}},
	{{1,1,1},
	 {1,0,0},
	 {1,1,1},
	 {0,0,1},
	 {1,1,1}},
	{{1,1,1},
	 {1,0,0},
	 {1,1,1},
	 {1,0,1},
	 {1,1,1}},
	{{1,1,1},
	 {0,0,1},
	 {0,0,1},
	 {0,0,1},
	 {0,0,1}},
	{{1,1,1},
	 {1,0,1},
	 {1,1,1},
	 {1,0,1},
	 {1,1,1}},
	{{1,1,1},
	 {1,0,1},
	 {1,1,1},
	 {0,0,1},
	 {1,1,1}}
};
vector <int> possible[10];
void backtrack(int index, int partial, int end){
	if(index == end){
		sum+=partial;
		cnt+=1;
		return ;
	}
	for(auto a: possible[index])
		backtrack(index+1, partial+pow(10, end-index-1)*a, end);
}
int main(){
	int n;
	string tmp;
	cin>>n;
	int input[5][4*n];
	FOR(i, 5){
		cin>>tmp;	
		FOR(j, 4*n-1){
			if(tmp[j]=='#')
				input[i][j] = 1;
			else
				input[i][j] = 0;
			}
	}	
	for(int i=0;i<n;i++){
		int s = 4*i;
		for(int k = 0;k<10;k++){ //number
			bool flag = true;
			for(int r = 0;r<5;r++){
				int index = s;
				for(int c = 0;c<3;c++, index++){
					if(number[k][r][c]==0 && input[r][index]==1){
							flag = false;
							break;
					}
				}
				if(!flag)
					break;
			}
			if(flag)
				possible[i].push_back(k);
		}
	}
	bool empty = true;
	FOR(i, n){
		if(!possible[i].empty()){
			empty = false;
			break;
		}
	}
	if(empty){
		cout<<"-1";
		return 0;
	}
	backtrack(0,0,n);
	printf("%.7f", sum/cnt);
}
