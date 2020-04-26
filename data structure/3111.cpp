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
		int rm_front(int len){
			NODE* p = root;
			int len_t=0;
			FOR(i, len){
				len_t++;
				if(p->c == exp[len_e-1] && len_t>=len_e){
					bool flag = true;
					NODE* t = p->next;
					FOR(j, len_e){
						if(p->c!=exp[len_e-j-1]){
							flag = false;
							break;
						}
						p = p->prev;
					}
					if (flag == true){	
						if(p==NULL){
							p = (NODE*)malloc(sizeof(NODE));
							root = p;
							p->prev = NULL;
						}
						p->next = t;
						t->prev = p;
						len_t-=len_e;
						len_r-=len_e;
						return len_r;
					}
					else
						p = t;
				}
				p = p->next;
			}
			return len_r;
		}
		bool scan(int len){
			NODE* p = root;
			int len_t=0;
			FOR(i, len){
				len_t++;
				if(ori[i] == exp[len_e-1] && len_t>=len_e){
					bool flag = true;
					NODE* t = p->next;
					FOR(j, len_e-1){
						if(p->c!=exp[len_e-j-2]){
							flag = false;
							break;
						}
						p = p->prev;
					}
					if (flag == true)
						return true;
					else
						p = t;
				}
				p = p->next;
			}
			return false;
		}
};
int main(){
	string original;
	string explode;
	cin>>explode>>original;
	Stack stack(original, explode); //initialize
	stack.push();
	int len=0, tlen=-1;
	while(1){
		len = stack.rm_front(stack.len_r);
		if(!stack.scan(len)){
			stack.print();
			return 0;
		}
	}
}
