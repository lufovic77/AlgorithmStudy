#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<pair<int, int> > dp [4002][4002];
int main(){
    string str1, str2;
    cin >> str1 >> str2;
    for(int i=0;i<str1.length();i++){
        const char ch1 = str1[i];
        bool flag = false;
        for(int j=0;j<str2.length();j++){
            if(ch1 == str2[j]){
                dp[i][i].push_back({j, j});
                flag = true;
            }
        }
        if(!flag){
            dp[i][i].push_back({-1, -1});
        }
    }
    for(int i=1;i<str1.length();i++){
        for(int j=1;j<str1.length();j++){
            if(i==j)
               continue;
            bool flag2 = false;
            for(auto temp1 : dp[i][j-1]){
                int left1 = temp1.first, right1 = temp1.second;
                if(left1 == -1)
                break;
                for(auto temp2: dp[j][j]){
                    int left2 = temp2.first, right2 = temp2.second;
                    if(left2 == -1)
                    break;
                    if(left1 - 1 == right2){
                        dp[i][j].push_back({left2, right1});
                        flag2 = true;
                    }
                    else if (right1 + 1 == left2){
                        dp[i][j].push_back({left1, right2});
                        flag2 = true;
                    }
                }
            }
            if(!flag2){
                dp[i][j].push_back({-1, -1});
            }
        }
    }
    int max = -1;
    for(int i=1;i<str1.length();i++){
        for(int j=1;j<str1.length();j++){
            auto temp = dp[i][j];
            int left1 = temp.first, right1 = temp.second;
            if(left1 == -1)
                continue;
            else{
                int len = right1-left1+1;
                if(max<len)
                max = len;
            }
        }
    }
    cout<<max;
}