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
    int m = getRandom(max(1, n - 5), n);
    printf("1"); m--;
    while(m--){
        printf("%d", getRandom(0, 1));
    }
    puts("");
}

int main(){
    char fileName[100];
    int i,cs = 10;//number of cases
    srand(time(NULL));
    for(i=8;i<=cs;i++){
        sprintf(fileName,"%d.in",i);
        freopen(fileName,"w",stdout);
        if(i<=4)writeSingleCase(5);
        else if(i<=5)writeSingleCase(10);
        else if(i<=10)writeSingleCase(63);
    }
}
