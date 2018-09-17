#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool cmp_length(string& a, string& b){return a.length()<b.length();}
bool cmp_dic(string &a, string& b){return a<b;}
string array[20010];
int main(){
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>array[i];
	}
	sort(array, array+N,cmp_length);
	
	for(int i=0;i<N;i++){
		int temp = array[i].length();
		int start = i, end;
		while(array[i].length() == temp && i<N){
			i++;
			end = i;
		}
		i--;
		sort(array+start, array+end, cmp_dic);
	}
	string temp = array[0];
	for(int i=1;i<N;i++){
		if(temp.compare(array[i])==0) //same
		array[i] = "kyung";
		else{
			temp = array[i];
		} 
	}
	string km = "kyung";
	for(int i=0;i<N;i++){
		if(array[i].compare(km)!=0)
		cout<<array[i]<<endl;
	}
	
}
