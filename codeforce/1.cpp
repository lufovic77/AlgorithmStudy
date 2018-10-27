#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctype.h>
using namespace std;
bool check(char array[], int len, int pri){
	bool flag1 = false;
	bool flag2 = false;
	bool flag3 = false;
	int pos1= -1;
	int pos2=-1;
	int pos3=-1;
	for(int i=0;i<len;i++){
		if(isdigit(array[i])){
			flag1 = true;
			pos1 = i;
		}
		if(isupper(array[i])){
			flag2 = true;
			pos2 = i;
		}
		if(islower(array[i])){
			flag3 = true;
			pos3 = i;
		}
	}
		if(flag1 && flag2 && flag3){
			return true;
		}
	if(pri==false){
		return false;
	}
	
	if((flag1 && flag2) ){
		for(int i=0;i<len;i++)	{
			if(i!=pos1 && i!=pos2){
				array[i] = 'a';
				printf("%s\n", array);
				return false;
			}
		}
		
	}
	if( (flag1&&flag3)) {
		
		for(int i=0;i<len;i++)	{
			if(i!=pos1 && i!=pos3){
				array[i] = 'A';
				printf("%s\n", array);
				return false;
			}
		}
	}
	if((flag2&&flag3) ){	//두개 있는 경우 
		
		for(int i=0;i<len;i++)	{
			if(i!=pos2 && i!=pos3){
				array[i] = '1';
				printf("%s\n", array);
				return false;
			}
		}
	}
	if(flag1){
	int temp = 0;
		for(int i=0;i<len;i++){
			if(i!=pos1&& temp==0) {
				temp=1;
				array[i]='A';
				continue;
			}
			if(i!=pos1 && temp==1){
				array[i]='a';
		printf("%s\n", array);
		return false;
			}
		}
		
	}
	if(flag2){
	int temp = 0;
		for(int i=0;i<len;i++){
			if(i!=pos2&& temp==0) {
				temp=1;
				array[i]='1';
				continue;
			}
			if(i!=pos2 && temp==1){
				array[i]='a';
		printf("%s\n", array);
		return false;
			}
		}
		
		
	}
	if(flag3){
		
	int temp = 0;
		for(int i=0;i<len;i++){
			if(i!=pos3&& temp==0) {
				temp=1;
				array[i]='1';
				continue;
			}
			if(i!=pos3 && temp==1){
				array[i]='A';
		printf("%s\n", array);
		return false;
		
			}
		}
	}
	
	return false;
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		char array[110];
		scanf("%s", array);
		int len = strlen(array);
		if(check(array, len, false)==true){
			printf("%s\n", array);
			continue;
		}
		else{
			check(array, len, true);
		}
	}
}
