#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string>
using namespace std;
int length;

int parsing(string & chemi, int count){
	char first = chemi.at(0);
	if(first==')'){
		cout<<"hello";
		exit(0);
	}
	if(first=='('){
		string temp = chemi.substr(1);
		return parsing(temp, count+1);
	}
	 
	if(first == 'H'){
		if(count+1<length){
			if(isdigit(chemi.at(1))){		
				if(count+2 == length){
					return atoi(&chemi.at(1));
				}	
				string temp = chemi.substr(2);
				return atoi(&chemi.at(1))+parsing(temp, count+2);
			}
		}
		if(count+1 == length){
			return 1;
		}
		string temp = chemi.substr(1);
		return 1+parsing(temp, count+1);
		
	}
	else if(first == 'C'){
		if(count+1<length){
			if(isdigit(chemi.at(1))){
				if(count+2 == length){
					return 12*atoi(&chemi.at(1));
				}	
				string temp = chemi.substr(2);
				return 12*atoi(&chemi.at(1))+parsing(temp, count+2);
			}
		}
		if(count+1 == length){
			return 12;
		}
		string temp = chemi.substr(1);
		return 12+parsing(temp, count+1);
		
	}
	else{	//O case
		if( count+1<length ){
			if( isdigit(chemi.at(1))){
				if(count+2 == length){
					return 16*atoi(&chemi.at(1));
				}	
				string temp = chemi.substr(2);
				return 16*atoi(&chemi.at(1))+parsing(temp, count+2);
			}
		}
		if(count+1 == length){
			return 16;
		}
		string temp = chemi.substr(1);
		return 16+parsing(temp, count+1);
		
	}	
}

int main(){
	string chemi;
	cin>>chemi;
	length = chemi.size();
	int total = 0;
	cout<<parsing(chemi,0);
}
