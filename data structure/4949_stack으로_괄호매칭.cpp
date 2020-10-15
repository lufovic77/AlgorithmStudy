#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#define FOR(i, n) for(int i=0;i<n;i++)
using namespace std;
/*
 * 입력함수의 교훈
 * 1. getline(cin, string): 띄어쓰기도 포용하는 넓은 친구이지만, 엔터(\n)도 입력으로 받아버린다. 
 * 2. scanf: 모두가 알듯이 띄어쓰기가 나오면 입력을 멈춘다. 
 * 3. gets: getline과 scanf의 가운데. 공백도 포용하며, 엔터도 생략해서 받는다. i
 * */
int main(){
	bool flag;
	while(1){
		bool flag = false;
		string input;
		stack <char>st;
		getline(cin, input);
		if(input[0]=='.')
			return 0;
		FOR(i, input.length()){
			flag = true;
			if(input[i]=='(' || input[i]=='['){
				st.push(input[i]);
				continue;
			}
			else if (input[i]==')'){
				if(st.empty()){
					printf("no\n");
					st.push('f');
					break;
				}
				if(st.top()=='('){
					st.pop();
					continue;
				}
				else{
					printf("no\n");
					break;
				}
			}
			else if(input[i]==']'){
				if(st.empty()){
					printf("no\n");
					st.push('f');
					break;
				}
				if(st.top()=='['){
					st.pop();
					continue;
				}
				else{
					printf("no\n");
					break;
				}
			}
			else
				continue;
		}
		if(flag&&st.empty())
			printf("yes\n");
			
	}
}
