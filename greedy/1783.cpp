#include <iostream>
using namespace std;
//어차피 세로 길이를 두배로 늘리면 위로만 가는 케이스랑 다를바가 없다. 
typedef unsigned long long ll;
int main(){
    ll n, m;
    cin>>n>>m;

    ll total = 0;
    ll flag = 0;
    if(m<=2 && n<=2){
        cout <<"1";
        return 0;
    }
    n *= 2;
    if(n>=6 && m>=6){
        n -= 6;
        m -= 6;
        total = 4; 
        flag = 1;
    }
    if(n>=m){
        n /= 2;
        if(n>m){
            total += m;
        }
        else{
            total+=n;
        }
        if(total>4 && flag == 0)
        total = 4;
    }
    else{
        m /= 2;
        if(m>n){
            total += n;
        }
        else{
            total+=m;
        }
        if(total>4 && flag == 0)
        total = 4;
    } 
    cout<<total;
}
