#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

int vow(char *str){
for(int i=0; str[i];i++){
    if(str[i]==' ')
        str[i]='z' ;

}

static int n=0;
    int count=0;

    if(!*str) return count;
       
    else if(*str=='a'||*str=='e'||*str=='i'||*str=='o'||*str=='u'){
    count++;
    str++;
    vow(str) ;
    }

}
int main(){
	char *str ;
	int n,count,i,ans;
	fgets(str,sizeof(str),stdin) ;
	
	ans=vow(str) ;
}
