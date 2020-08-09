#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
typedef unsigned long long ull;
double dist (pair<int, int> a, pair<int, int>b){
	int tmp = pow(a.first-b.first, 2)+pow(a.second-b.second,2);
	return sqrt(tmp);
}
double gra(pair<int, int>a, pair<int,int>b){
	if(a.first-b.first==0)
		return 1;
	return (a.second-b.second)/(a.first-b.first);
}
bool middle(pair<int, int>a, pair<int, int>b, pair<int,int>c, pair<int,int>d){
	double x = (a.first+b.first)/2.0;
	double y = (c.first+d.first)/2.0;
	double z = (a.second+b.second)/2.0;
	double w = (c.second+d.second)/2.0;
	if(x==y && z==w)
		return true;
	else
		return false;
}
int main(){
	int n, x, y;
	cin>>n;
	for(int i=0;i<n;i++){
		pair<int, int> input[4];
		for(int k=0;k<4;k++){
			cin>>input[k].first>>input[k].second;
		}
		double a, b, c, d;
		double root = sqrt(2);
		a = gra(input[0],input[1]);
		b = gra(input[2],input[3]);//gradient
		if(a*b==-1 && dist(input[0],input[1])==dist(input[2],input[3])){
			if(middle(input[0], input[1], input[2], input[3])){
				cout<<1<<endl;
				continue;
			}
		}
		a = gra(input[0], input[2]);
		b = gra(input[1], input[3]);
		if(a*b==-1 && dist(input[0],input[2])==dist(input[1],input[3])){
			if(middle(input[0], input[2], input[1], input[3])){
				cout<<1<<endl;
				continue;
			}
		}
		a = gra(input[1],input[2]);
		b = gra(input[0],input[3]);
		if(a*b==-1 && dist(input[1],input[2])==dist(input[0],input[3])){
			if(middle(input[1], input[2], input[0], input[3])){
				cout<<1<<endl;
				continue;
			}
		}
		cout<<0<<endl;
	}
}

