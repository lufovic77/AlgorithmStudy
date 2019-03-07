#include <iostream>
using namespace std; 
class parent{
	public:
		int age;
		void print();

};
void parent::print(){
	cout<<"parent"<<endl;
}
class child:parent{
	public:
		void print(){
			cout<<"child"<<endl;
		}
};

int main(){
	parent obj1; 
	obj1.print();
	child obj2;
	obj2.print();
}
