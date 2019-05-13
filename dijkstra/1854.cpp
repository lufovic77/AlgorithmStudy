#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, k;
vector<vector <pair<int, int> > > edge;

vector <priority_queue<int, int>> djikstra (){
    priority_queue<pair<int, int> > pq;

    while(!pq.empty()){

    }


}



int main(){
    
    cin>>n>>m>>k;
    vector <pair<int, int> > temp;

    for(int i=0;i<m;i++){
        int a, b, c;
        cin>>a>>b>>c;
        edge[a].push_back({b,c});
    }



}