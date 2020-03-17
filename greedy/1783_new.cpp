#include <iostream>
#include <cstdlib>
using namespace std;
int main(){
	int height, width;
	cin>>height>>width;	

	if(height ==1 ){
		cout<<1;
		return 0;
	}
	if(height == 2){
		cout << min(4, ((width+1)/2));
		return 0;
	}
	//hegith >=3
	if(width < 7){
		cout<<min(4, width);
		return 0;
	}
	else		
		cout<<width -2;
}
