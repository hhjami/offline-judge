
#include<stdio.h>
#include<string.h>
#include<math.h>
#define max(a,b) a>b?a:b
typedef long long lli;
int digit_found(lli n,lli mx){
	if(n==(lli)0){
		 return mx;
	}
	else {
		int m=n%(lli)10;
		digit_found( n/(lli)10,max(mx,m));
	}
}
int main(){
	lli t,n;
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		printf("%lld\n",digit_found(n,(lli)0));

	}
   

}