#include<stdio.h>
#include<string.h>

int maxDig(int a, int max)
{
	if(!a)
		return max;
	else if((a%10)>max)
		max = (a%10);
		
		
	a/=10;
	return maxDig(a,max);

}


int main()
{
	int a,b,t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&a);
		b=maxDig(a,0);
		printf("%d\n",b);
	}
	return 0;
}
