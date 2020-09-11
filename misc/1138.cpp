#include <iostream>
#include <list>
using namespace std;
int check [20];
int main(){
	list <int> arr;
	int N;
	cin>>N;
	int temp;
	for (int i=0;i<N;i++){
		cin>>temp;
		arr.push_back(temp);
	}
	int index=1;
	while(!arr.empty()){
		int count = 0;
		for(int i=0;i<N;i++){
			if(count==arr.front() && check[i]==0){
				check[i]=index;
				break;
			}
			if(check[i]!=0) continue;
			else count++;
		}
		arr.pop_front();
		index++;
	}
	for(int i=0;i<N;i++)
	cout<<check[i]<<" ";
} 
/*
5
2 1 0 1 0
*/
