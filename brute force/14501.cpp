#include <iostream>
#include <algorithm>
using namespace std;
int time[16];
int price[16];
int N;
int findCost(int mark[], int start, int curPrice, int prev){
	if(start==N)
		return curPrice;
	if(start>N)
		return curPrice-price[prev];
	int maximum=-1;
	for(int i=start;i<N;i++){
		if(/*i+time[i]-1	<N &&*/ mark[i]!=1 && mark[i+time[i]-1]!=1){	//can be done in limited time? 
			for(int k=0;k<time[i];k++){
				mark[i+k]=1;
			}	
			maximum=max(maximum, findCost(mark, i+time[i], curPrice+price[i], i));
			for(int k=0;k<time[i];k++){
				mark[i+k]=0;
			}	
		}
	}
	return maximum;
}

int main(){
	cin>>N;
	int mark[16];
	for(int i=0;i<16;i++)
	mark[i]=0;
	for(int i=0;i<N;i++){
		cin>>time[i]>>price[i];
	}
	int answer=findCost(mark, 0, 0, 0);
	cout<<answer;
}
