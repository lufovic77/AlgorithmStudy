#include <iostream>
#include <queue>
using namespace std;
typedef unsigned long long ull;
int main(){
    ull num[110];
    num[0] = 1;
    num[1] = 1;
    num[2] = 1;
    num[3] = 2;
    num[4] = 2;
    num[5] = 3;
    for(int i=6;i<=100;i++){
        num[i] = num[i-1] + num[i-5];
    }
    int t;
    cin>>t;
    int n;
    queue<ull> q;
    for(int i=0;i<t;i++){
        cin>>n;
        q.push(n);
    }
    for(int i=0;i<t;i++){
        cout<<num[q.front()-1]<<endl;
        q.pop();
    }
}