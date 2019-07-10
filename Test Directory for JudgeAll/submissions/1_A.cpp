#include<stdio.h>
#include<string.h>

int numVowel(char s[], int i, int n, int ans)
{
	if(i==n)
		return ans;
	else if(s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U' || s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
		return numVowel(s,++i,n, ++ans);
	else
		return numVowel(s,++i,n, ans);
}


int main()
{
	char s[10000];
	int n, i=0, ans;
	
	gets(s);
	n=strlen(s);
	ans=numVowel(s,i,n,0);
	printf("%d\n",ans);
	return 0;
}
