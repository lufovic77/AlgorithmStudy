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
		Stack(string o, string e){
			this->ori = o;
			this->exp = e;
			this->len = o.size();
			this->len_e = e.size();
		}
		void push(){
			NODE* p = NULL;
			FOR(i, len){
				if(ori[i] == exp[len_e-1]){
					bool flag = true;
					NODE* t = p;
					FOR(j, len_e-1){
						fprintf(stderr, "?");
						if(p->c!=exp[len_e-j-2]){
							flag = false;
							break;
						}
						p = p->prev;
					}
					if (flag == true)	
						p->next = NULL;
					else{
						p = t;
						continue;
					}
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
			cout<<p;
			while(p!=NULL){
				cout<<p->c<<endl;
				p = p->next;
			}	
		}
		
};
int main(){
	string original;
	string explode;
	cin>>original>>explode;
	Stack stack(original, explode); //initialize
	stack.push();
	stack.print();
}
