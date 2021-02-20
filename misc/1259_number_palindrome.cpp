#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	string a, b;
	while(1){
		cin>>a;
		b = a;
		if(a=="0")
			return 0;
		reverse(a.begin(), a.end());
		if(a==b)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}
}
