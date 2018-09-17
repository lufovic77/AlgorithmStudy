#include <stdio.h>
#include <algorithm>

using namespace std;
typedef struct point{
	int x;
	int y;
}POINT;
POINT pos [100010];
bool cmp_POINT1(POINT a, POINT b) { return a.x<=b.x; }
bool cmp_POINT2(POINT a, POINT b) { return a.y<b.y; }

int main(){	
	int N;
	scanf("%d", &N);
	for(int i=0;i<N;i++)
		scanf("%d%d", &pos[i].x,&pos[i].y);
	sort(pos, pos+N, cmp_POINT1);
	for(int i=0;i<N;i++){
		int temp = pos[i].x;
		int start = i, end;
		while(pos[i].x == temp && i<N){
			i++;
			end = i;
		}
		i--;
		sort(pos+start, pos+end, cmp_POINT2);
	}
	for(int i=0;i<N;i++)
	printf("%d %d\n",pos[i].x, pos[i].y);
}
