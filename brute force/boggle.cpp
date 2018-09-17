#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int dx[8]={1,1,0,-1,-1,-1,0,1};
int dy[8]={0,1,1,1,0,-1,-1,-1};
char board[5][5];
int score[10]={1,1,2,3,5,11};
typedef long long ll;

bool hasWord(int x,int y, const string& word){	//참조자였네 ㅎㅎ.. const 참조자 정리! 
	if(x<0|| y<0 ||x>=4||y>=4)	//이거 overflow도 생각해봐야함.  
		return false;
	if(word[0]!=board[x][y])
		return false;
	if(word.length()==1)//string 사용법 정리!  
		return true;
	
	for(int i=0;i<8;i++){ 
		if(hasWord(x+dx[i], y+dy[i], word.substr(1)))
			return true;
	}
	return false;
}

int main(){
	int w;
	cin>>w;
	string words[300010];
	for(int i=0;i<w;i++){
		cin>>words[i];
	}
	int b;
	cin>>b;
	
	for(int i=0;i<b;i++){
		for(int m=0;m<4;m++){
				cin>>board[m];
		}			
		
		ll max=-1;
		ll count=0;
		string longest;
		ll total=0;
		for(int j=0;j<w;j++){
			int length = words[j].size();
			int flag=0;
			for(int k=0;k<4;k++){
				for(int l=0;l<4;l++){
					if(hasWord(k,l,words[j])){	//find
						count++;
						if(length>=3)
						total+=score[length-3];
						if(max<length){
							max=length;
							longest = words[j];
						}
						else if(max == length){
							if((longest> words[j])){	//이것도 정리 ㅇㅅㅇ;; 
								longest = words[j];
							}
						}	
						flag=1;	
					}
					if(flag==1)
					break;
				}
				if(flag==1)
				break;
			} 
		}
		cout<<total<<" "<<longest<<" "<<count<<endl;
	}
}
