#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp (int a, int b){return a>b;}
int main(){
	int n;
	vector <int> pos;
	vector <int> neg;
	cin>>n;
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		if(temp>0)
			pos.push_back(temp);
		else
			neg.push_back(temp);
	}
	sort(pos.begin(), pos.end(), cmp);
	sort(neg.begin(), neg.end());
	int total = 0;
	int pos_len = pos.size();
	int neg_len = neg.size();
	if(pos_len %2 ==1 )
		total += pos[--pos_len];
	if(neg_len %2 ==1 )
		total += neg[--neg_len];
	if(pos_len!=0){
		for(int i=0;i<pos_len ;i+=2){
			if(pos[i] == 1){
				total +=2 ;
				continue;
			}
			if(pos[i+1] == 1){
				total +=1;
				total +=pos[i];
			}
			total += pos[i] * pos[i+1];
		}
	}
	if(neg_len !=0){
		for(int i=0;i<neg_len ;i+=2){
			total += neg[i] * neg[i+1];
		}
	}
	cout<<total;
}
