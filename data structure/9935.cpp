#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
typedef struct node{
	struct node* next;
	struct node* prev;
	char c;
}NODE;
class Stack{
	private:
		int len; //len of original string
		string ori;
		string exp;
		NODE* root;
	public:
		Stack(string o, string e){
			this->ori = o;
			this->exp = e;
			this->len = o.size();
			this->root=(NODE*)malloc(sizeof(NODE));
			this->root->c = ori[0];
		}
		void push(){
			NODE* p = this->root;
			for(int i=1;i<len;i++){
				NODE* tmp=(NODE*)malloc(sizeof(NODE));
				tmp->c = ori[i];
				tmp->prev = p;
				tmp->next = NULL;
				p->next = tmp;
				p=tmp;
			}
		}
		void print(){
			NODE* p = root;
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
