#include <iostream>
using namespace std;
class base{
	private:
		int basenum;
	public:
		base(): basenum(20){
			cout<<"base void"<<endl;
		}
		base(int n): basenum(n){
			cout<<"base one"<<endl;
		}
		void show(){
			cout<<basenum<<endl;
		}
};

class derived : public base{
	private:
		int derivenum;
	public:
		derived(): derivenum(20){	
			cout<<"derived void"<<endl;
		}
		derived(int n): derivenum(n), base(n){
			cout<<"derived one"<<endl;
		}
		derived(int n1, int n2): base(n1), derivenum(n2){//initializer
			cout<<"derived two"<<endl;
		}
		void showbase(){
			show(); //can use the method in base class
			cout<<derivenum<<endl;
		}
};
int main(){
	//derived * d0 = new base; //COMPILE ERROR!!!! invalid conversion
	base * d1 = new base;
	base * d2 = new derived(10);	//COMPILE SUCCESS. 	
}
