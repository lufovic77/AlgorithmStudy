#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#define FOR(i, n) for(int i=0;i<n;i++)
using namespace std;
int total = 0;
void permute(string type, int index, vector<char> str, char prev){
	if(index>=type.size()){
		total++; 
		return ;
	}
	if(type[index] == 'c'){
		char tmp;
		FOR(i, 26){
			tmp = 'a' + i;
			if(tmp == prev)
				continue;
			else{
				str.push_back(tmp);
				permute(type, index+1, str, tmp);
			}
		}
	}
	else{
		char tmp;
		FOR(i, 10){
			tmp = '0'+i;
			if(tmp == prev)
				continue;
			else{
				str.push_back(tmp);
				permute(type, index+1, str, tmp);
			}
		}
	}
	return ;
}
int main(){
	string input;
	cin>>input;
	vector <char> str;
	permute(input, 0, str, '?');
	cout<<total;
}
