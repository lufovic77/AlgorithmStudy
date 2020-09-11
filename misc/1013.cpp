#include <iostream>
#include <string>
using namespace std;
string first = "100";
string second = "1";
string third = "01";
int index;
static int count =0;
void generate(string & overall, int len){
	if (len >= 20){
		count ++;
		return ; 
	}
	//cout<<len<<" "<<overall<<endl;
	string temp = overall+first;
	generate(temp, len+3);
	temp = overall+second;
	generate(temp, len+1);
	temp = overall+third;
	generate(temp, len+2);
	return ;
}

int main(){
	string overall = "" ;
	generate(overall, 0);
	cout<<count;
}
