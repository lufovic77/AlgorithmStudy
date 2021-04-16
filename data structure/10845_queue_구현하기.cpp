#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <queue>
#include <string>
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;
string sArr[10] = {"push", "pop", "front", "back", "size", "empty"};
int main(){
	ios::sync_with_stdio(false);//Should not combine iostream with cstdio furthur
	int n;
	string input;
	queue<int> q;
	cin>>n;
	FOR(i, n){
		cin>>input;
		if(input == sArr[0]){ //push
			int num;
			cin>>num;
			q.push(num);
		}
		else if (input == sArr[1]){//pop
			if(!q.empty()){
				cout<<q.front()<<endl;
				q.pop();
			}
			else
				cout<<"-1"<<endl;
		}
		else if (input == sArr[2]){//front
			if(!q.empty())
				cout<<q.front()<<endl;
			else
				cout<<"-1"<<endl;
		}
		else if (input == sArr[3]){//back
			if(!q.empty())
				cout<<q.back()<<endl;
			else
				cout<<"-1"<<endl;
		}
		else if (input == sArr[4])//size
			cout<<q.size()<<endl;
		else if (input == sArr[5]){//empty
			if(q.empty())
			cout<<"1"<<endl;
			else
			cout<<"0"<<endl;
		}
	}
}