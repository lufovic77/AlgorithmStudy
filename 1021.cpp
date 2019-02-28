#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,M;	
int arrayToDelete[60];
int search(int pivot, int numToDelete, int checkList[],int count){
	cout<<pivot<<" "<<numToDelete<<" ";
	cout<<"check list";
	for(int i=1;i<=N;i++)
	cout<<checkList[i]<<" ";
	cout<<endl;
	if(numToDelete <= 0){
		return count;
	}
	if(pivot>N)
	pivot =  1;
	else if(pivot<1)
	pivot = N;
	if(arrayToDelete[pivot] == 1 & checkList[pivot]==1){
		checkList[pivot]=0;
		numToDelete--;
	}
	else if(arrayToDelete[pivot]==0){
		count++;
	}	
//	return min(search(pivot-1,numToDelete, checkList, count), search(pivot+1,numToDelete, checkList, count));
	int a = search(pivot-1,numToDelete, checkList, count);
	int b = search(pivot+1,numToDelete, checkList, count);
	return min(a,b);
}

int main(){
	int checkList[50];
	for(int i=0;i<=49;i++)
	checkList[i]=0;
	int pivot = 1;
	cin >> N>>M;
	int numToDelete = M;	
	int temp;
	for(int i=1;i<=N;i++)
	checkList[i]=1;
	for(int i=1;i<=M;i++){
		cin>>temp;
		arrayToDelete[temp] = 1;
	}
	int min=search(pivot, numToDelete, checkList, 0);
	cout<<min;
	return 0;
}
