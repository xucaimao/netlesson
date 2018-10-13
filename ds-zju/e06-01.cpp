/*中国大学MOOC-陈越、何钦铭-数据结构-2018秋
 * 06-图1 列出连通集 （25 分)
 * wirte by xucaimao,2018-10-11
 *
 * */

#include <iostream>
#include <cstdio>
#include <cstring>  //memset
#include <queue>
using namespace std;
const int maxn=15;
int G[maxn][maxn];
int vis[maxn];
int M[maxn],pM; //用于记录联通图的数组及指针
int N;


void dfs(int u,int id){
    if(vis[u])return;//点u被访问过
    vis[u]=id;  //设置访问标志
    M[pM++]=u;  //记录联通图
    for(int j=0;j<N;j++){//访问与u相邻的各个点
        if(j!=u && G[u][j] )
            dfs(j,id);  //从这一点开始往下访问
    }
}

void bfs(int i,int id){
    if(vis[i]) return;  //点i被访问过
    queue<int> q;
    q.push(i);
    vis[i]=id;  //进队列就要记录
    while(!q.empty()){
        int u=q.front();
        M[pM++]=u;
        q.pop();
        for(int j=0;j<N;j++){//访问与u相邻的各个点
            if(j!=u && G[u][j] && vis[j]==0){
                q.push(j);  //从这一点开始往下访问
                vis[j]=id;
            }
        }
    }

}

int main(){
    freopen("/Users/xcm/xcmprogram/netlesson/ds-zju/in.txt","r",stdin);
    int E;
    scanf("%d %d",&N,&E);
    memset(G, 0,sizeof(G));
    for(int i=0;i<E;i++){   //记录E条边
        int v,w;
        scanf("%d %d",&v,&w);
        G[v][w]=1;
        G[w][v]=1;
    }
    //开始dfs
    memset(vis,0, sizeof(vis));
    int cnt=0;
    for(int i=0;i<N;i++){
        pM=0;
        dfs(i,++cnt);
        if(pM){
            printf("{ ");
            for(int i=0;i<pM;i++)
                printf("%d ",M[i]);
            printf("}\n");
        }
    }

    //开始bfs
    memset(vis,0, sizeof(vis));
    cnt=0;
    for(int i=0;i<N;i++){
        pM=0;
        bfs(i,++cnt);
        if(pM){
            printf("{ ");
            for(int i=0;i<pM;i++)
                printf("%d ",M[i]);
            printf("}\n");
        }
    }
    return 0;
}