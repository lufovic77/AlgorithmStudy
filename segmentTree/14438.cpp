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
		int update(int index, int newValue, int node,int leftN, int rightN ){
			if(index<leftN || rightN<index)
				return tree[node];
			if(leftN == rightN)
				return tree[node] = newValue;
			int mid = (leftN+rightN)/2;
			return tree[node] = min(update(index, newValue, node*2, leftN, mid),
					update(index, newValue, node*2+1, mid+1, rightN));
		}
};
int main(){
	int n, m, tmp, a, b, c, ans;
	cin>>n;
	vector <int> arr;
	arr.push_back(0);
	FOR(i, n){
		scanf("%d", &tmp);
		arr.push_back(tmp);
	}
	cin>>m;
	segT obj = segT(arr, n); 
	FOR(i, m){
		scanf("%d%d%d", &a, &b,&c);
		//Do something
		if(a==1){
			obj.update(b, c, 1, 1, n);
		}
		else{
			ans = obj.query(b, c, 1, 1, n);
			printf("%d\n", ans);
		}
	}
}
