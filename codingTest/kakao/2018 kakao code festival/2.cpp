#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;
double doll[510];
double absoul(double a){
	if(a>=0)
	return a;
	else
	return -a;
}
int main(){
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	cin>>doll[i];
	double min2=210000000;
	int index=0;
	double mean2;
	double sum=0;
	int q =k, w;
	for(int h=q;h<=n;h++){
		k=h;
		for(int i=0;i<=n-k;i++){
			if(i==0){
				for(int j=0;j<k;j++){
						sum+=doll[j+i];	
				}
			}
			else{
				sum-=doll[i-1];
				sum+=doll[i+k-1];
			}
			double mean = (double)((double)sum/(double)k);
			double sum2=0;
			for(int j=0;j<k;j++){
				double diff = mean - (double)doll[j+i];
				sum2+=absoul(diff);	
			}
			if(min2>sum2){
				mean2 = mean;
				min2 = sum2;
				index = i;
				w = k;
			}
		}
	}
	double total=0;
	for(int i=index;i<index+w;i++){
		double temp = absoul((double)doll[i]-mean2);
		total+=temp*temp;
	}
	total/=(double)w;
	double rst = sqrt(total);
	printf("%.8lf", rst);
}
