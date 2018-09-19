#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <math.h>
using namespace std;
//bool isPrime[MAX+1];
/*
void makeprime(int number[], int index, bool flag){
	if(flag == false)
	return ;
	if(index ==n && flag==true ){
		for(int i=0;i<index;i++)
		cout<<number[i];
		cout<<endl;
		return ;
	}
	for(int i=1;i<=9;i++){
		number[index ] = i;
		std::stringstream ss;
		for (unsigned j = 0; j <= index; ++j)
        ss << number [j];
        int temp;
        ss >> temp;
		if(isPrime[temp]){
			makeprime(number, index+1, true);
			number[index] = 0;
		}	
		else 
		makeprime(number, index+1, false);
	}
}
*/
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
    /*
    vector<int> prime;
    fill(isPrime+2, isPrime+MAX+1, true);
    int size = pow(10, n) - pow(10, n-1);
    cout<<size<<endl;
    for(int i=2; i<=MAX; i++){
        if(isPrime[i]) prime.push_back(i);
        for(int j=i*2; j<=MAX; j+=i)
            isPrime[j] = false;
    }
    int number[10];
    /*
    for(int i=0; i<prime.size(); i++){
        printf("%4d", prime[i]);
        if(i%10 == 9 || i == prime.size()-1) puts("");
    }
    */
    int number[10];
    int index = 0;
    making(number, index, n);
   // makeprime(number, 0, true);
}

