#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <cstdlib>
#define FOR(i, n) for(int i=0;i<n;i++)
using namespace std;
class segT{
	private:
		pair<int, int>* tree;
		vector<int> arr;
	public:
		segT(vector<int> &v, int n){
			tree = new pair<int, int>[n*4];
			arr = v;
			init(1, 1, n);
		}
		pair<int, int> init(int node, int left, int right){
			if(left == right){
				tree[node].second = left;
				tree[node].first = arr[left];
				return tree[node];
			}
			int mid = (left+right)/2;
			pair<int, int> tmp1 = init(node*2, left, mid);
			pair<int, int> tmp2 = init(node*2+1, mid+1, right); 
			if(tmp1.first > tmp2.first){
				tree[node].second = tmp2.second;
				tree[node].first = tmp2.first;
				return tree[node];
			}
			else if(tmp1.first < tmp2.first){
				tree[node].second = tmp1.second;
				tree[node].first = tmp1.first;
				return tree[node];
			}
			else{
				if(tmp1.second < tmp2.second){
					tree[node].second = tmp1.second;
					tree[node].first = tmp1.first;
					return tree[node];				
				}
				else{
					tree[node].second = tmp2.second;
					tree[node].first = tmp2.first;
					return tree[node];
				}
			}

		}
		pair<int, int> query(int l, int r, int node, int leftN, int rightN){
			if(rightN<l || leftN>r){
				pair<int, int> tmp;
				tmp.first = INT_MAX;
				return tmp;
			}
			if(l<=leftN && rightN<=r)
				return tree[node];
			int mid = (leftN+rightN)/2;
			pair<int, int> one = query(l, r, node*2, leftN, mid);
			pair<int, int> two = query(l, r, node*2+1, mid+1, rightN);
			if(one.first>two.first)
				return two;
			else if(one.first<two.first)
				return one;
			else{//same case
				if(one.second<two.second)
					return one;
				else
					return two;
			}
		}
		pair<int, int> update(int index, int newValue, int node,int leftN, int rightN ){
			if(index<leftN || rightN<index)
				return tree[node];
			if(leftN == rightN){
				tree[node].second = leftN;
				tree[node].first = newValue;
				return tree[node];
			}
			int mid = (leftN+rightN)/2;
			pair<int, int> tmp1 = update(index, newValue, node*2, leftN, mid);
			pair<int, int> tmp2 = update(index, newValue, node*2+1, mid+1, rightN);
			if(tmp1.first > tmp2.first){
				tree[node].second = tmp2.second;
				tree[node].first = tmp2.first;
				return tree[node];
			}
			else if (tmp1.first < tmp2.first){
				tree[node].second = tmp1.second;
				tree[node].first = tmp1.first;
				return tree[node];
			}
			else{
				if(tmp1.second < tmp2.second){
					tree[node].second = tmp1.second;
					tree[node].first = tmp1.first;
					return tree[node];				
				}
				else{
					tree[node].second = tmp2.second;
					tree[node].first = tmp2.first;
					return tree[node];
				}
			}
		}
};
int main(){
	int n, m, tmp, a, b, c;
	pair<int, int> ans;
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
			printf("%d\n", ans.second);
		}
	}
}
