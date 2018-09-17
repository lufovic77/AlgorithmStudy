#include <iostream>
using namespace std;
int answer(int left){
	if(left == 1)
	return 1;
	if (left ==2)
	return 3;
	return 2*answer(left-1)+1;
}

int main(){
	int N;
	cin>>N;
	cout << answer(N);
}
