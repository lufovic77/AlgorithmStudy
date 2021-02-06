#include <vector>
#include <iostream>
using namespace std;
void func(vector<vector<int> >&v){ //call by reference
	cout<<v[0][1]<<endl;
	v[0][1] = 10;
	return ;
}
void func(vector<vector<int> >v){ //call by value
	cout<<v[0][1]<<endl;
	v[0][1] = 10;
	return ;
}
/*
 * 기본적으로 배열은 포인터이기 때문에 
 * 함수 인자로 넘길 경우 call by value가 불가능하다.
 * 이때, vector로 이차원 배열을 만들어서 넘긴다면 ?
 * 참조자 성격을 가지게 한는 &를 빼고 넘긴다면 
 * 충분히 call by value가 가능하다. 
 * */
int main(){
	vector<vector<int> > v;
	vector<int> tmp = {1,2,3,4,5};
	v.push_back(tmp);
	func(v);
	cout<<v[0][1];
}
