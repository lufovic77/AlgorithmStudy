#include <iostream>
#include <cstdio>
#include <bitset>
#include <vector>
#include <algorithm>
#define FOR(i, n) for(int i=0;i<n;i++)
using namespace std;
/*
int stu [10001][51];
vector<int> sub[51];
two much memory -> use bitmasking!
*/ 
typedef bitset<51> bitS;
bitS stu [10001];
bitS sub [51];
int main(){
	unsigned int n, m, tmp, in;
	bitS bit;
	cin>>n;
	FOR(i, n){
		scanf("%d", &tmp);
		FOR(j, tmp){
			scanf("%d", &in);
			bit = 0x1;
			bit<<=in;
			sub[i] = sub[i] | bit;
		}
	}
	cin>>m;
	FOR(i, m){
		scanf("%d", &tmp);
		FOR(j, tmp){
			scanf("%d", &in);
			bit = 0x1;
			bit<<=in;
			stu[i] = stu[i] | bit;
		}
	}
	int index, total;
	FOR(i, m){
		total = 0;
		FOR(j, n){
			bit = stu[i] & sub[j];
			if(bit == sub[j])
				total++;
		}
		printf("%d\n", total);
	}
}
