#include <cstdio>
using namespace std;
typedef long long ll;
int main(){
	ll N,M;
	scanf("%d%d", &N, &M);
	ll a = N-M;
	ll b = N+M;
	ll ret = a*b;
	printf("%ld", ret);
	return 0;	
}
