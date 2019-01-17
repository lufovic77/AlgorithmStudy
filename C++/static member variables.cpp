#include <iostream>
using namespace std;
class person{
	public:
		//static int age = 23; compile error
		static int age;
	public:
		/*	Also compile error. Must be initalized once.
		void setAge(int n): age(n){
		}
		*/
};
int person::age = 23;	//must be defined outside of the class
int main(){
	person kyungmin;
	cout<<kyungmin.age<<endl;	
	person someOther;
	cout<<someOther.age<<endl;	//Same result with object kyungmin.
}
