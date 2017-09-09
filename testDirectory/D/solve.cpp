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

vector<int> g[2][MX], nd, comp;
int vi[MX], sz;

void dfs(int u,int idx){
    vi[u] = 1;
    int i,v;
    for(i=0;i<g[idx][u].size();i++){
        v = g[idx][u][i];
        if(!vi[v])dfs(v,idx);
    }
    if(!idx)nd.pb(u);
    else comp.pb(u);
}


int main(){
    int n,m,u,v,i,j;
    scanf("%d %d",&n, &m);
    while(m--){
        scanf("%d %d",&u,&v);
        g[0][u].pb(v);
        g[1][v].pb(u);
    }

    for(i=0;i<n;i++){
        if(!vi[i])dfs(i,0);
    }
    CLR(vi);
    reverse(nd.begin(),nd.end());
    for(i=0;i<n;i++){
        if(!vi[nd[i]]){
            comp.clear();
            dfs(nd[i],1);
            //sort(comp.begin(),comp.end());
            for(j=0;j<comp.size();j++){
                if(j)printf(" ");
                printf("%d",comp[j]);
            }
            printf("\n");
        }
    }
    return 0;
}


