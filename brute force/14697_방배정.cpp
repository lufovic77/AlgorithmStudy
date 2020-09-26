#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define FOR(i, n) for(int i=0;i<n;i++)
using namespace std;
int main(){
	int a, b, c, n;
	cin>>a>>b>>c>>n;
	FOR(i, 50){
		FOR(j, 50){
			FOR(k, 50){
				if(a*i + b*j + k*c == n){
					cout<<1;
					return 0;
				}
			}
		}
	}
	cout<<0;
}
