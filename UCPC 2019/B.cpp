#include <iostream>
#include <map>
using namespace std;
int main(){
    map <int, int> conversion;
    conversion[46] = 46;
    conversion[79] = 79;
    conversion[45] = 124;
    conversion[124] = 45;
    conversion[47] = 92;
    conversion[92] = 47;
    conversion[94] = 60;
    conversion[60] = 118;
    conversion[118] = 62;
    conversion[62] = 94;

    int m, n;
    cin>> m>> n;
    char map1[110][110];
    char map2[110][110];

    for(int i=0;i<m;i++)
    for(int j=0;j<n;j++)
    cin >> map1[i][j];

    for(int i=0;i<m;i++)
    for(int j=0;j<n;j++){
        map2[n-j-1][i] = conversion[map1[i][j]];
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<map2[i][j];
        }
        cout<<endl;
    }

}