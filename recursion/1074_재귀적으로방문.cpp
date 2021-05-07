#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <algorithm>
#define FOR(i,n) for(int i=0;i<n;i++)
#define FOR2(i,n) for(int i=1;i<=n;i++)
using namespace std;
int c[4] = {0, 0, 1, 1};
int r[4] = {0, 1, 0, 1};
int cnt = 0;
typedef pair<int, int> p;
p target;
bool found = false;
void recursion(p LU, p RD){
	if(found)
		return ;
	int tc = target.first, lc = LU.first, rc = RD.first;
	int tr = target.second, lr = LU.second, rr = RD.second;
	if(LU.first == RD.first && LU.second == RD.second){
		if(lc == tc && lr == tr){
			cout<<cnt;
			found = true;
		}
		cnt++;			
		return ;
	}
	else{
		p lu = make_pair(lc, lr);
		p rd = make_pair((rc+lc)/2, (lr+rr)/2);
		recursion(lu, rd);
		lu = make_pair(lc, (rr+lr)/2+1);
		rd = make_pair((rc+lc)/2, rr);
		recursion(lu, rd);
		lu = make_pair((rc+lc)/2+1, lr);
		rd = make_pair(rc, (rr+lr)/2);
		recursion(lu, rd);
		lu = make_pair((rc+lc)/2+1, (rr+lr)/2+1);
		rd = make_pair(rc, rr);
		recursion(lu, rd);
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false);//Should not combine iostream with cstdio furthur
	int n, c, r;
	cin>>n>>c>>r;
	/*
	구간을 뭉텅이로 자를 필요가 있음. 
	내 생각에는 왼쪽 위 좌표, 오른쪽 아래 좌표로 나누면 좋을듯
	아니 시부레 이거 행, 열도 0부터 시작하고 
	n번째 방문도 0부터 시작임 ;;;
	아니 코드짜다 보니까 coloum/row 순으로 집어넣었네 .......
	*/
	p LU = make_pair(0, 0);
	p RD = make_pair(pow(2, n)-1,pow(2, n)-1);	
	target = make_pair(c, r);
	recursion(LU, RD);
}
