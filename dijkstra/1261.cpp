#include <iostream>
#include <queue>
#include <cstdio>
#include <limits.h>

using namespace std;
typedef pair<int, int> POS;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int n, m;
int map[101][101];

int dijkstra(){
    int dist[101][101];
    for(int i=0;i<101;i++)
    for(int j=0;j<101;j++)
    dist[i][j] = INT_MAX;

    priority_queue<pair<int /*cost*/, POS /*node*/> > pq; //cost, node 
    /*
    계속 갱신
    */
    pq.push({0,{0,0}});
    dist[0][0] = 0;

    while(!pq.empty()){
        int cost = -pq.top().first;
        POS temp = pq.top().second;
        pq.pop();
        if(temp == make_pair(n,m)){
            continue;
        }

        for(int i=0;i<4;i++){
            int curX = temp.first + dx[i];
            int curY = temp.second + dy[i];

            if(curX < 0 || curX >=n || curY < 0 || curY >= m)
            continue;


            if(map[curX][curY] == 0){
                if(dist[curX][curY] > cost){
                    dist[curX][curY] = cost;    
                    pq.push({-cost,{curX, curY}});
                }

            }
            else{
                if(dist[curX][curY] > cost + 1){
                    dist[curX][curY] = cost + 1;    
                    pq.push({-cost-1,{curX, curY}});
                }
            }
        }
    }
    return dist[n-1][m-1];
}

int main(){
    cin >> m >> n;
    for(int i=0;i<n;i++){
        for(int k=0;k<m;k++){
            scanf("%1d", &map[i][k]);
        }
    }
    int ans = dijkstra();
    cout<<ans;
}