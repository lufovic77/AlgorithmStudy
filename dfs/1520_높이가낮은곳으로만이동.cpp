#include <iostream>
#define FOR(i,n) for(int i=0;i<n;i++)
int dx[4] = {-1, 0, 1, 0}; 
int dy[4] = {0, 1, 0, -1};
using namespace std;
int ret = 0, m, n;
int dp[510][510];
int visited[510][510];
int	map[510][510];
int realZero[510][510];
/*
나는 항상 기준이
  -> 요기가 y 
   ---------------
요 |			  |
기 |			  |
가 |			  |
x  ---------------
 */
int dfs(int x, int y){
	if (x == m-1 && y == n-1 )
		return 1;
	if(dp[x][y]!=0){
		return dp[x][y];
	}
	if(dp[x][y] == 0 && realZero[x][y]==1)
		return 0;
	FOR(i, 4){
		int newX = x + dx[i];
		int newY = y + dy[i];
		if(newX >= 0 && newX<m && newY>=0 && newY <n && visited[newX][newY] == 0 && map[x][y] > map[newX][newY]){
			visited[newX][newY] = 1;
			dp[x][y] += dfs(newX, newY);
			visited[newX][newY] = 0;
		}
	}
	/*
		realZero가 필요한 이유
		: 탐색을 끝난 dp의 값이 0인건데, 
		코드에서는 방문을 아직 안한 경로인줄 알고 탐색을 시작할 수도 있다. 
		이를 방지하려고 진짜 dp값이 0인 경우 realZero도 1로 세팅해줘서 이런 오류를 막는다. 
	*/
	if(dp[x][y]==0)
		realZero[x][y] = 1;
	return dp[x][y];
}
int main(){
	ios::sync_with_stdio(false);//Should not combine iostream with cstdio furthur
	int tmp;
	cin>>m>>n;
	FOR(i, m){
		FOR(k, n){
			cin>>tmp;
			map[i][k] = tmp;
		}
	}
	visited[0][0] = 1;
	int ret = dfs(0, 0);
	cout<<dp[0][0];
}
