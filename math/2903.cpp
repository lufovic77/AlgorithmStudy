#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;
typedef long long int llu;
int main(){
	llu n, ret;
	cin>>n;
	ret = pow(2, n);
	ret = pow(ret+1, 2);
	printf("%lld", ret);
}
