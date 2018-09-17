#include <stdio.h>
#include <memory.h>
int dp[110][110];
int map[110][110];
int jump(int r, int c,int n){
	if(r==n-1 && c==n-1)
	return 1;
	if(r>=n || c>=n)
	return 0;

	int jumpsize=map[r][c];
	

	if(dp[r][c]!=-1){
		return dp[r][c];
	}
	return dp[r][c]=jump(r,c+jumpsize,n)||jump(r+jumpsize,c,n);
}
int main(){
	
	int c;
	scanf("%d", &c);
	
	memset(dp,-1,sizeof(dp));
	int i,j,n;
	int r,col;
	for(i=0;i<c;i++){
		memset(map,0,sizeof(map));
		scanf("%d", &n);
		for(r=0;r<n;r++){
			for(col=0;col<n;col++){
				scanf("%d", &map[r][col]);
			}
		}
		int result=jump(0,0,n);
		
		if(result==1)
			printf("YES\n");
		else
			printf("NO\n");
	memset(dp,-1,sizeof(dp));
		
	}
	return 0;	
}
