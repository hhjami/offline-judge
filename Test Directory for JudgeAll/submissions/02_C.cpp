
#include<stdio.h>
#include<string.h>
#include<math.h>
#define max(a,b) a>b?a:b
typedef long long lli;
lli len_s(char s[],lli count){
	if(s[count]=='\0') return count;
	return len_s(s,count+(lli)1);
}
lli decimal_convert(char bn[],lli index,lli number,lli count ){
	 if(index == 0 ){
	 	if(bn[index]=='1')
	 		number+=(lli)1*((lli)1<<count) ;
	 	return number;
	 } 
	 else {
	 	if(bn[index]=='1')
	 		number+=(lli)1*((lli)1<<count) ;
	 	return decimal_convert(bn,index-(lli)1,number,count+(lli)1);
	 }
}
int main(){
	char binary[100];
	scanf("%s",binary);
	printf("%lld\n",decimal_convert(binary,len_s(binary,0)-(lli)1,(lli)0,(lli)0));


   

}