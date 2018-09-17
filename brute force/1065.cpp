#include <iostream>
using namespace std;
int check(int i){
	int array[5], diff[5];
	int index=0, index2=0;
	while(i!=0){
		array[index]=i%10;
		i/=10;
		index++;		
	}
	if(index==1)
	return 1;
	for(int k=1;k<index;k++, index2++){
		diff[index2]= array[k]-array[k-1];
	}
	int flag=1, temp=diff[0];
	for(int k=1;k<index2;k++)
	if(temp!=diff[k])
	flag=0;
	if (flag==1)
	return 1;
	else
	return 0;
}

int main(){
	int N;
	cin>>N;
	int answer=0;
	for(int i=1;i<=N;i++)
	answer+=check(i);
	cout<<answer;
}
