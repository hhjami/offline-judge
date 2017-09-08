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

int topo[MX],pos[MX];

int main(int argc, char *argv[]){
	int a,b,i,j,n,m,u,v;
	FILE *in = fopen(argv[1],"r");
	freopen(argv[2], "r",stdin);
	a=0;	
	while(scanf("%d",&topo[a])==1){
		pos[topo[a]]=a;
		a++;
	}
	fscanf(in,"%d %d",&n,&m);
	if(a!=n)return 0;
	while(m--){
		fscanf(in,"%d %d",&u, &v);
		if(pos[u]>pos[v])return 0;
	}
	cout<<"+Accepted"<<endl;
	return 0;
}

