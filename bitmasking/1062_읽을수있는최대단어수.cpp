#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <queue>
#include <string>
#include <bitset>
#define FOR(i,n) for(int i=0;i<n;i++)
#define FOR2(i,n) for(int i=1;i<=n;i++)
using namespace std;
bitset<27> bit[60]; //단어는 50개까지 주어질 수 있다. 
bitset<27> alpha;
bitset<27> cmp;
int n, k,ret = INT_MIN;
void recursive(int chance, int index){
	if(index>26)
		return ;
	if(chance == 0){
		int cnt = 0;
		FOR(i, n){
//			cout<<(bit[i]&cmp) <<endl;  <<를 bit operator로 착각해서 괄호를 꼭 해줘야함 ㅋㅋㅋㅋㅋ
			if((bit[i]&cmp) ==bit[i]){ //즉, 표현할 수 있는 단어라면
				cnt++;	
			}
 		}
		ret = max(ret, cnt);
		return;
	}
	if(alpha[index]==1){
		cmp.set(index,true);
		recursive(chance-1, index+1);
		cmp.set(index, false);
	}
	recursive(chance, index+1);
	return ;
}
int main(){
	ios::sync_with_stdio(false);//Should not combine iostream with cstdio furthur
	int chance;
	cin>>n>>k;
	chance = k-5;
	string s, tmp;
	alpha.reset();
	cmp.reset();
	/*alpha.flip(0); // 1 for a . flip(n)은 n+1번째 비트를 반전시킨다. 비트는 0번째, 1번째 이렇게 간다. 
	alpha.flip('n'-'a');
	alpha.flip('t'-'a');
	alpha.flip('c'-'a');
	alpha.flip('i'-'a');
	cmp.flip(0); // 1 for a
	cmp.flip('n'-'a');
	cmp.flip('t'-'a');
	cmp.flip('c'-'a');
	cmp.flip('i'-'a');*/
	FOR(i, n){
		cin>>s;
		tmp = s.substr(4, s.size()-8);
		for(int j=0;j<tmp.size();j++){
			char c = tmp[j];
			if(c!='a' && c!='n'&&c!='t'&&c!='c'&&c!='i'){
				bit[i].set(tmp[j]-'a', true);
				alpha.set(tmp[j]-'a',true);  //동일하게 set(n, true)도 n+1번째 비트를 true로 set함. 
			}
		}
	}
	if(k<5){
		cout<<"0";
		return 0;
	}
	if(k==26){
		cout<<n;
		return 0;
	}
	/*FOR(i, n){
		cout<<bit[i]<<endl;
	}
	cout<<alpha<<endl<<endl;*/
	recursive(chance, 1);
	cout<<ret;
}
