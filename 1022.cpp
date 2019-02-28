#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<int> lt;
int main(){
	int r1, c1, r2, c2;
	cin>>r1>>c1>>r2>>c2;
	int map[60][10];
	int prev = 1;
	int temp;
	lt.push_back(1);
	for(int i=1;i<=5000;i+=2){
		int gap = 4*i;
		temp = prev+gap;
		lt.push_back(temp);
		prev = temp;
	}
	int pos = abs(r1)
	
	
	
}
