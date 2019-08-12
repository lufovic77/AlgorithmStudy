#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
int main(){
    int wall, o1, o2, it;
    cin >> wall >> o1 >> o2 >> it;
    vector<int> order;
    for(int i=0;i<it;i++){
        int temp;
        cin>> temp;
        order.push_back(temp);
    }
    pair<int, pair<int, int> > status = {o1,  {o2, 0}} ;
    for (auto content: order){
        int first = status.first;
        int second = status.second.first;
        if (content == first || content == second){ //opened case
            continue;
        }
        int diff1 = abs(content - first);
        int diff2 = abs(content - second);
        bool flag = (diff1 > diff2) ? true : false;
        /*
        true: closer to second
        dalse: closer to first
        */
        if(flag) { //true

        }
        else{

        }
    }
}





