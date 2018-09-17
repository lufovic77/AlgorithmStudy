#include <iostream>
#include <cstdio>
using namespace std;

typedef unsigned long long ull;
int array[11][2];
int n;
ull mini = 2100000000;
void find(ull left, ull right, int count){
	if(count == n){
		if(left == 0 && right ==0)
		return ;
		ull diff;
		if(left > right )
		diff = left -right;
		else
		diff = right -left;
		if(mini>diff)
		mini = diff;
		return ;
	}
	if(left == 0){
		find(array[count][0], right + array[count][1], count+1);
	}
	else{
		find(left*array[count][0], right + array[count][1], count+1);
	}
		find(left, right, count+1);
	return ;	
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d%d",&array[i][0] , &array[i][1]);
	}
	find(0,0,0);
	cout<<mini;
}
