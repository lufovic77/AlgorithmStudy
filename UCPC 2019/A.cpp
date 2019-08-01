#include <iostream>
using namespace std;
int main(){
    int bigInt;
    cin >> bigInt;
    if(bigInt <=5)
    cout<<bigInt;
    else{
        bigInt-=5;
        int mok = bigInt/4;
        int rem = bigInt%4;
        if(rem ==0 ){
            if(mok%2 ==1)
                cout<<"1";
            else
                cout<<"5";
        }
        else{
            if(mok%2 ==0){
                cout<<(5-rem);
            }
            else{
                cout<<rem+1;
            }
        }
    }
}