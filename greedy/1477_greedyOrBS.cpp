#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <queue>
#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;
class custom{
	public:
		int x;
		int y;
		int diff;
	custom(int x, int y):x(x), y(y), diff(y-x){}
};
struct cmp{
	bool operator()(custom u, custom t){
		return u.diff < t.diff;
	}
};
int main(){
	int n, m, l, tmp;
	vector<int> pos;
	cin>>n>>m>>l;
	FOR(i, n){
		scanf("%d", &tmp);
		pos.push_back(tmp);
	}
	sort(pos.begin(), pos.end());
	priority_queue<custom, vector<custom>, cmp > pq; //max heap
	FOR(i, n-1){
		int a = pos[i], b = pos[i+1];
		pq.push(custom(a, b));
	}
	FOR(i, m){
		int x = pq.top().x;
		int y = pq.top().y;
		int mid = (x+y)/2;
		pq.pop();
		pq.push(custom(x, mid));
		pq.push(custom(mid, y));
	}
	cout<<pq.top().diff;
}
