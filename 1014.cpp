#include <iostream>
#include <cstdio>
using namespace std;
int map[15][15];
void clean(){
	for(int i=0;i<15;i++){
		for(int j=0;j<15;j++){
			map[i][j]=0;
		}
	}
}
int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		clean();
		int n,m;
		cin>>n>>m;
		for(int a=0;a<n;a++){
			for(int b=0;b<m;b++){
				int dot;
				scanf("%d", &dot);
				if(dot == '.'){
					cout<<"?";
				}
				else{	//can't sit
					cout<<"!";
				}
			}
		}	
	}
}
