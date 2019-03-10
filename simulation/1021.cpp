#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <deque>
using namespace std;
typedef struct no{
	int val;
	struct no* prev;
	struct no* next;
}NODE;

void del(NODE* cur){
	NODE* prev = cur->prev;
	NODE* next = cur->next;
	prev->next=next;
	next->prev=prev;
	return ;
} 
int nodeNum;
int main(){
	deque<int> dq;
	int N,M;
	cin>>N>>M;
	for(int i=0;i<M;i++){
		int temp;
		cin>>temp;
		dq.push_back(temp);
	}
	nodeNum=M;
	NODE* first;
	NODE* cur;
	for(int i=1;i<=N;i++){
		NODE* temp = (NODE*)malloc(sizeof(NODE));
		temp->val=i;
		
		if(i!=1){
			temp->prev=cur;
			cur->next=temp;
		}
		cur = temp;
		if(i==1){
			first=temp;		
			continue;
		}
		else if(i==N){
			temp->next=first;
			first->prev=temp;
		}
	}
	//������� circular queue �� ����.
	cur = first;
	int total=0;
	while(!dq.empty()){
		int temp = cur->val;
		if(dq.front()==temp){//���ݲ� �����ϱ� 
			if(nodeNum==1){//������ �ϳ� ������ ����. ���� ����ϸ� �ȴ�.  
				cout<<total;
				return 0;
			}		
			del(cur);
			dq.pop_front();
			nodeNum--;
			cur = cur->next;
		}
		else{//�����̶� ������ ���ϱ� 
			int cnt1=0, cnt2=0;
			NODE* temp=cur;
			while(!(temp->val==dq.front())){
				cnt1++;
				temp=temp->prev;
			}
			temp = cur;
			while(!(temp->val==dq.front())){
				cnt2++;
				temp=temp->next;
			}
			if(cnt1>cnt2){ //�������� �̵��� 
				total+=cnt2;
				for(int i=0;i<cnt2;i++)
				cur=cur->next;
			}
			else{
				total+=cnt1;
				for(int i=0;i<cnt1;i++)
				cur=cur->prev;
			}
		}
	} 
}
