/*中国大学MOOC-陈越、何钦铭-数据结构-2017秋
 * 08-图8 How Long Does It Take （25 分）
 * wirte by xucaimao,2018-10-23
 * 考察知识点--拓扑排序及关键路径
 * 注意边的权重最小为0
 * 注意图中可能有多个起点和重点，所以必须采用记录最大值的方式
 * 而不能采用返回最后点的值的方式
 * */
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int maxN=110;
int G[maxN][maxN];
int inDegree[maxN];
int vertexEarlyTime[maxN];   //用于记录最早开始时间
int sortedVertex[maxN]; //用于记录拓扑序的序列
int N,M;
queue<int> inDegZero;

int TopoSort(){
    int ans=0;
    //对于图中的每一个顶点，如果入度为0则入队列
    for(int i=0;i<N;i++){
        if(inDegree[i]==0){
            inDegZero.push(i);
        }
    }
    int visitedNum=0;//用于记录访问过的顶点数量
    while(!inDegZero.empty()){
        //取一个入度为0的顶点v
        int v=inDegZero.front();
        inDegZero.pop();
        sortedVertex[visitedNum]=v;
        visitedNum++;
        //遍历v的所有邻接点w
        for(int w=0;w<N;w++)
            if(G[v][w]!=-1){    //注意这里判断有边存在的条件
                inDegree[w]--;
                if(inDegree[w]==0)
                    inDegZero.push(w);
                vertexEarlyTime[w]= max( vertexEarlyTime[w] , vertexEarlyTime[v]+G[v][w] );
                if(vertexEarlyTime[w]>ans)  //记录最大值
                    ans=vertexEarlyTime[w];
            }
    }
    if(visitedNum!=N)
        ans=-1;
    return ans;
}

int main(){
    freopen("/Users/xcm/xcmprogram/netlesson/ds-zju/in.txt","r",stdin);
    memset(G,-1, sizeof(G));    //有的边权重为0
    memset(vertexEarlyTime,0,sizeof(vertexEarlyTime));
    memset(inDegree,0, sizeof(inDegree));
    cin>>N>>M;
    int u,v,w;
    //读入图数据并初始化入度
    for(int i=0;i<M;i++){
        cin>>u>>v>>w;
        inDegree[v]++;
        G[u][v]=w;
    }
    int ans=TopoSort();
    if(ans==-1)
        cout<<"Impossible"<<endl;
    else
        cout<<ans<<endl;
    return 0;
}