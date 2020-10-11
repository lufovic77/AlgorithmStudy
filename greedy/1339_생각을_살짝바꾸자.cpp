#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <cmath>
#define FOR(i, n) for(int i=0;i<n;i++)
using namespace std;
int arr[26]; //for alphabetic order	
int main(){
	int n, l;
	string tmp;
	cin>>n;
	char c;
	FOR(i, n){
		cin>>tmp;
		FOR(j, tmp.length()){
			c = tmp[j];	
			l = tmp.length()-j-1;
			arr[c-'A'] += pow(10, l);
		}	
	}
	int total = 0, index =0;
	sort(arr, arr+26, greater<int>());
	for(int i=9;i>=0;i--){
		total += arr[index++]*i;
	}
	cout<<total;
}
