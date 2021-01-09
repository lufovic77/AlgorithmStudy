#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#define FOR(i,n) for(int i=0;i<n;i++)
#define FOR2(i,n) for(int i=1;i<=n;i++)
using namespace std;
bool checkPalindrome(int a){
	string cmp1 = to_string(a);
	string cmp2 = cmp1;
	reverse(cmp1.begin(), cmp1.end()); //reversing the string
	if(cmp1 == cmp2)
		return true;
	return false;
}
int main(){
	int size = 1040000, n;
	int number[size];
	vector<int> prime;
	cin>>n;
	FOR2(i, size)
		number[i] = i;
	//sieve start
	for(int i=2;i<sqrt(size);i++)
		if(number[i] != 0)
			for(int k = pow(i,2);k<=size;k+=i) //focuse on k = pow(i, 2) not i*2
				number[k] = 0;
	//sieve end
	FOR2(i, size)
		if(number[i] !=0)
			prime.push_back(number[i]);
	for(auto a: prime){
		if(a>=n){
			if(checkPalindrome(a)){
				cout<<a;
				return 0;
			}
		}
	}
}
