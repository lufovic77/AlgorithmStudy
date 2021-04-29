#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
int check[100000];
int array[100000][2];
typedef long long ll;
int gcd(int a, int b) {

  while (b != 0) {
    int temp = a % b;
    a = b;
    b = temp;
  }

  return abs(a);
}
bool search(int num, int left, int right){
	if(left<=right){
		int mid = (left+right-1)/2;
		if(check[mid]<num){
			return search(num,left, mid-1);
		}
		else if(check[mid]>num){
			return search(num,mid+1, right);
		}
		else{
			return true;
		}
	}
	return false;
}
int main(){
	int l, r;
	cin>>l>>r;
	int count = 0;
	int index = 0;
	for(int i=l;i<r;i++){
		for(int j=i+1;j<=r;j++){
			sort(check, check+index);
			cout<<"?";
			for(int m=0;m<index;m++)
			cout<<check[m];
			cout<<"?";
			cout<<endl;
			if(search(i, 0,index-1)==true || search(j, 0,index-1)==true || i==j)
			continue;
			else{
				if(gcd(i,j)==1){
					array[count][0]=i;
					array[count][1]=j;
					check[index]=i;
					index++;
					check[index]=j;
					index++;
					count++;
				}
			}
		}
	}
	int temp = (r-l+1)/2;
//	if(count==temp){
		cout<<"YES"<<endl;
		for(int i=0;i<count;i++)
		cout<<array[i][0]<<" "<<array[i][1]<<endl;
	//}
	//else
	cout<<"NO";
}
