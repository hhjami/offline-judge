#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

int maxnum(int n,int max){
	if (n==0) return max;
	int last = n%10 ;
	if(last>=max) max=last ;
	n=n/10 ;
	return maxnum(n,max) ;
}
int main(){
	
	int n,count,i,ans,t;
	scanf("%d",&t) ;
	while(t--){
		scanf("%d",&n);
	
		if(n==0) ans=0;
		else ans=maxnum(n,-1) ;
	printf("%d\n",ans) ;
}
}
