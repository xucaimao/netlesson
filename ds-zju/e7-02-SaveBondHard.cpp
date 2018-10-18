/*中国大学MOOC-陈越、何钦铭-数据结构-2017秋
 * 07-图5 Saving James Bond - Hard Version （30 分）
 * wirte by xucaimao,2018-10-18
 * 在距离判断的时候，采用直接判断平方的方式，提供运算速度与精度
 * 注意题目中的这一句
 * If there are many shortest paths, just output the one with the minimum first jump, which is guaranteed to be unique.
 * */

#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
const int diameterOfIsland=15;
const int halfWidthOfLake=50;
const int maxN=110;
int NumOfCrocdile,DistOfJump;
struct Pos{
    int x,y;
};

Pos G[maxN];
int first[maxN];    //用于储存第一跳的鳄鱼在G[]中的下标
int fN;             //能满足第一跳的鳄鱼的数量
int preVertex[maxN],minPreVertex[maxN];   //某一点的前驱点
int dist[maxN],minDist[maxN];

//判断能否从小岛上首先调到的鳄鱼的位置
bool firstJump(Pos p){
    double r=diameterOfIsland/2.0;
    return p.x*p.x + p.y*p.y <= (DistOfJump+r)*(DistOfJump+r);
}
bool comp(int p1,int p2){
    int x1=G[p1].x;
    int y1=G[p1].y;
    int x2=G[p2].x;
    int y2=G[p2].y;
    return (x1*x1+y1*y1)<(x2*x2+y2*y2);
}

//判断能否直接跳到岸边
bool jumpToBank(Pos p){
    int x,y;
    if(p.x<0) x=p.x*(-1);
    else x=p.x;
    if(p.y<0) y=p.y*(-1);
    else y=p.y;
    return ( halfWidthOfLake-x <= DistOfJump || halfWidthOfLake-y <= DistOfJump); //判断垂直距离
}
//判断能否从一个鳄鱼跳到另外一个鳄鱼
bool jumpToCrocdile(Pos p1,Pos p2){
    int dx=(p2.x-p1.x);
    int dy=p2.y-p1.y;
    return (dx*dx+dy*dy) <= DistOfJump*DistOfJump;
}

//从出岛后的第一个点u开始遍历
int bfs(int u){
    memset(dist,-1, sizeof(dist));
    memset(preVertex,-1, sizeof(preVertex));
    queue<int> q;
    int lastPoint=-1;
    dist[0]=0;
    dist[u]=1;  //从岛跳到这个点，已经用了一步
    preVertex[u]=0;
    q.push(u);
    while(!q.empty()){
        int v=q.front();
        q.pop();
        if( jumpToBank(G[v]) ){ //能从这一点跳到岸上，则返回该点的序号
            lastPoint=v;
            break;
        }
        //对应v的每一个邻接点
        for(int w=1; w<=NumOfCrocdile;w++){
            if(dist[w]==-1 && w!=v){
                if( jumpToCrocdile(G[v],G[w]) ){  //能从一个鳄鱼v跳到另外一个鳄鱼w
                    q.push(w);
                    dist[w]=dist[v]+1;
                    preVertex[w]=v;
                }
            }
        }
    }
    return lastPoint;
}


int main(){
    freopen("F:\\xcmprogram\\netlesson\\ds-zju\\in.txt","r",stdin);
    scanf("%d %d",&NumOfCrocdile,&DistOfJump);
    fN=0;
    //读入鳄鱼位置数据，并找出能完成第一跳的鳄鱼位置，并记录其位置(在G中的下标)
    //编号0代表小岛
    double r=diameterOfIsland/2.0;
    for(int i=1;i<=NumOfCrocdile;){
        scanf("%d %d",&G[i].x,&G[i].y);
        if(firstJump(G[i]))
            first[fN++]=i;
        i++;
    }
    //对可以完成的第一跳进行排序，开始时题目没看清楚
    sort(first,first+fN,comp);

    int lastPoint=-1;
    int minStep=maxN;
    if(DistOfJump>=42.5){   //直接从岛跳到岸上
        lastPoint=0;
        dist[0]=0;
        minStep=1;
    }
    else{       //从第一跳的鳄鱼开始遍历
        int Case=0;
        for(int i=0;i<fN;i++){
            int curLastPoint=bfs(first[i]);
//            if(curLastPoint>=0){
//                printf("Case %d ,the step is %d ; Last Point is: %d[%d,%d] \n",
//                        ++Case,dist[curLastPoint]+1,curLastPoint,G[curLastPoint].x,G[curLastPoint].y);
//            }
            //找到一条路径，同时该路径必以前的短，记录该路径及先关数据
            //也就是说，如果找到两条长度一样的路径，也是输出第一条找到的
            //这里找到的是最后一个点，通过该点可以跳到岸上，所以记录的步数应该加1
            if(curLastPoint>=0 && dist[curLastPoint]+1<minStep){
                minStep=dist[curLastPoint]+1;
                lastPoint=curLastPoint;
                memcpy(minDist,dist,sizeof(dist));
                memcpy(minPreVertex,preVertex,sizeof(preVertex));
            }
        }
    }

    if(lastPoint>=0){
        //打印路径
        printf("%d\n",minStep);
        stack<int> s;
        //刚开始这里开始写成 i=preVertex[lastPoint]造成死循环
        for(int i=lastPoint;i>0;i=minPreVertex[i])
            s.push(i);
        while(!s.empty()){
            int p=s.top();
            s.pop();
            printf("%d %d\n",G[p].x,G[p].y);
        }
    }
    else
        printf("0\n");
    return 0;
}