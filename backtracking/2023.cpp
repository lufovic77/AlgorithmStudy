#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <math.h>
using namespace std;
bool check(int n){
	if(n==1)
	return false;
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0){
			return false;
		}
	}
	return true;
}

void making(int number[], int index , int n){
	if(index == n){
		for(int i=0;i<index;i++)
		cout<<number[i];
		cout<<endl;
		return ;
	}
	
	for(int i=1;i<=9;i++){
		number[index] = i;
		
		std::stringstream ss;
		for (unsigned j = 0; j <= index; ++j)
        ss << number [j];
        int temp;
        ss >> temp;
		
		if(check(temp)){
			making(number, index+1, n);
		}
	}
	return ;
}
int main(){
	int n;
    cin>>n;
    int number[10];
    int index = 0;
    making(number, index, n);
}

