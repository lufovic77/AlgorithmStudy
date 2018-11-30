#include <iostream>
#include <cstring>
using namespace std;
class person{
	private:
		char * name;
		int age;
	public:
		person (char * myname, int myage){
			int len = strlen(myname);
			name = new char[len];
			strcpy(name, myname);
			age = myage;
		}		
		~person (){
			delete []name;
		}
};
int main(){
	person man1("kim kyung min", 22);
	person man2 = man1;
}
