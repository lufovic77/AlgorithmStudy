#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;
int v, e, s;
vector<vector<pair<int/*node*/, int/*cost*/>>> edge;

vector<int> dijkstra(){
    vector<int> dist(v+1, INT_MAX);
    priority_queue<pair<int/*cost*/, int>> pq;

    pq.push({0, s});
    dist[s] = 0;
    while(!pq.empty()){
        int cost = -pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if(dist[node] < cost){
            continue;
        }

        for(auto temp: edge[node]){
            if(dist[temp.first] > cost + temp.second ){
                dist[temp.first] = cost+ temp.second;
                pq.push({-dist[temp.first], temp.first});
            }
        }    
    }
    return dist;
}

int main(){
    cin>>v>>e>>s;
    edge.resize(v+1); //한번 resize하면 고정이 돼서 다시 써야하먄 clear를 해줘야 한다. 

    for(int i=0;i<e;i++){
        int a, b, c;
        cin>>a>>b>>c;
        edge[a].push_back({b,c});
    }

    vector<int> ans = dijkstra();
    
    for(int i=1;i<=v;i++){
        int distance = ans[i];
        if(distance == INT_MAX){
            cout<<"INF"<<endl;
            continue;
        }
        cout<<distance<<endl;
    }
}