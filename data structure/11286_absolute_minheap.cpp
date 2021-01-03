#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <cmath>
#define FOR(i, n) for(int i=0;i<n;i++)
using namespace std;
class custom{
	public:
		int real;
		int absol;
	custom(int x):real(x), absol(abs(x)){}
};
struct cmp{
	bool operator()(custom u, custom t){
		if(u.absol == t.absol)
			return u.real >= t.real;
		return u.absol >= t.absol;
	}
};
int main(){
	int n, tmp;
	cin>>n;
	priority_queue<custom, vector<custom> ,cmp> pq;
	vector<int> input;
	FOR(i, n){
		scanf("%d", &tmp);
		input.push_back(tmp);
	}
	FOR(i, n){
		tmp = input[i];
		if(tmp == 0){
			if(pq.empty()){
				printf("0\n");
				continue;
			}
			printf("%d\n", pq.top().real);
			pq.pop();
		}
		else
			pq.push(custom(tmp));
	}
	
}
