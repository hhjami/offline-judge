#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
using namespace std;

long long int dec(long long int n,long long int i){
	static long long int ans=0;
	if (n==0) return ans;
	long long int last = n%10 ;
	n=n/10;
	ans= ans+ last* pow(2,i) ;
	
	return dec(n,i+1) ;
}
int main(){
	
	long long int n,count,i,ans,t;
	
		scanf("%lld",&n);
	
		if(n==0) ans=0;
		else ans=dec(n,0) ;
	printf("%lld\n",ans) ;
	
}

