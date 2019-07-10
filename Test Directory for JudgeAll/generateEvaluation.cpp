#include<bits/stdc++.h>
using namespace std;
FILE *in, *out;
int roll, problem, nproblem, casesInEachProblem[100];
double eval[2000][100];
set<int> uniqueRoll;

void getRollAndProblem(char str[1000]){
    char pname[100];
    sscanf(str, "Submitting Problem %s for Roll No: %d", pname, &roll);
    printf("%s %d\n", pname, roll);
    problem = pname[0] - 'A';
    uniqueRoll.insert(roll);
    nproblem = max(nproblem, (problem+1));

}

void processSubmission(){
    char str[1000];
    int len, cs = 0;
    double cnt = 0;
    while(fgets(str, sizeof(str), in)){
        len = strlen(str);
        str[len - 1] = 0;
        len--;
        printf("%s\n", str);
        if(strcmp(str, "End of Submission") == 0) break;
        cs++;
        casesInEachProblem[problem] = cs;
        if(strstr(str, "PASSED")) cnt = cnt + 1;
        if(strstr(str, "White")) cnt = cnt + .5;
    }
    eval[roll][problem] = max(eval[roll][problem], cnt);
}

void outputToFile(){
    printf("%d\n",nproblem);
    int i, j;
    fprintf(out, "Roll");
    for(i = 0; i < nproblem; i++){
        fprintf(out, "\t%c", 'A' + i);
    }
    fprintf(out, "\n");
    for(i = 0; i < nproblem; i++){
        fprintf(out, "\t%d", casesInEachProblem[i]);
    }
    fprintf(out, "\n");
    set<int>::iterator it;
    for(it = uniqueRoll.begin(); it!=uniqueRoll.end(); it++){
        i = *it;
        fprintf(out, "%d", i);
        for(j = 0; j < nproblem; j++){
            fprintf(out, "\t%.1lf",eval[i][j]);
        }
        fprintf(out, "\n");
    }
    
}

int main(){
    in = fopen("allSubmissionVerdicts.txt", "r");
    out = fopen("evaluation.txt", "w");
    char str[1000];
    int len;
    while(fgets(str, sizeof(str), in)){
        len = strlen(str);
        str[len - 1] = 0;
        len--;
        getRollAndProblem(str);
        processSubmission();
    }
    outputToFile();
}
