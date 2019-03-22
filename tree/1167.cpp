#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
int visited[100010];
map<int, map<int,int> > m;
typedef struct two{
	int node;
	int cost;
}TWO;
TWO* calCost (int node, int cost){
	int temp=cost;
	TWO* ret ;
	int cur = node;
	visited[node] = 1;
	map <int,int> :: iterator it2;
	for(it2 = m[node].begin() ;it2 != m[node].end(); it2++){
		if(visited[it2->first] == 0){
			ret = calCost(it2->first, cost+it2->second);
			if(temp < ret ->cost){
				temp = ret->cost;
				cur = ret->node;	
			}
		}
	}
	TWO* s1 = (TWO*)malloc(sizeof(TWO));
	s1->cost = temp;
	s1->node = cur;
	return s1;
}
int main(){
	int V;
	cin >> V;
	for(int i=0;i<V;i++){
		int temp;
		int node=0;
		while(1){
			cin>>temp;
			if(temp == -1) //end of input
			break;
			
			if(node == 0) //for the first time
				node = temp; 
			else{
				int a;
				cin>>a;
				m[node].insert(make_pair(temp,a));
			}				
		}
	}	
	/*
	map <int,map<int,int>> :: iterator it1;
	map <int,int> :: iterator it2;
	for(it1 = m.begin();it1!=m.end(); it1++){
		for(it2 = m[it1->first].begin() ;it2 != m[it1->first].end(); it2++)
		cout<<" "<<it2->first;
		cout<<endl;
	}*/
	TWO* s1 ;
	s1 = calCost(1, 0); //just start from node 1
	for(int i=0;i<100010;i++)
	visited[i]=0;
	int ret = s1->cost;
	s1 = calCost(s1->node, 0);
	cout<<s1->cost;
}
