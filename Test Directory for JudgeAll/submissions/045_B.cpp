#include<stdio.h>

int Max(int a, int max)
{
    int n;
    if(a == 0)
        return max;
   if(a%10> max)
      max = a%10;
    a = a / 10;
    Max(a, max);
}

int main()
{
    int t,a,res;
    scanf("%d", &t);
    while(t--)
    {
          scanf("%d",&a);
          res = Max(a,0);
          printf("%d\n",res);
    }
}
