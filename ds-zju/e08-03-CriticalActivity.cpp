/*中国大学MOOC-陈越、何钦铭-数据结构-2017秋
 * 08-图9 关键活动 （30 分）
 * wirte by xucaimao,2018-10-23
 * 考察知识点--拓扑排序及关键路径
 * 注意边的权重最小为0
 * 注意图中可能有多个起点和重点，所以必须采用记录最大值的方式
 * 而不能采用返回最后点的值的方式
 * 编号从1开始，导致所有的循环都要修改
 * */
//TODO 单起点和单终点，2条关键路径没有通过

#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int maxN=110;
int G[maxN][maxN];
int inDegree[maxN];     //记录顶点的入度
int earliestTime[maxN]; //用于记录最早开始时间
int latestTime[maxN];   //用于记录最晚开始时间
int sortedVertex[maxN]; //用于记录拓扑序的序列
int N,M;
queue<int> inDegZero;

int TopoSortEarlistTime(){
    int ans=0;
    //开始计算最早开始时间
    //对于图中的每一个顶点，如果入度为0则入队列
    for(int i=1;i<=N;i++){
        if(inDegree[i]==0){
            inDegZero.push(i);
        }
    }
    int visitedNum=0;//用于记录访问过的顶点数量
    while(!inDegZero.empty()){
        //取一个入度为0的顶点v
        int v=inDegZero.front();
        inDegZero.pop();
        sortedVertex[++visitedNum]=v;   //记录拓扑序列
        //遍历v的所有邻接点w
        for(int w=1;w<=N;w++)
            if(G[v][w]!=-1){    //注意这里判断有边存在的条件
                inDegree[w]--;
                if(inDegree[w]==0)
                    inDegZero.push(w);
                earliestTime[w]= max( earliestTime[w] , earliestTime[v]+G[v][w] );
                if(earliestTime[w]>ans)  //记录最大值
                    ans=earliestTime[w];
            }
    }
    if(visitedNum!=N)
        ans=-1;
    return ans;
}

void TopSortLatestTime(){
    //开始计算最晚开始时间
    //初始化各顶点的最晚开始时间的初始值
    for(int i=1;i<=N;i++)
        latestTime[i]=earliestTime[sortedVertex[N]];
    //按拓扑序的逆序，开始遍历各个顶点v
    for(int i=N-1;i>=1;i--){
        int v=sortedVertex[i];
        for(int w=1;w<=N;w++)    //对于顶点v的每一个邻接点w
            if(G[v][w]!=-1){
                latestTime[v]=min( latestTime[v] , latestTime[w]-G[v][w] );
            }
    }
    //遍历所有边，如果是关键活动则输出
    for(int v=1;v<=N;v++)
        for(int w=1;w<=N;w++)
            if(G[v][w]!=-1 && G[v][w]!=0 && latestTime[w]-earliestTime[v]-G[v][w]==0)
                cout<<v<<"->"<<w<<endl;
}

int main(){
    freopen("/Users/xcm/xcmprogram/netlesson/ds-zju/in.txt","r",stdin);
    memset(G,0, sizeof(G));
    memset(earliestTime,0,sizeof(earliestTime));
    memset(inDegree,0, sizeof(inDegree));
    cin>>N>>M;
    int u,v,w;
    //读入图数据并初始化入度
    for(int i=0;i<M;i++){
        cin>>u>>v>>w;
        inDegree[v]++;
        G[u][v]=w;
    }
    int ans=TopoSortEarlistTime();
    if(ans==-1)
        cout<<"0"<<endl;
    else{
        cout<<ans<<endl;
        TopSortLatestTime();
//        cout<<"Earliest time:\n";
//        for(int i=1;i<=N;i++)
//            cout<<earliestTime[i]<<"\t";
//        cout<<endl;
//        cout<<"Latest time:\n";
//        for(int i=1;i<=N;i++)
//            cout<<latestTime[i]<<"\t";
//        cout<<endl;
    }
    return 0;
}