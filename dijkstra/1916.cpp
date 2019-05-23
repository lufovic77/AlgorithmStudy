#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;
int city, bus; //city 1 to N
int s, g;
vector<vector<pair<int/*node*/, int/*cost*/>>> edge;
int dijkstra(){
	vector <int> dist(1001, INT_MAX);
	priority_queue <pair<int/*cost*/ , int /*node*/>> pq;
	dist[s] = 0;
	pq.push({0, s});

	while(!pq.empty()){
		int curCost = -pq.top().first;
		int curNode = pq.top().second;
		pq.pop();

		if(curNode == g)
		continue;
		for(auto nextNode: edge[curNode]){
			int & ret = dist[nextNode.first];
			if(ret > nextNode.second + curCost){
				ret = nextNode.second + curCost;
				pq.push({-ret, nextNode.first});
			}
			else
			{
				continue;
			}
		}
	}
	return dist[g];
}

int main(){
	cin>>city>>bus;
	edge.resize(city+1);
	for(int i=0;i<bus;i++){
		int a, b, c;
		cin>>a>>b>>c;
		edge[a].push_back({b, c});
	}
	cin>>s>>g;
	int ret = dijkstra();
	cout<<ret;
}
