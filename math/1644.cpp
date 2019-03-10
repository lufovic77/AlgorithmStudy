#include <iostream>
using namespace std;
int main(){
	int size;
	cin>>size;
	int arr[size];
	for(int i=1;i<=size;i++)
	arr[i]=i;
	for(int i=2;i<=size;i++){
		int temp = arr[i];
		if(temp!=0){
			for(int j=i+temp;j<=size;j+=temp){
				arr[j]=0;	
			}
		}
	}
	
	for(int i=size-1000;i<=size;i++)
	if(arr[i]!=0)
	cout<<arr[i]<<" ";
	
	
}
