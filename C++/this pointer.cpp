#include <iostream>
using namespace std;
class simpleClass{
	private:
		int num;
		int hello1;
		int hello2;
	public:
		simpleClass(int n): num(n){	//constructor
			cout<<num<<", "<<this<<endl;
		}
		simpleClass(int hello1, int hello2){	//name of parameter and private member variables is identical
			this->hello1 = hello1;
			this->hello2 = hello2;
		}
};
int main(){
	simpleClass temp1(1);
	simpleClass temp2(2);
	int num(2);
	cout<<num;
}
