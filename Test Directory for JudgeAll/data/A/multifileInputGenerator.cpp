#include<cstdio>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(){
    char fileName[100];
    int i,cs = 5,strLen=200;//number of cases
    srand(time(NULL));
    for(i=1;i<=cs;i++){
        sprintf(fileName,"%d.in",i);
        freopen(fileName,"w",stdout);
        int len=rand()%strLen;
        for(int j=0;j<len;j++){
			int chi = rand()%90;
			printf("%c",chi+32);
		}
		printf("\n");
    }
}
