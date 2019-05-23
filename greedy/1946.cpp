#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t-- >0){
        int n;
        int total = 1; //first one
        cin>>n;
        vector <pair <int, int> > rank;
        for(int i=0;i<n;i++){
            int a, b;
            cin >> a >> b;
            rank.push_back({a, b});
        }
        sort(rank.begin(), rank.end());
        int minimum = rank[0].second;
        for (int i=1;i<rank.size();i++){
            int now = rank[i].second;
            if(now<minimum){
                total++;
                minimum = now;
            }
            
        }
        cout<<total<<endl;
    }
}