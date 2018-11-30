#include <iostream>
using namespace std;
class simpleClass{
	private:
		int num;
	public:
		simpleClass(int n): num(n){
		}
		simpleClass(const simpleClass&copy):num(copy.num){
		}
		simpleClass & addNum(int n){
			num+=n;
			return *this; 	//object itself.(dereference the this pointer) 
		}
		void showData(){
			cout<<"num: "<<num<<endl;
		}
};
simpleClass simpleFunc(simpleClass ob){
	return ob;
}

int main(){
	simpleClass obj(7);
	simpleFunc(obj).addNum(30).showData();
	simpleFunc(obj).showData();
	obj.showData();
}
