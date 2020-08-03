#include <iostream>
using namespace std;
int nest[246913]; //marked with 0 -> prime number
#define end 246912
int main(){
	nest[0] = 1;
	nest[1] = 1;
	for(int i=2;i<=end;i++){
		for(int j=2;j<=end/i;j++)
			nest[j*i] = 1;
	}
	int n,cnt;
	while(1){
		cnt = 0;
		cin>>n;
		if(n == 0)
			return 0;
		for(int i=n+1;i<=2*n;i++)
			if(nest[i]==0)
				cnt++;
		cout<<cnt<<endl;
	}
}
