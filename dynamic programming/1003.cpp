#include <iostream>
#include <cstdio>
using namespace std;
int dp1[50];
int dp2[50];
int fibonacci1(int n) {
    int &ret = dp1[n];
    if(ret!=-1)
    return ret;
    else if (n == 0) {
		return 1;
    } else if (n == 1) {
        return 0;
    } else {
        return ret = fibonacci1(n-1) + fibonacci1(n-2);
    }
}
int fibonacci2(int n) {
    int &ret = dp2[n];
    if(ret!=-1)
    return ret;
    else if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return ret = fibonacci2(n-1) + fibonacci2(n-2);
    }
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int num;
		scanf("%d", &num);
		if(num == 0){
			printf("1 0\n");
			continue;
			
		}
		else if(num ==1){
			printf("0 1\n");
			continue;
		}
		for(int k=0;k<41;k++){
			dp1[k]=-1;dp2[k]=-1;
		}
		fibonacci1(num);
		fibonacci2(num);	
		printf("%d %d\n", dp1[num],dp2[num]);
	}	
}
