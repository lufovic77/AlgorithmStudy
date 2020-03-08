#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> doub_pair;

bool CMP_1 (doub_pair a, doub_pair b){
	return a.first >= b.first;
}
bool CMP_2 (doub_pair a, doub_pair b){
	return a.first < b.first;
}
//sort with the input value and also swap the index

int main(){
	int N;
	pair<int, int> pos_sorting[10002];
	pair<int, int> neg_sorting[10002];
	bool pos_flag[10002]; //flag for input array
	pos_flag[0] = true;
	pos_flag[10001] = true;
	for(int i=1;i<10001;i++)
		pos_flag[i] = false;
	bool neg_flag[10002];
	neg_flag[0] = true;
	neg_flag[10001] = true;
	for(int i=1;i<10001;i++)
		neg_flag[i] = false;
	cin>>N;
	int pos_i = 1;
	int neg_i = 1;
	for (int i=1;i<=N;i++){
		int temp;
		cin >> temp;
		if(temp >0){
			pos_sorting[pos_i].first = temp;
			pos_sorting[pos_i].second = i;
			pos_i++;
		} //for positive integers (including zero)
		else{
			neg_sorting[neg_i].first = temp;
			neg_sorting[neg_i].second = i;
			neg_i++;
		}	
	}
	pos_flag[pos_i] = true;
	neg_flag[neg_i] = true;
	sort(pos_sorting+1, pos_sorting+pos_i, CMP_1);
	sort(neg_sorting+1, neg_sorting+neg_i, CMP_2);

//pre-processing ends. Now for Greedy Algorithm. First, positive integers
	int total = 0;
	for(int i=1;i<=pos_i;i++){
		int pick = pos_sorting[i].first;
//		int index = pos_sorting[i].second;
		int left = -1;
		int right = -1;
		if(pos_flag[i])
			continue;
		if(!pos_flag[i-1] ){ //left
			int &target = pos_sorting[i-1].first;
			if(target <=1){
				//ignore
			}
			else{
				left = target;
			}			
		}
		if(!pos_flag[i+1]){ //right
			int &target = pos_sorting[i+1].first;
			if(target <=1){
				//ignore
			}
			else{
				right= target;
			}
		}
		pos_flag[i] = true;
		if(left == -1 && right==-1){
			total += pick;
			continue;
		}
		if(left>=right){
			total += left*pick;
			pos_flag[i-1] = true;
		}
		else{
			total += right*pick;
			pos_flag[i+1] = true;
		}
	}
	for(int i=1;i<=neg_i;i++){
		int pick = neg_sorting[i].first;
		int index = neg_sorting[i].second;
		int left = 1;
		int right = 1;
		if(neg_flag[i])
			continue;
		if(!neg_flag[i-1] ){ //left
			left = neg_sorting[i-1].first;		
		}
		if(!neg_flag[i+1]){ //right
			right= neg_sorting[i+1].first;
		}
		neg_flag[i] = true;
		if(left == 1 && right==1){
			total += pick;
			continue;
		}
		if(left>=right){
			total += right*pick;
			neg_flag[i+1] = true;
		}
		else{
			total += left*pick;
			neg_flag[i-1] = true;
		}

	}
	cout<<total;
}
