#include <iostream>
using namespace std;
class tempClass{
	private:
		tempClass(int n) : num(n){}
		int num;
	public:
		tempClass() : num(0){}
		tempClass& CreateInitObj(int n) const{
			tempClass * ptr = new tempClass(n);
			return *ptr;
		}
		void showNum() const {
			cout<<num<<endl;
		}
};

int main(){
	tempClass temp;
	temp.showNum();
	tempClass ptr = temp.CreateInitObj(10);
	ptr.showNum();
}
