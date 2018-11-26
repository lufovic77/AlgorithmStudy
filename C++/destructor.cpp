#include <iostream>
using namespace std;
class tempClass{
	private:
		int num;
		char * cheese;
	public:
		tempClass(int n): num(n){
			cheese = new char[n];
			cin >> cheese;
		}
		void showCheese(){
			cout<<cheese<<endl;
		}
		~tempClass(){
			delete []cheese;
			cout<<"done"<<endl;
		}
};
int main(){
	tempClass recota(10);
	recota.showCheese();
}
