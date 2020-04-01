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
	int size = (ec-sc) * (er-sr);
//	cout<< sr<<sc<<er<<ec<<twoD[sr][sc]<<endl;
	if(size == 0){	//only one element
		cnt[twoD[sr][sc]+1] ++;
		return ;
	}
	int total = 0;
	for(int i=sr;i<=er;i++){
		for(int k=sc;k<=ec;k++)
			total += twoD[i][k];		
	}
	if(total == 0|| total == size || total == (-1)*size){ //all zero case
		cnt[twoD[sr][sc]+1] ++;
		return ;}
	else{
		int r = (sr+er);
		int c = (sc+ec);
		int row[3] = [r/3, r/3, 2*r/3, r];
		int col[3] = [];
		
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
		cout<<cnt[i]<<" ";
}
