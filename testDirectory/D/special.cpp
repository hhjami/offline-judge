#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<stack>
#include<vector>
#include<cctype>
#include<cstdio>
#include<string>
#include<sstream>
#include<cstring>
#include<cstdlib>
#include<fstream>
#include<iterator>
#include<iostream>
#include<algorithm>
#include<cassert>
#include<ctime>

using namespace std;

#pragma comment(linker,"/STACK:16777216")
#pragma warning(disable:4786)

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define myabs(a) ((a)<0?(-(a)):(a))
#define AIN(a, b, c) assert(b <= a && a <= c)
#define pi acos(-1.0)
#define CLR(a) memset(a,0,sizeof(a))
#define SET(a) memset(a,-1,sizeof(a))
#define pb push_back
#define all(a) a.begin(),a.end()
#define ff first
#define ss second
#define eps 1e-9
#define root 1
#define lft 2*idx
#define rgt 2*idx+1
#define cllft lft,st,mid,s,e
#define clrgt rgt,mid+1,ed,s,e
#define inf (1<<29)
#define ii64 long long
#define MX 100002

typedef pair<int,int> pii;

vector<int> comp1[MX],comp2[MX];

string s,tmp;
char str[MX];

bool compare(vector<int> a,vector<int> b){
	int i;
	for(i=0;i<a.size() && i<b.size();i++){
		if(a[i]<b[i])return true;
		else if(a[i]>b[i])return false;
	}
	return a.size() < b.size();
}

int main(){
	//freopen("output.txt","r",stdin);
	//freopen("in.txt","r",stdin);
	int a,b,i,j;
	a = 0;
	while(getline(cin,s)){
		stringstream kin(s);
		while(kin>>tmp){
			int x;
			sscanf(tmp.c_str(),"%d",&x);
			comp1[a].pb(x);
		}
		sort(all(comp1[a]));
		a++;
	}
	sort(comp1, comp1+a, compare);
//	for(i=0;i<a;i++){
//		for(j=0;j<comp1[i].size();j++){
//			cout<<comp1[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	FILE *fp = fopen("output.txt","r");
	b = 0;
	while(fgets(str,MX,fp)){
		stringstream kin(str);
		while(kin>>tmp){
			int x;
			sscanf(tmp.c_str(),"%d",&x);
			comp2[b].pb(x);
		}
		sort(all(comp2[b]));
		b++;
	}
	sort(comp2, comp2+b, compare);
//	for(i=0;i<b;i++){
//		for(j=0;j<comp2[i].size();j++){
//			cout<<comp2[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	if(a!=b)return 0;
	for(i=0;i<a;i++){
		if(comp1[i].size()!=comp2[i].size())return 0;
		for(j=0;j<comp1[i].size();j++){
			if(comp1[i][j]!=comp2[i][j])return 0;
		}
	}
	cout<<"+Accepted"<<endl;
    return 0;
}

