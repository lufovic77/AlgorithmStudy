#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
int main(){
	int r;
	cin>>r;
	double pi = M_PI;
	double ori = pi * pow(r, 2);
	double taxi = 2*pow(r, 2); // manhattan distance
	printf("%f\n%f", ori, taxi);
}
