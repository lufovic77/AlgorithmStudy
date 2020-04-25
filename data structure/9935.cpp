#include <iostream>
#include <cstdio>
#include <string>
#include <cstdlib>
using namespace std;
typedef struct node{
	struct node* next;
	struct node* prev;
	char c;
}NODE;
#define FOR(i,b) for(int i=0;i<b;i++)
class Stack{
	private:
		int len; //len of original string
		int len_e;
		string ori;
		string exp;
		NODE* root;
	public:
		int len_r;
		Stack(string o, string e){
			this->ori = o;
			this->exp = e;
			this->len = o.size();
			this->len_e = e.size();
			len_r = 0;
		}
		void push(){
			NODE* p = NULL;
			FOR(i, len){
				len_r++;
				if(ori[i] == exp[len_e-1] && len_r>=len_e){
					bool flag = true;
					NODE* t = p;
					FOR(j, len_e-1){
						if(p->c!=exp[len_e-j-2]){
							flag = false;
							break;
						}
						p = p->prev;
					}
					if (flag == true){
						if(p!=NULL)
							p->next = NULL;
						else
							root =NULL;
						len_r-=len_e;
						continue;
					}
					else
						p = t;
				}
				NODE* tmp=(NODE*)malloc(sizeof(NODE));
				tmp->c = ori[i];
				tmp->prev = p;
				tmp->next = NULL;
				if(p!=NULL)
					p->next = tmp;
				else
					root = tmp;
				p = tmp;
			}
		}
		void print(){
			NODE* p = root;
			while(p!=NULL){
				cout<<p->c;
				p = p->next;
			}
			if(root==NULL)
				cout<<"FRULA";
		}
		int scan(int len){
			NODE* p = root;
			int len_r=len;
			FOR(i, len){
				len_r++;
				if(ori[i] == exp[len_e-1] && len_r>=len_e){
					bool flag = true;
					NODE* t = p->next;
					FOR(j, len_e-1){
						if(p->c!=exp[len_e-j-2]){
							flag = false;
							break;
						}
						p = p->prev;
					}
					if (flag == true){	
						p->next = t;
						t->prev = p;
						len_r-=len_e;
						continue;
					}
					else
						p = t;
				}
				p = p->next;
			}
			return len_r;
		}
		
};
int main(){
	string original;
	string explode;
	cin>>original>>explode;
	Stack stack(original, explode); //initialize
	stack.push();
	int len=0, tlen=-1;
	stack.len_r = 0;
	while(1){
		tlen = len;
		len=stack.scan(stack.len_r);
		if(tlen == len)
			break;
	}
	stack.print();
}
