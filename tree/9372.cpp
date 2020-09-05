#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
#define FOR(i, n) for(int i=0;i<n;i++)
int main(){
/* While solving, I realized the answer is the number of edges. 
 * And number of edges is vertex-1. 
 * The answer is N-1. .......
 * */
	int t,n,m,a,b;
	cin>>t;
	FOR(i, t){
		cin>>n>>m;
		FOR(j, m){
			cin>>a>>b;
		}
		printf("%d\n", n-1);
	}
/*	int t, n, m;
	cin>>t;
	while(t--){
		cin>>n>>m;
		vector<int> edge[10010];
		int	visited[1010];

		int a, b, s;
		FOR(i, m){
			if(i==0)
				s = a;
			cin>>a>>b;
			edge[a].push_back(b);
			edge[b].push_back(a);
		}
		

	}
	*/
}
