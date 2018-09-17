#include <iostream>
#include <cstdio>
using namespace std;

bool relation[910][910];
int global;
int K,N,F;
int done=0;
void findPairs(bool students[64], int count){
	if(done==1)
	return;
	int firstFree=-1;
	int flag=-1;
	for(int i=1;i<=N;i++){
		
		if(!students[i]){
			firstFree=i;	
			break;
		}
	}
	global=count;
	if(count==K/2){
		done=1;
		return ;
	}
	if(firstFree==-1)
	return ;
	for(int i=firstFree+1;i<=N;i++){
		if(students[i]==false && relation[firstFree][i]==true){
			if(done==1)
			return;
			flag=1;
			students[i]=students[firstFree]=true;
			findPairs(students, count+1);
	//		students[i]=students[firstFree]=false;
		}
		
	}
	return ;
}
int main(){
	bool students[64];
	for(int i=0;i<64;i++)
	students[i]=false;

	for(int i=1;i<910;i++)
	for(int j=1;j<910;j++)
	relation[i][j]=false;
		
	cin>>K>>N>>F;
	for(int i=0;i<F;i++){
		int a,b;
		cin>>a>>b;
		relation[a][b]=true;
		relation[b][a]=true;
	}
	findPairs(students, 0);
	for(int i=1;i<=N;i++){
			cout<<students[i]<<" ";
		}
	
	
	cout<<"global"<<global<<endl; 
	if(global*2<K)
	cout<<"-1";
	else{
		for(int i=1;i<=N;i++){
			if(students[i]==true)
			cout<<i<<endl;
		}
	}
}
