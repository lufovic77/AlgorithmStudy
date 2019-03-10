#include <iostream>
#include <deque>
#include <string>
using namespace std;
int main(){
	int n;
	cin>>n;
	while(n!=0){
		deque<int> dq;
		do {
			dq.push_front(n%2);
			n=n>>1;
		}while(n%2!=0);
		string a;
		for(auto it=dq.begin();it!=dq.end();it++)
		a.push_back(*it+'0');
		cout<<a;
		cout<<std::stoi(a, nullptr, 2)<<endl;
	}
	string a="0110";
}
