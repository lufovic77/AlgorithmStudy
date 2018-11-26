#include <iostream>
using namespace std;
class simpleClass{
	private:
		int var1;
		int var2;
	public:
		simpleClass(int a, int b): var1(a), var2(b){
		}
		explicit simpleClass (simpleClass &copy): var1(copy.var1), var2(copy.var2){	
		//just copy constructor
		}
		void showMembers(){
			cout<<var1<<endl;
			cout<<var2<<endl;
		}
};
int main(){
	simpleClass obj1(10, 20);
	// simpleClass obj2 = obj2; error occurs here 
	simpleClass obj2(obj1);
	obj1.showMembers();
	obj2.showMembers();
}
