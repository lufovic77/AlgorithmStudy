#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <limits.h>
#define FOR(i, n) for(int i=0;i<n;i++)
using namespace std;
class segT{
	private:
		int tree[400000];
	public:
		segT(vector<int> arr, int n){
			init(arr, 1, 0, n-1);
		}
		int init(vector<int> arr, int node, int left, int right){
			if(left == right){
				return tree[node] = arr[left];
			}
			int mid = (left+right)/2;
			return tree[node] = min(\
					init(arr, node*2, left, mid), init(arr, node*2+1, mid+1, right));
		}
		int query(int l, int r, int node, int leftN, int rightN){
			if(leftN==rightN)
				return tree[node];
			if(rightN<l || leftN>r)
				return INT_MAX;
			if(l<=leftN && r<=rightN)
				return tree[node];
			int mid = (leftN+rightN);
			return min(query(l, r, node*2, leftN, mid),\
					query(l, r, node*2+1, mid+1, rightN));
		}
};
int main(){
	int n, m, tmp, a, b, ans;
	cin>>n>>m;
	vector <int> arr;
	FOR(i, n){
		cin>>tmp;
		arr.push_back(tmp);
	}
	segT obj = segT(arr, n); 
	FOR(i, m){
		cin>>a>>b;
		//Do something
		ans = obj.query(a, b, 1, 0, n-1);
		printf("%d\n", ans);
	}
}
