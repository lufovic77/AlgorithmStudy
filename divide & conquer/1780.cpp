#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
typedef pair<int,int> pint;
//-std=c++11
void divide (vector<int> twoD[],pint s, pint e, int cnt[]){
	int sr = s.first; //start row
	int sc = s.second; //start column
	int er = e.first; //end row
	int ec = e.second; //end column
	int size = (ec-sc+1) * (er-sr+1);
//	cout<< sr<<sc<<er<<ec<<twoD[sr][sc]<<endl;
	if(sr == er & sc == ec){	//only one element
		cnt[twoD[sr][sc]+1] ++;
		return ;
	}
	int total = 0;
	bool flag = true;
	for(int i=sr;i<=er;i++){
		for(int k=sc;k<=ec;k++){
			total += twoD[i][k];
			if (total !=0)
				flag = false;
		}
	}
	if( total == size || total == (-1)*size){ //all zero case
		cnt[twoD[sr][sc]+1] ++;
		return ;
	}
	if(total == 0 & flag){
		cnt[twoD[sr][sc]+1] ++;
		return ;
	}
	else{
		int len = (er-sr+1);
		int offset[3] = {0, len/3, 2*len/3};
		for(int i=0;i<3;i++){
			s.first = sr+offset[i];
			e.first = er-offset[2-i];
			for(int k=0;k<3;k++){
				s.second = sc+offset[k];
				e.second = ec-offset[2-k];
				divide(twoD, s, e, cnt);
			}
		}
		
	}
	return ;
}
int main(){
	int N, temp;
	cin>>N;
	vector <int> twoD [N+1];
	for(int i=1;i<=N;i++)
		twoD[i].push_back(2); //dummy value
	int cnt[3]; //value of -1, 0, 1
	cnt[0] = cnt[1] = cnt[2] = 0;
	for(int i=1;i<=N;i++){
		for(int k=0;k<N;k++){
			scanf("%d", &temp);
			twoD[i].push_back(temp);
		}
	}
	pair<int, int> s;
	pair<int, int> e;
	s.first = s.second = 1;
	e.first = e.second = N;
	divide(twoD, s, e, cnt);
	for(int i=0;i<3;i++)
		cout<<cnt[i]<<endl;
}
