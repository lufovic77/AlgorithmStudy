#include <iostream>
using namespace std;

int N,M;
int map[100000][10];
int temp[100000][10];
int x[1000000];
int y[1000000];
int vx[1000000];
int vy[1000000];
int dx[4]={1, 0,-1, 0};
int dy[4]={0, 1, 0,-1};
int index=0, index2=0;
void copy(void){
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			temp[i][j]=map[i][j];
		}
	} 	
}
void bfs(int x,int y){
	if(temp[x][y]==2 || temp[x][y]==1 || x<0||x>=N||y<0||y>=M)
	return ;
	temp[x][y]=2;
	for(int i=0;i<4;i++){
		bfs(x+dx[i], y+dy[i]);
	}
	return ;
}
void spread(void){
	for(int i=0;i<index2;i++){
		for(int j=0;j<4;j++){
	 		bfs(vx[i]+dx[j], vy[i]+dy[j]);
		}
	}
}
int find(){
	int area=0;
	for(int i=0;i<N;i++)
	for(int j=0;j<M;j++)
	if(temp[i][j]==0)
	area++;
	return area;
}
int main(){
	cin>>N;
	cin>>M;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			scanf("%d", &map[i][j]);
		}
	}
	int max=-1;
	int area=0;
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++){
			if(map[i][j]==0){
				x[index]=i;
				y[index]=j;
				index++;
			}
			if(map[i][j]==2){
				vx[index2]=i;
				vy[index2]=j;
				index2++;
			}
		}
	
	for(int a=0;a<index;a++)
		for(int b=a;b<index;b++)
			for(int c=b;c<index;c++){
				if(a==b || a==c || b==c)
				continue;
				else{
					copy();
					temp[x[a]][y[a]]=1;	//寒技快扁
					temp[x[b]][y[b]]=1;	//寒技快扁
					temp[x[c]][y[c]]=1;	//寒技快扁 
					spread();
					area=find();
				//	cout<<area<<endl;
					if(max<area)
					max=area;
				}
			}
	cout<<max;
}
