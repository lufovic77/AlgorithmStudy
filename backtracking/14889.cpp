#include <iostream>
using namespace std;
#define FOR(i, k) for(int i=1;i<=k;i++)
int ability[22][22];
int stotal=0, ltotal=0, n;
void backtrack(bool flag[],int cur, int cnt){
	if(cnt == n/2){
		FOR(i, n)
			cout<<flag[i];
		cout<<endl;
		return ;
	}
	for(int i=cur;i<=n;i++){
		if(!flag[i]){	
			flag[i] = true;
			backtrack(flag,i,cnt+1);
			flag[i] = false;
		}
	}
	return ;
}
int main(){
	int tmp;
	cin >> n;
	FOR(i, n)
		FOR(j, n){
			scanf("%d",&tmp);
			ability[i][j] = tmp;
		}
	bool flag[22];
	fill(flag, flag+21, false);
	flag[1] = true;
	backtrack(flag,2, 1);
}
