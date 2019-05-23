#include <iostream>
#include <string>
#include <limits.h>
#include <vector>
#include  <stdlib.h>
#include <cstdio>


using namespace std;
int main(){
    string line;
    getline(cin, line); //input one string 
    int total = 0;
    int left=0, right=0;
    int index = -1;
    
    int indexM = -1;
    
    vector <int> num (50, INT_MAX);
    string temp;
    for(int i=0;i<line.length();i++){
        if(line[i] == '+'){
            index++;
            right = i;

            temp = line.substr(left, right);
            num[index] = stoi(temp);

            left = right;
            left++;
            //right++;
        }
        else if(line[i]=='-'){
            index++;
            if(indexM == -1)
            indexM = index;

            right = i;

            temp = line.substr(left, right);
            num[index] = stoi(temp);
            left = right;
            left++;
        }  
    }
    num[++index] = stoi(line.substr(left,line.length()));
    if(indexM == -1)
    indexM = index;
    for(int i=0;i<=indexM;i++)
    total += num[i];
    indexM++;
    for(int i=indexM;num[i]!=INT_MAX;i++){
        total -= num[i];
    }
    cout<< total;
}