#include <iostream>
#include <string>
using namespace std;
#define FOR(i, n) for(int i=0;i<n;i++)
int card[4][13];
int num(char c){
	switch(c){
		case 'P':
			return 0;
		case 'K':
			return 1;
		case 'H':
			return 2;
		case'T':
			return 3;
		default:
			return -1;
	}
}
int main(){
	string s;
	cin>>s;
	int index=0;
	while(1){
		char c = s[index];
		int a  = s[index+1] - '0';
		int b = s[index+2] -'0';
		int col = 10*a + b;
		int row = num(c);
		if(card[row][col]==1){
			cout<<"GRESKA";
			return 0;
		}
		else{
			card[row][col] = 1;
		}
		index+=3;
		if(index>=s.length())
			break;
	}
	int ret;
	FOR(i, 4){
		ret = 0;
		FOR(j, 13){
			if(card[i][j]==0)
				ret++;
		}
		cout<<ret<<" ";
	}
}
