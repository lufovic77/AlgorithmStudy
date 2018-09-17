#include <iostream>
using namespace std;
class Point{
	public:
		Point(int x , int y){
			this->x = x;
			this->y = y;
		}
		void print(){
			cout<<x<<" "<<y<<endl;
		}
	private:
		int x;
		int y;
};
class Rectangle{
	private:
		Point one;
		Point two;
	public:
		int hello;
		Rectangle();
		void printPoint(){
			one.print();
		}
};
Rectangle::Rectangle() : one(1, 2), two(3, 4){
	cout<<"done?";
}
int main(){
	Rectangle rec;
	rec.printPoint();
}
