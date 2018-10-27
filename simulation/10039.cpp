#include <iostream>
using namespace std;
int main(){
	int a, total = 0 ;
	for(int i=0;i<5;i++){
		cin >> a;
		if(a<40){
			total += 40;
			continue;
		}
		else{
			total += a;
		}
	}
	cout<<total/5;
	
}
