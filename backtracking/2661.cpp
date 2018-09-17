#include <iostream>
#include <stdlib.h> 
#include <cstring>
using namespace std;
int num[3]={1,2,3};
int length;
int n;
bool check(int array[], int index){
	int len = 2;
	while(len*2<=index){
		for(int i=0;i<=index-2*len;i++){
			int flag2=0;
			for(int j=0;j<len;j++){
				if(array[i+j]!=array[i+j+len]){
					flag2 = 1;
				}
				
			}
			if(flag2 == 0){
				return false;
			}
		}
		//
		len++;
	}
	return true;
}
void making(int array[], int prev, int index){
	if(index == n){
		if(check(array, index)==true){
			for(int i=0;i<n;i++)
			cout<<array[i];
				exit(0);
				return ;
		}
		return ;
	}
	for(int i=0;i<3;i++){
		if(prev != num[i]){
			array[index] = num[i];
			if(check(array, index)==false){
				return ;
			}
			making(array, num[i], index+1);
		}
	}
}
int main(){
	cin>>n;
	int array[100];
	array[0] = 1;
	for(int i=1;i<100;i++)
	array[i]=0;
	making(array, 1,1);
}
