#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int main(){
	char num[100010];
	int n;
	unsigned long long sum =0;
	cin>>num;
	int length = strlen(num);
	for(int i=0;i<length;i++){
		int a = num[i]-'0';
		sum+=a;
	}
	sort(num, num+length);
	if(num[0]!='0'){
		printf("-1");
		return 0;
	}
	
	if(sum%3 == 0){
		for(int i=length-1;i>=0;i--)
		printf("%c", num[i]);
		return 0;
	}
	else{
		printf("-1");
		return 0;
	}
}
