#include<cstdio>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;


int getRandom(int a,int b){
    long long ret = rand();
    ret %= (b - a + 1);
    ret += a;
    return ret;
}

void writeSingleCase(int n){
    int m = getRandom(1, n);
    printf("%d\n",m);
}

int main(){
    char fileName[100];
    int i,cs = 5;//number of cases
    srand(time(NULL));
    for(i=1;i<=cs;i++){
        sprintf(fileName,"%d.in",i);
        freopen(fileName,"w",stdout);
        if(i<=1)writeSingleCase(5);
        else if(i<=3)writeSingleCase(10);
        else if(i<=5)writeSingleCase(1000);
    }
}
