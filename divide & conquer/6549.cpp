#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll height[100010];
ll maxi(ll a, ll b){
	if(a>=b)return a;
	else return b;
}
ll mini(ll a, ll b){
	if(a<=b)return a;	
	else return b;
}
ll traverse(ll left, ll right){
	if(left == right)
	return height[left];
	
	ll mid = (left+right)/2;
	ll area = maxi(traverse(left,mid), traverse(mid+1, right));
	
	ll low, high;
	low = mid; high = mid+1;
	ll minHeight = mini(height[low], height[high]);
	ll width = 2;
	area = maxi(width*minHeight, area);
	while(left<low || high<right ){
		if(high < right &&(low == left || height[low-1] < height[high+1] )){
			high++;width++;
			if (minHeight>height[high])
			minHeight = height[high];
			area = maxi(area, width*minHeight);
		}
		else if(left<low &&(right ==high || height[low-1] > height[high+1]) ){	//왼쪽이 더 높은 경우 
			low--;width++;
			if (minHeight>height[low])
			minHeight = height[low];
			area = maxi(area, width*minHeight);
		}
		else{
			high ++; low--; width+=2;
			if (minHeight>height[low])
			minHeight = height[low];
			area = maxi(area, width*minHeight);
			
		}
	}
	return area;
	
}

int main(){
	ll n;
	while(1){
		cin>>n;
		if(n==0)
		exit(0);
		height[0]=-1;height[n+1]=-1;
		fill(height, height+100009, 0);	
		for(ll i=1;i<=n;i++)
		cin>>height[i];
		cout<<traverse(1, n)<<endl;		
	}
}
