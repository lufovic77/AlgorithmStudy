#include <iostream>
#include <cstdlib>
#define num_partitions 10000
using namespace std;

typedef struct node{
	string name;
	int present;
	struct node * next;
}NODE;
NODE * hashtable[10000];

void traverse(){
	for (int i=0;i<10000;i++){
		if(hashtable[i]==NULL)
		continue;
		else{
			NODE * temp;
			temp = hashtable[i];
			while(temp!=NULL){
				cout<<temp->name<<endl;
				temp=temp->next;
			}
		}
	}
	return ;
}

unsigned long hashing(const char *key) {
    unsigned long hash = 5381;
    int c;
    while ((c = *key++) != '\0')
        hash = hash * 33 + c;
    return hash % num_partitions;
}

void newNode(string & name, int flag){
	NODE* root=(NODE*)malloc(sizeof(NODE));
	root->name = name;
	root->present = flag;
	root->next=NULL;
	return ; 
}
void insert(string & name1, int flag, int index){
	if(hashtable[index]==NULL){	//처음 방문해보리기 
		hashtable[index]=(NODE*)malloc(sizeof(NODE));
		hashtable[index]->name = name1;
		hashtable[index]->present = flag;
		hashtable[index]->next=NULL;
		return ;
	}
	else{
		NODE * node = hashtable[index];
		while(node->next!=NULL){
			if(node->name.compare(name1)==0){	//같다
				node->present=flag; 
				return ;
			}
		}
		NODE * temp =(NODE*)malloc(sizeof(NODE));
		temp->name = name1;
		temp->present = flag;
		temp->next=NULL;
		node->next=temp;
	}
}
int main(){
	int n;
	cin>>n;
	string name;
	string IO;
	bool flag;
	string in="enter";
	for(int i=0;i<n;i++){
		cin>>name;
		cin>>IO;
		cout<<"sdasd";
		const char * na = name.c_str();
		unsigned long hash = hashing(na);
		
		cout<<"hashing: "<<hash<<endl;
		if(IO.compare(in)==0){	//enter
			flag=1;
		}
		else
			flag=0;
		cout<<"?";
		insert(name, flag, hash);
	}
	traverse();
	
}
