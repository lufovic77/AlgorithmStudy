#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <queue>
#include <set>
#define FOR(i,n) for(int i=0;i<n;i++)
#define FOR2(i,n) for(int i=1;i<=n;i++)
using namespace std;
typedef unsigned long long ull;
struct CMP{
	bool operator()(pair<int, int> p, pair<int, int> q){
		if(p.second==q.second)
			return p.first>q.first;
		return p.second<q.second;
	}
};
int main(){
	int n, k, t1, t2;
	ull ret =0;
	priority_queue<pair<int, int> , vector<pair<int, int>> , CMP> pq;
	multiset<int> bag;
	cin>>n>>k;
	FOR(i, n){
		cin>>t1>>t2;
		pq.push(make_pair(t1, t2));
	}
	FOR(i, k){
		cin>>t1;
		bag.insert(t1);
	}
	while(!pq.empty() && bag.size()!=0){
		int left = 0, right = bag.size()-1, mid;
		int weight = pq.top().first, price = pq.top().second, prev = -1;
		auto iter = bag.end();
		iter--;
		if(weight>*iter){
			pq.pop();
			continue;
		}
		/*
		while(left<=right){
			mid = (left+right)/2;
			if(bag[mid] < weight)
				left = mid+1;
			else if (bag[mid]>weight){
				prev = mid;
				right = mid-1;
			}
			else
				break;
		}
		if(bag[mid]>=weight){
			bag.erase(bag.begin()+mid);
			ret+=price;
		}
		else if(prev!=-1){//prev가 답임
			bag.erase(bag.begin()+prev);
			ret+=price;
		}
		*/
		auto a = bag.lower_bound(weight);
		ret+=price;
		bag.erase(a);
		pq.pop();
	}
	cout<<ret;
}
