#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
bool CMP(int a, int b){return a<=b;};
int main(){
	int N,tmp;
	scanf("%d", &N);
	vector<int> arr;
	for(int i=0;i<N;i++){
		scanf("%d", &tmp);
		arr.push_back(tmp);
	}
	sort(arr.begin(), arr.end(), CMP);
	for(auto ele: arr)
		printf("%d\n", ele);
}
