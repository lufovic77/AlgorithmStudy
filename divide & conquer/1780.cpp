#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
//-std=c++11
int divide (vector<int> twoD[],int s, int e, int cnt[]){
	int size = e-s;
	int ret = 0;
	for(int i=0;i<size;i++){
		for(auto a : twoD[i])	//change here
			ret+=a;
	}
	if(ret == 0){
		cnt[1] ++;
		return cnt;
	}
	else if(ret == size*size){
		cnt[2] ++;
		return cnt;
	}
	else if(ret == (-1)*size*size ){
		cnt[0] ++;
		return cnt;
	}
	else{
		

	}
}
int main(){
	int N, temp;
	cin>>N;
	std::vector <int> twoD [N];
	int cnt[3];
	cnt[0] = cnt[1] = cnt[2] = 0;
	for(int i=0;i<N;i++){
		for(int k=0;k<N;k++){
			scanf("%d", &temp);
			twoD[i].push_back(temp);
		}
	}
	int* ret;
	ret = divide(twoD, N, cnt);
}
