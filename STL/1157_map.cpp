#include <iostream>
#include <map>
#include <string>
#include <ctype.h>
#include <algorithm>
using namespace std;
int main(){
	string input;
	map<char, int> m1;
	map<char, int>::iterator it1;
	cin>>input;
	
	for(int i=0;i<input.size();i++){
		if(islower(input[i]))
		input[i]=toupper(input[i]); //to uppercase
		m1.insert(make_pair(input[i],0));
	}
	int maxi = -1;
	for(int i=0;i<input.size();i++){
		char ch = input.at(i);
		auto it = m1.find(ch);
		maxi = max(maxi,++it->second);
	}
	int count =0;
	char temp;
	for(auto it=m1.begin();it!=m1.end();it++){
		if(maxi == it->second){
			temp = it->first;
			count++;
		}
		if(count>1){
			cout<<"?";
			return 0;
		}	
	}
	cout<<temp;		
}
