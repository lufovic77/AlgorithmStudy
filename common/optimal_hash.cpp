#include <iostream>
#include <string>
using namespace std;
unsigned long hash(unsigned char *str){
	unsigned long hash = 5381;
	int c;
	while (c = *str++)
	hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
	return hash;
} //original
unsigned long hashStr(string str){
	unsigned long hash = 5381;
	int c, i;
	i = 0;
	while (c = str[i++])
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
	return hash%500000;
}
int main(){
	string a;
	cin>>a;
	cout<<hashStr(a);
}
