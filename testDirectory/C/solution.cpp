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

vector<int> g[MX];
int vi[MX], flag, topo[MX], sz;

void dfs(int u){
    vi[u] = 1;
    int i,v;
    for(i=0;i<g[u].size();i++){
        v = g[u][i];
        if(!vi[v])dfs(v);
        else if(vi[v]==1) flag = 1;
    }
    vi[u] = 2;
    topo[sz++]=u;
}


int main(){
    int n,m,u,v,i;
    scanf("%d %d",&n, &m);
    while(m--){
        scanf("%d %d",&u,&v);
        g[u].pb(v);
    }

    for(i=0;i<n;i++){
        if(!vi[i])dfs(i);
    }
    assert(!flag);
    for(i=n-1;i>=0;i--)printf("%d\n",topo[i]);
    return 0;
}


