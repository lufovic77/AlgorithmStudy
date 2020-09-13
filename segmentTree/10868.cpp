#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <limits.h>
#define FOR(i, n) for(int i=0;i<n;i++)
using namespace std;
class segT{
	private:
		int tree[300000];
		vector<int> arr;
	public:
		segT(vector<int> &v, int n){
			arr = v;
			init(1, 1, n);
		}
		int init(int node, int left, int right){
			if(left == right){
				return tree[node] = arr[left];
			}
			int mid = (left+right)/2;
			return tree[node] = min(
					init(node*2, left, mid), init(node*2+1, mid+1, right));
		}
		int query(int l, int r, int node, int leftN, int rightN){
			if(rightN<l || leftN>r)
				return INT_MAX;
			if(l<=leftN && rightN<=r)
				return tree[node];
			int mid = (leftN+rightN)/2;
			return min(query(l, r, node*2, leftN, mid),
					query(l, r, node*2+1, mid+1, rightN));
		}
};
int main(){
	int n, m, tmp, a, b, ans;
	cin>>n>>m;
	vector <int> arr;
	arr.push_back(0);
	FOR(i, n){
		scanf("%d", &tmp);
		arr.push_back(tmp);
	}
	segT obj = segT(arr, n); 
	FOR(i, m){
		scanf("%d%d", &a, &b);
		//Do something
		ans = obj.query(a, b, 1, 1, n);
		printf("%d\n", ans);
	}
}
