#include <iostream>
#include <vector>
#include <algorithm>
typedef struct num{
	int content;
	int index;
}NUM;
using namespace std;
int answer[60];
bool compFunc(NUM& a, NUM& b){
	if(a.content == b.content)
	return a.index<=b.index;
	else
	return a.content<=b.content;
}
int main(){
	int n;
	cin>>n;
	vector<NUM> array(n);
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		array[i].content = a;
		array[i].index = i;
	}
	sort(array.begin(), array.end(), compFunc);
	for(int i=0;i<n;i++){
		answer[array[i].index] = i;
	}
	for(int i=0;i<n;i++)
	cout<<answer[i]<<" ";
}
