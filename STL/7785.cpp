#include <iostream>
#include <queue>
#include <string>

using namespace std;

unsigned long hashing(const char *key, int num_partitions) {
    unsigned long hash = 5381;
    int c;
    while ((c = *key++) != '\0')
        hash = hash * 33 + c;
    return hash % num_partitions;
}
int main(){
	priority_queue< string, vector<string>, less<string> > pq;
	string str="hello";
	pq.push(str);
	cout<<pq.top()<<endl;
	
	const char * c = str.c_str();
	cout<<hashing(c, 1000);
	
}
