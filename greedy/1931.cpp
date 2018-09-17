#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct info{
	int start, end;
}INFO;

bool cmp(const INFO & a, const INFO& b){
	if(a.end == b.end) return a.start <b.start;
	else return a.end<b.end;
}
int main(){
	int N;
	cin>>N;
	vector<INFO> array(N);
	for(int i=0;i<N;i++){
		cin>>array[i].start>>array[i].end;
	}
	sort(array.begin(), array.end(), cmp);
		
	int last = array[0].end;
	int count = 1;
	for(int i=1;i<N;i++){
		if(array[i].start>=last){
		last = array[i].end;
		count++;
		}		
	}
	cout<<count;
}

/*
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

typedef struct info{
	int start, end;
}INFO;

INFO array[10010];
bool cmp(const INFO & a, const INFO& b){
	if(a.end == b.end) return a.start <b.start;
	else return a.end<b.end;
}
int main(){
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		array[i].start=a;
		array[i].end=b;
	}
	sort(array, array+N, cmp);
		
	int last = array[0].end;
	int count = 1;
	for(int i=1;i<N;i++){
		if(array[i].start>=last){
		last = array[i].end;
		count++;
		}		
	}
	cout<<count;
}
*/
