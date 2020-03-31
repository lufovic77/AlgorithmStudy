#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
typedef pair<int,int> pint;
//-std=c++11
int* divide (vector<int> twoD[],pint s, pint e, int cnt[]){
}
int main(){
	int N, temp;
	cin>>N;
	vector <int> twoD [N];
	for(int i=0;i<N;i++)
		twoD[i].push_back(2); //dummy value
	int cnt[3];
	cnt[0] = cnt[1] = cnt[2] = 0;
	for(int i=0;i<N;i++){
		for(int k=0;k<N;k++){
			scanf("%d", &temp);
			twoD[i].push_back(temp);
		}
	}
	int* ret;
	pair<int, int> s;
	pair<int, int> e;
	s.first = s.second = 1;
	e.first = e.second = N;
	ret = divide(twoD, s, e, cnt);
}
