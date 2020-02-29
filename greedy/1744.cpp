#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> doub_pair;

bool CMP (doub_pair a, doub_pair b){
	return a.first >= b.first;
}
//sort with the input value and also swap the index

int main(){
	int N;
	pair<int, int> input[10001];
	pair<int, int> sorting[10001];
	bool flag[10001];
	for(int i=0;i<10001;i++)
		flag[i] = false;
	cin>>N;
	for (int i=0;i<N;i++){
		int temp;
		cin >> temp;
		input[i].first = temp;
		input[i]. second = i;
	}
	for (int i=0;i<N;i++){
		sorting[i].first = input[i].first;
		sorting[i].second = input[i].second;
	}
	sort(sorting, sorting+N, CMP);
//pre-processing ends. Now for greedy Algorithm
	

}
