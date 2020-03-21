#include <cstdio>
#include <vector>
using namespace std;
int main(){
	vector <int> A;
	vector <int> B;
	int la, lb;
	scanf("%d%d", &la, &lb);
	int temp;
	for(int i=0;i<la;i++){
		scanf("%d", &temp);
		A.push_back(temp);
	}
	for(int i=0;i<lb;i++){
		scanf("%d", &temp);	
		B.push_back(temp);
	}
	vector <int> total;
	int ia = 0;
	int ib = 0;
	A.push_back(1000000001);
	B.push_back(1000000001);
	while(ia != la || ib != lb){
		if(A[ia] >=B[ib]){
			total.push_back(B[ib]);
			ib++;
		}
		else{
			total.push_back(A[ia]);
			ia++;
		}
	}
	for(auto elem : total)
		printf("%d ", elem);
}
