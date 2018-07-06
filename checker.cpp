#include<bits/stdc++.h>
using namespace std;
#define ui64 unsigned long long
#define ACTUAL 0
#define WSIG 1
#define CSIG 2
ui64           judgeActualHash[] = {          10000000126ULL, 15016765479445928360ULL};
ui64         judgeWSIgnoreHash[] = {                   56ULL, 11723863469077744606ULL};
ui64    judgeWS_CaseIgnoreHash[] = {                   56ULL, 11723863469077744638ULL};

bool isWS(char c){
    return c == ' ' || c == '\n' || c == '\r' || c == '\t';
}

ui64 findHash(char filename[], int flag = ACTUAL){
    FILE *fp = fopen(filename,"r");
    ui64 p = 1000000007;
    char c;
    ui64 hash = 0, coeff = 1;
    while((c = fgetc(fp))!=EOF){
        if(isWS(c) && (flag & WSIG))continue;
        if(isalpha(c) && (flag & CSIG)) c = tolower(c);
        hash += (c * coeff);
        coeff *= p;
    }
    fclose(fp);
    return hash;
}

void check(int cs){
    int i;
    ui64 scHash;
    for(i = 1; i <= cs; i++){
        char file[100],infile[100];
        sprintf(file,"%d.out",i);
        sprintf(infile,"%d.in",i);
        printf("Case %d: ",i);
        FILE *fp;
        int flag = 0;
        if((fp = fopen(infile, "r")) == NULL) flag = 1;
        if(flag) printf("Input File Missing!!!\n");
        else{
            scHash = findHash(file);
            if(scHash == judgeActualHash[i-1])printf("Passed\n");
            else{
                scHash = findHash(file, WSIG);
                if(scHash == judgeWSIgnoreHash[i-1])printf("White Space Error\n");
                else{
                    scHash = findHash(file, WSIG | CSIG);
                    if(scHash == judgeWS_CaseIgnoreHash[i-1])printf("Upper/Lower Case Error\n");
                    else printf("!!!!!!!!!!!!!!FAILED!!!!!!!!!!!!!\n");
                }
            }
        }
    }
}
int main(){
	check(2);
	return 0;
}
