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
	public:
		int len_r;
		NODE* root;
		NODE* rear;
		Stack(string o, string e){
			this->ori = o;
			this->exp = e;
			this->len = o.size();
			this->len_e = e.size();
			len_r = 0;

		}
		void push(){
			len_r = 0;
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
			rear = p;
		}
		void print(){
			NODE* p = root;
			while(p!=NULL){
				cout<<p->c;
				p = p->next;
			}
			if(root==NULL)
				cout<<"";
		}
		int rm(int len, int f){
			NODE* p;
			if(f==0)
				p = root;
			else
				p = rear;
			int len_t=0;
			FOR(i, len){
				len_t++;
				if((f==0 && p->c == exp[len_e-1] && len_t>=len_e) || (f==1 && p->c == exp[len_e-1]&&len_t+len_e<=len_r+1)){
					bool flag = true;
					NODE* t = p->next;
					NODE* tt = p;
					FOR(j, len_e){
						if(p->c!=exp[len_e-j-1]){
							flag = false;
							break;
						}
						p = p->prev;
					}
					if (flag == true){	
						if(p==NULL)
							root = t;
						else
						p->next = t;
						if(t!=NULL)
							t->prev = p;
						else
							rear = p;
						len_t-=len_e;
						len_r-=len_e;
						return len_r;
					}
					else{
						p = tt;
					}
				}
				if(f==0)
					p = p->next;
				else
					p = p->prev;
			}
			return len_r;
		}
		bool scan(int len){
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
					if (flag == true)
						return true;
					else{
						p = t;
						continue;
					}
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
	int len=0, t=0, cnt=0;
	while(1){
		if(!stack.scan(stack.len_r)){
			stack.print();
			return 0;
		}
		len = stack.rm(stack.len_r,t++);
		t%=2;
	}
}
