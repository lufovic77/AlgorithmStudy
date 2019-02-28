#include <iostream>
#include <cstdio>
using namespace std;
int mapA[60][60];
int mapB[60][60];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
		scanf("%1d", &mapA[i][j]);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
		scanf("%1d", &mapB[i][j]);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
		mapA[i][j] = mapA[i][j]^mapB[i][j];
	}	
	int index = 0;
	int count=0;
	while(index<m){
		if(mapA[0][index]==0){
			index++;	
		}
	}
	
}
