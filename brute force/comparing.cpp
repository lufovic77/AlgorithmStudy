#include <iostream>
using namespace std;
int getSum(int now, int sum){
    if(now==0)
    return sum;
    return getSum(now-1, sum+now);
}

int main(){
	int sum=0;
	for(int i=1;i<=10;i++)
		sum+=i;
	cout<<"for: "<<sum<<endl;
	cout<<"recursion: "<<getSum(10,0)<<endl;
	
}
