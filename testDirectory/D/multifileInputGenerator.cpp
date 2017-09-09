#include<cstdio>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;

int getRandom(int a,int b){
    long long ret = rand()*rand();
    ret %= (b - a + 1);
    ret += a;
    return ret;
}

void writeSingleCase(int n){
    int m = getRandom(n, 10*n);
    printf("%d\n%d\n",n, m);
    while(m--){
        int u = getRandom(0,n-1);
        int v = getRandom(0,n-1);
        printf("%d %d\n",u,v);
    }
}

int main(){
    char fileName[100];
    int i,cs = 5;
    srand(time(NULL));
    for(i=1;i<=cs;i++){
        sprintf(fileName,"%d.in",i);
        freopen(fileName,"w",stdout);
        if(i<=1)writeSingleCase(5);
        else if(i<=3)writeSingleCase(10);
        else if(i<=5)writeSingleCase(1000);
    }
}
