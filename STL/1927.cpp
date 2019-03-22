#include <cstdio>
#include <queue>
using namespace std;
int main(){
	priority_queue<int,vector<int> ,greater<int> > pq;
	int n;
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		int temp;
		scanf("%d", &temp);
		if(temp == 0){
			if(pq.size()==0)
			printf("0\n");
			else{
				printf("%d\n", pq.top());
				pq.pop();
			}			
		}
		else{
			pq.push(temp);
		}
	}
}
