/*中国大学MOOC-陈越、何钦铭-数据结构-2017秋
 * 07-图6 旅游规划 （25 分）
 * 有权图的单源最短路问题，有两个权重
 * wirte by xucaimao,2018-10-20
 * */
#include <cstdio>
#include <cstring>
const int maxN=510;
const int INFINITY=99999999;
struct Node{
    int dist;
    int cost;
};

Node G[maxN][maxN];
int dist[maxN];
int cost[maxN];
int path[maxN];
int collected[maxN];

int N,M,S,D;


int findMinInUncollected(){
    //采用遍历所有节点的方式，查找没有被收录节点中的最小值
    //返回-1说明没有找到节点
    int ans=-1;
    int min=INFINITY;
    for(int i=0;i<maxN;i++){
        if(collected[i]==0){//i未被收录
            if(dist[i]<min){
                ans=i;
                min=dist[i];
            }
            else if(dist[i]==dist[ans] && cost[i]<cost[ans]){
                //路径长度相同的情况下，选取花费小的
                ans=i;
                min=dist[i];
            }
        }
    }
    return ans;
}

void dijkstra(int start,int end){
    //初始化
    for(int i=0;i<maxN;i++){
        collected[i]=0;
        dist[i]=INFINITY;
        cost[i]=INFINITY;
        path[i]=-1;
    }
    dist[start]=0;
    cost[start]=0;

    //开始遍历
    while(1){
        int v=findMinInUncollected();
        if(v==-1)break;
        collected[v]=1;
        //遍历v的所有邻接点w
        for(int w=0;w<maxN;w++){
            //存在边，没有被收录
            if(w!=v && G[v][w].dist && !collected[w]){
                if(dist[v]+G[v][w].dist < dist[w]){
                    dist[w]=dist[v]+G[v][w].dist;
                    cost[w]=cost[v]+G[v][w].cost;
                    path[w]=v;
                }
                else if(dist[v]+G[v][w].dist == dist[w] && cost[v]+G[v][w].cost < cost[w]){
                    //路径长度相同的情况下，选取花费小的
                    dist[w]=dist[v]+G[v][w].dist;
                    cost[w]=cost[v]+G[v][w].cost;
                    path[w]=v;
                }
            }
        }
    }
    printf("%d %d\n",dist[end],cost[end]);
}

int main(){
    freopen("F:\\xcmprogram\\netlesson\\ds-zju\\in.txt","r",stdin);
    memset(G,0,sizeof(G));
    scanf("%d %d %d %d",&N,&M,&S,&D);
    int s,d;
    Node nd;
    for(int i=0;i<M;i++){
        scanf("%d %d %d %d",&s,&d,&nd.dist,&nd.cost);
        G[s][d]=nd;
        G[d][s]=nd;
    }
    dijkstra(S,D);
    return 0;
}