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
#define MX 102

typedef pair<int,int> pii;

int n,m;
char mat[MX][MX];
int vi[MX][MX];
int bfs(int sx,int sy){
    queue< pii > q;
    pii u,v;
    int dx, dy, ret = 0;
    if(mat[sx][sy]=='#')return 0;
    vi[sx][sy] = 1;
    q.push( pii(sx,sy) );
    while(!q.empty()){
        u = q.front(); q.pop();
	ret++;
        for(dx = -1; dx<=1; dx++){
            for(dy = -1; dy<=1; dy++){
                if(dx==dy)continue;
                if(dx*dy)continue;
                v = pii (u.ff + dx, u.ss + dy);
                if(v.ff <0 || v.ff >=n || v.ss<0 || v.ss>=m || mat[v.ff][v.ss]=='#' || vi[v.ff][v.ss])continue;
                q.push(v);
                vi[v.ff][v.ss] = 1;
            }
        }
    }
    return ret;
}

int main(){
    scanf("%d %d",&n,&m);
    int i, j, res = 0, tmp;
    for(i=0;i<n;i++)scanf("%s",mat[i]);
    for(i=0;i<n;i++){
	    for(j=0;j<m;j++){
		    if(!vi[i][j]){
			    tmp = bfs(i,j);
			    res = max(res, tmp);
		    }
	    }
    }
    printf("%d\n",res);
    return 0;
}


