#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define FOR(i, n) for(int i=0;i<n;i++)
using namespace std;
int tree[100];
/*
void mutate_preorder(int node){
	if(tree[node] ==0)
		return ;
	cout<<tree[node]<<" ";
	mutate_preorder(node*2+1);
	mutate_preorder(node*2);
}
void postorder(int node){
	if(tree[node] ==0)
		return ;
	postorder(node*2);
	postorder(node*2+1);
	cout<<tree[node]<<" ";
}
//postorder result & preorder with right node prior result is same. 
*/
vector<int> preorder, inorder;
vector<int> slice(int l, int r, bool flag){
	vector<int> v;
	
	if(flag){
		if(l==r & l<preorder.size()){
			v.push_back(inorder[l]);
			return v;
		}
		return vector<int>(inorder.begin()+l, inorder.begin()+r);
	}
	if(!flag){
		if(l==r & l<preorder.size()){
			v.push_back(preorder[l]);
			return v;
		}
		return vector<int>(preorder.begin()+l, preorder.begin()+r);
	}
}
void toPostOrder(vector<int> pre, vector <int> in, int l, int r, int pI){
	int n = preorder.size();
	if(pre.empty()){
		return ;
	}
	int root = pre[0];
	int index = find(inorder.begin(), inorder.end(), root) - inorder.begin();
	cout<<"--"<<l<<r<<root<<index<<pI<<"--"<<endl;
	if(l!=r-1){
		toPostOrder(slice(pI+1,index+1, false), slice(l, index, true), l,index, pI+1);
		toPostOrder(slice(index+1, n, false), slice(index+1, n, true), index+1, r, index+1);
	}
	printf("%d ",root);
	return ;
}
int main(){
	int t, n, tmp;
	cin>>t;
	while(t--){
		scanf("%d", &n);
		preorder.clear();
		inorder.clear();
		FOR(i, n){
			scanf("%d", &tmp);
			preorder.push_back(tmp);
		}
		FOR(i, n){
			scanf("%d", &tmp);
			inorder.push_back(tmp);
		}
		toPostOrder(preorder, inorder, 0, n, 0);
		printf("\n");
	}
}
