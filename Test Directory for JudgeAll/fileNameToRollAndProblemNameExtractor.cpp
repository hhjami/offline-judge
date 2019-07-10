#include<bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]){
    string fileName;
    if(argc == 1) cin>>fileName;
    else fileName = argv[1];
    int l = strlen("submissions/");
    fileName = fileName.substr(l, fileName.length() - l);
    int roll;
    char problemName[2];
    sscanf(fileName.c_str(),"%d_%1s", &roll, problemName);
    problemName[0] = toupper(problemName[0]);
    cout<<roll<<endl<<problemName<<endl;
    return 0;
}
