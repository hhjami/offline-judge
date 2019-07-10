#include<stdio.h>
#include<string.h>

unsigned long long int binToDec(char s[],unsigned long long int n, unsigned long long int dec, unsigned long long int t)
{
	if(n<0)
		return dec;
	else if(s[n]=='1')
		dec+=t;
	
	binToDec(s,n-1,dec,(t*2));
		
}


int main()
{
	char s[10000];
	unsigned long long int n, ans;
	
	scanf("%s", s);
	n=strlen(s);
	ans=binToDec(s, n-1, 0,1);
	printf("%llu\n",ans);
	return 0;
}
