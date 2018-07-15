#include<bits/stdc++.h>
using namespace std;
#define ACTUAL 0
#define WSIG 1
#define CSIG 2
#define ui64 unsigned long long
#define MXCS 100

ui64 aHash[MXCS];//actual hash of the ans file
ui64 wsIgnoreHash[MXCS];//hash of the file while ignoring white spaces
ui64 ws_caseIgnoreHash[MXCS];//hash of the file ignoring white spaces and cases
ui64 judgeActualHash[MXCS];
ui64 judgeWSIgnoreHash[MXCS];
ui64 judgeWS_CaseIgnoreHash[MXCS];
//start_copying_at_this_line

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
        char file[100],infile[100],stsfile[100];
        sprintf(file,"%d.out",i);
        sprintf(infile,"%d.in",i);
        sprintf(stsfile,"%d.status",i);
        printf("Case %d: ",i);
        FILE *fp;
        int flag = 0;
        if((fp = fopen(infile, "r")) == NULL) flag = 1;
        if(flag) printf("Input File Missing!!!\n");
        else{
            FILE *stsfp = fopen(stsfile, "r");
            char sts[100];
            fgets(sts, 100, stsfp);
            if(strncmp(sts, "TLE", 3) == 0) printf("Time Limit Exceeded\n");
            else if(strncmp(sts, "timeout", 7) == 0) printf("Run Time Error\n");
            else {
                scHash = findHash(file);
                if(scHash == judgeActualHash[i-1])printf("*********************PASSED***********************\n");
                else{
                    scHash = findHash(file, WSIG);
                    if(scHash == judgeWSIgnoreHash[i-1])printf("White Space Error\n");
                    else{
                        scHash = findHash(file, WSIG | CSIG);
                        if(scHash == judgeWS_CaseIgnoreHash[i-1])printf("Upper/Lower Case Error\n");
                        else printf("Failed\n");
                    }
                }
            }
        }
    }
}
//stop_copying_at_this_line

void copyFromThisFile(){
    FILE *fp = fopen("genChecker.cpp","r");
    char buffer[10000];
    int flag = 0;
    while(fgets(buffer, 10000, fp)){
        buffer[strlen(buffer)-2]=0;
        if(strcmp(buffer,"//stop_copying_at_this_line")==0) break;
        if(flag)printf("%s\n",buffer);
        if(strcmp(buffer,"//start_copying_at_this_line")==0) flag = 1;
    }
    fclose(fp);
}


void makeHashArrayInCode(string arName, ui64 hash[], int cs){
    printf("ui64 %25s[] = {", arName.c_str());
    for(int i = 0; i < cs; i++){
        if(i)printf(",");
        printf("%21lluULL",hash[i]);
    }
    printf("};\n");
}

void generateCode(int cs){
    int i;
    printf("#include<bits/stdc++.h>\n");
    printf("using namespace std;\n");
    printf("#define ui64 unsigned long long\n");
    printf("#define ACTUAL 0\n");
    printf("#define WSIG 1\n");
    printf("#define CSIG 2\n");
    makeHashArrayInCode("judgeActualHash",aHash, cs);
    makeHashArrayInCode("judgeWSIgnoreHash",wsIgnoreHash, cs);
    makeHashArrayInCode("judgeWS_CaseIgnoreHash",ws_caseIgnoreHash, cs);
    copyFromThisFile();
    printf("int main(){\n");
    printf("\tcheck(%d);\n",cs);
    printf("\treturn 0;\n");
    printf("}\n");
}

int main(int argc, char *argv[]){
    freopen("checker.cpp","w",stdout);
    int cs, i;
    if(argc>1)sscanf(argv[1],"%d",&cs);
    else cs = 2;


    for(i = 1; i <= cs; i++){
        char file[100];
        sprintf(file,"%d.ans",i);
        aHash[i-1] = findHash(file);
        wsIgnoreHash[i-1] = findHash(file, WSIG);
        ws_caseIgnoreHash[i-1] = findHash(file, WSIG | CSIG);
    }
    generateCode(cs);
}
