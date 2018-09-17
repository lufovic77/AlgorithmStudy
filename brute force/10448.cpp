#include <cstdio>
#include <iostream>
using namespace std;

int triNum[1100];
int find(int num){
	for(int a=1;a<num;a++){
		for(int b=a;b<num;b++){
			for(int c=b;c<num;c++){
				if((triNum[a]+triNum[b]+triNum[c])==num)	
				return 1;
			}
		}
	}
	return 0;
}
int main(){
	for (int i=1;i<=1000;i++){
		triNum[i]=i*(i+1)/2;
	}
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int num;
		cin>>num;
		int answer = find(num);
		cout<<answer<<endl;
	}
}
