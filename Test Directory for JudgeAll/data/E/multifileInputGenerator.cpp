#include<cstdio>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(){
    char fileName[100];
    int i,cs = 5,is=200;//number of cases
    srand(time(NULL));
    for(i=1;i<=cs;i++){
        sprintf(fileName,"%d.in",i);
        freopen(fileName,"w",stdout);
        int total=rand()%is;
        printf("%d\n",total);
        for(int j=0;j<total;j++){
			int num = rand()%10000000;
			printf("%d\n",num);
		}
    }
}
