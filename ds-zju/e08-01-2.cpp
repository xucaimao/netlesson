/*中国大学MOOC-陈越、何钦铭-数据结构-2017秋
 * 08-图7 公路村村通
 * 网上程序，编程很简单，按Prime的原理实现，容易理解
 * 和dijkstra算法非常类似，只是在最终的转换方程上有所区别
 * 考察知识点--最小生成树
 * 扩充了记录路径及打印的功能
 * */

#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#define MAX 7
const int INFINITY=99999999;
using namespace std;

int G[MAX][MAX];
int dist[MAX];
int path[MAX];

int findmin(int N){
    //采用遍历的方式查找，没有采用最小堆
    int minV;
    int mindist = INFINITY;
    for(int V = 1; V <= N; V++) {
        //节点没有被访问 && 比当前最小值小
        if(dist[V] != 0 && dist[V] < mindist) {
            mindist = dist[V];
            minV = V;
        }
    }
    if(mindist < INFINITY)
        return minV;
    else
        return -1;
}

int prim(int S, int N) {
    int V;
    for(V = 1; V <= N; V++) {
        dist[V] = G[1][V];  // dist[v]=C(s, v) 当sv连通时; dist[v]=INFINITY  当sv不连通时;
        path[V]=-1;
    }
    int allweight = 0,Vcount = 0;
    dist[S] = 0;
    Vcount++;
    //遍历起点的邻接点,设置初始条件
    for(int i=1;i<=N;i++)
        if(i!=S && G[S][i]<INFINITY){
            path[i]=S;
            dist[i]=G[S][i];
        }

    while(1){
        V = findmin(N);     //找到未被收录的权值最小的点
        if(V < 0) break;    //没有找到
        allweight += dist[V];
        Vcount++;
        dist[V] = 0;    //把V收入已访问

        for(int W = 1; W <= N; W++) {   //遍历V的邻接点
            if(G[V][W] < INFINITY){
                //W没有被访问 &&
                if(dist[W] != 0 && G[V][W] < dist[W]){
                    dist[W] = G[V][W];
                    path[W] = V;
                }
            }
        }
    }

    if(Vcount < N){
        return -1;
    }
    return allweight;
}

int main(void){
    freopen("/Users/xcm/xcmprogram/netlesson/ds-zju/in.txt","r",stdin);
    int N,M;
    int v1,v2,weight;
    scanf("%d%d",&N,&M);
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++)
            G[i][j] = INFINITY; //初始化所有节点间的权重为无穷大
    }
    for(int i = 0; i < M; i++){
        scanf("%d%d%d",&v1,&v2,&weight);
        G[v1][v2] = G[v2][v1] = weight;
    }

    int tot = prim(1,N);
    printf("%d\n",tot);

    for(int i=2;i<=N;i++)
        printf("(%d-%d :%d)\t",path[i],i,G[i][path[i]]);
    printf("\n");
    return 0;
}

