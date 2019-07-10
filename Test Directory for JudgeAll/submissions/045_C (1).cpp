#include<stdio.h>
#include<math.h>

long long int Bitodec(long long int x, long long int dec, long long int time)
{
    if(x == 0)
    {
        return dec;
    }
    long long int n = x%10;
    long long int a = n* (pow(2,time));
    time++;
    dec+= a;
    x = x/10;
    Bitodec(x, dec, time);
}

int main()
{
    long long int x;
    scanf("%lld", &x);
    long long int dec = Bitodec(x,0,0);
    printf("%lld\n",dec);
    return 0;
}

