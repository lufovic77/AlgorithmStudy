#include <iostream>
using namespace std;
class person{
	private:
		int age;
		int weight;
		int height;
	public:
		char * name;
		void inputInfo(){
			cin>>age>>weight>>height;
		}
		void showInfo(){
			cout<<age<<weight<<height;
		}
};
int main(){
	person arr[3];
	arr[0].inputInfo();
	arr[0].showInfo();
	
	person * ptr[3];
	/*error if not allocated first
	ptr[0].inputInfo();
	ptr[0].showInfo();
	*/
}
