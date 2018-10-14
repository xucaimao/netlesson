/*中国大学MOOC-陈越、何钦铭-数据结构-2018秋
 * 06-图3 六度空间 （30 分）
 * wirte by xucaimao,2018-10-13
 *
 * */

#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

const int maxN=10010;
int G[maxN][maxN]={0};
int Level[maxN];    //用于标记节点的层序
int Vis[maxN];
int NumOfVertics;

//从点u开始做bfs
double bfs(int u){
    memset(Level,0, sizeof(Level));
    memset(Vis,0,sizeof(Vis));
    queue<int> q;
    q.push(u);
    Vis[u]=1;
    Level[u]=0;
    int num=1;
    int level=0;
    while(!q.empty()){
        int v=q.front();
        q.pop();
        level=Level[v];

        for(int w=1;level<=5 && w<=NumOfVertics;w++){
            if(G[v][w] && !Vis[w]){
                q.push(w);
                Vis[w]=1;
                Level[w]=level+1;
                num++;
            }
        }
    }
    return (double)num/NumOfVertics;
}

int main(){
    freopen("/Users/xcm/xcmprogram/netlesson/ds-zju/in.txt","r",stdin);
    int M;
    scanf("%d %d",&NumOfVertics,&M);
    for(int i=0;i<M;i++){
        int v,w;
        scanf("%d %d",&v,&w);
        G[v][w]=1;
        G[w][v]=1;
    }
    for(int i=1;i<=NumOfVertics;i++)
        printf("%d: %.2f%%\n",i,bfs(i)*100);
    return 0;
}