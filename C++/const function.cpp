#include <iostream>
using namespace std;
class simpleClass{
	private:
		int num;
	public:
		simpleClass (){
		}
		simpleClass (int n): num(n){
		}
		simpleClass& addNum(int n){
			this->num += n;
			return *this;	//return type is reference
		}
		void showData() const{
			cout<<"num: "<<num<<endl;
		}
};
int main(){
	const simpleClass obj(10);
	//obj.addNum(7);	//error here(not const)
	obj.showData();		//const member func. no problem
	return 0;
}
