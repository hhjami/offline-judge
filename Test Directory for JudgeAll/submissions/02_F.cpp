
#include<stdio.h>
#include<string.h>
#include<math.h>
#define max(a,b) a>b?a:b
typedef long long lli;
int len_s(char s[],int  count){
	if(s[count]=='\0') return count;
	return len_s(s,count+1);
}
void reverse_string(char s[],int index,int l){
	 if(index>l/2) return;
	 char temp=s[index];
	 s[index]=s[l-index-1];
	 s[l-index-1]=temp;
	 reverse_string(s,index+1,l);
}
int main(){
    char a,s[1000];
    printf("\n");
    gets(s);
    reverse_string(s,0,len_s(s,0));
    printf("%s\n",s);

}