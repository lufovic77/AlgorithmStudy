#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int length;
string s;
int count =0;
bool check(string temp, int len){
	if(len == 1)
	return true;
	char prev = temp[0];
	for(int i=1;i<len;i++){
		if(temp[i]==prev){
			return false;
		}
		prev = temp[i];
	}
	return true;
}
void generate(string temp,int used[], int index){
	if(check(temp, temp.size()) == false){
		return ;
	}
	if(index == length){
		count++;
		cout<<temp<<endl;
		return ;
	}
	for(int i=0;i<length;i++){
		if(used[i]==1)
		continue;
		else{
			string a = s.at(i);
			temp.append(a);
			used[i] = 1;
			generate(temp, used, index+1);
			used[i] = 0;			
		}
	}
	return ;
}
int main(){
	int used[11];
	for(int i=0;i<11;i++)
	used[i] = 0;
	string temp;
	cin>>s;
	length = s.size();
	for(int i=0;i<s.size();i++){
		string a = s.at(i);
		temp.append(a);
		used[i] = 1;
		generate(temp,used, 1);
		used[i] =0;
	}
	cout<<count;
}

