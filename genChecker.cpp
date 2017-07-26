#include<bits/stdc++.h>
using namespace std;

#define ui64 unsigned long long
ui64 judgeHash[10];
//start_copying_at_this_line
ui64 findHash(char filename[]){
    FILE *fp = fopen(filename,"r");
    ui64 p = 1000000007;
    char c;
    ui64 hash = 0, coeff = 1;
    while((c = fgetc(fp))!=EOF){
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
        else scHash = findHash(file);
        if(!flag && scHash == judgeHash[i-1])printf("Passed\n");
        else printf("Failed\n");
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

void generateCode(ui64 hash[], int cs){
    int i;
    printf("#include<bits/stdc++.h>\n");
    printf("using namespace std;\n");
    printf("#define ui64 unsigned long long\n");
    printf("ui64 judgeHash[] = {");
    for(i = 0; i < cs; i++){
        if(i)printf(",");
        printf("%lluULL",hash[i]);
    }
    printf("};\n");
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
    else cs = 1;

    ui64 hash[cs];
    for(i = 1; i <= cs; i++){
        char file[100];
        sprintf(file,"%d.ans",i);
        hash[i-1] = findHash(file);
    }
    generateCode(hash, cs);
}
