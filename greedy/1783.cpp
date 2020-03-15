#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;
int N, M;
int moveX[4] = {-2, 1, -1, 2};
int moveY[4] = { 1, 2,  2, 1};
int chess(int posX, int posY, vector <bool> &flag,int count, int type){
	int ans = -1;
	int fail = false;
	for(int i=0;i<4;i++){
		int newX = posX+moveX[i];
		int newY = posY+moveY[i];
		if(newX <M && newY<N && newX>=0 && newY>0){
			flag[i] = true;
			ans = max(ans, chess(newX, newY, flag, count+1, i));
			fail = true;
		}
	}
	if(fail == false){
		if(count>=4){
			for(int i=0;i<4;i++){
				if(flag[i] == false){
					return -1;
				}			
			}
			return count;
		}
		else{
			return count;		
		}
	}	
	return ans;
}
int main(){
	cin>>M>>N;
	vector <bool> flag;
	for(int i=0;i<4;i++)
		flag.push_back(false);
	int curX = M-1;
	int curY = 0;
	int	ans = max(ans, chess(curX ,curY, flag, 1, -1));
	if (ans ==-1)
		cout<<"1";
	else
		cout<<ans;
}
