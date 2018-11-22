/*中国大学MOOC-陈越、何钦铭-数据结构-2018秋
 * 06-图2 Saving James Bond - Easy Version （25 分）
 * wirte by xucaimao,2018-10-11
 * 在距离判断的时候，采用直接判断平方的方式，提高了运算速度与精度
 * 提交通过后，增加了记录路径（第一条，不是最优）的功能
 * */

#include <cstdio>
#include <cmath>
#include <cstring>
const int diameterOfIsland=15;
const int halfWidthOfLake=50;
const int maxN=110;
int NumOfCrocdile,DistOfJump;
struct Pos{
    int x,y;
};

Pos G[maxN];
int vis[maxN]={0};
int first[maxN];    //用于储存第一跳的鳄鱼在G[]中的下标
int fN;             //能满足第一跳的鳄鱼的数量
int path[maxN],numOfPath=0;     //记录路径

//判断能否从小岛上首先调到的鳄鱼的位置
bool firstJump(Pos p){
    double r=diameterOfIsland/2.0;
    return p.x*p.x + p.y*p.y <= (DistOfJump+r)*(DistOfJump+r);
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

bool dfs(int cur,int level){
    //首先记录路径
    path[level]=cur;
    numOfPath=level+1;

    if(jumpToBank(G[cur])) return true;//首先判断能不能从该点直接跳到岸上
    bool ret=false;
    vis[cur]=1;    //设置访问标志
    int next;
    for(next=0;next<NumOfCrocdile;next++){
        //不是原来的点 && 没有被访问过 && 可以跳过去
        if( next!=cur && !vis[next] && jumpToCrocdile(G[next],G[cur]) ){
            ret=dfs(next,level+1);
            //vis[next]=0;   //取消访问标志
            if(ret)break;
        }
    }

    return ret;
}

int main(){
    freopen("/Users/xcm/xcmprogram/netlesson/ds-zju/in.txt","r",stdin);
    scanf("%d %d",&NumOfCrocdile,&DistOfJump);
    fN=0;
    //读入鳄鱼位置数据，并找出能完成第一跳的鳄鱼位置，并记录其位置(在G中的下标)
    for(int i=0;i<NumOfCrocdile;i++){
        scanf("%d %d",&G[i].x,&G[i].y);
        if(firstJump(G[i]))
            first[fN++]=i;
    }
    //从第一跳的鳄鱼开始遍历
    bool ans=false;
    //直接从岛跳到岸上
    if(DistOfJump>=42.5) ans=true;
    else{
        for(int i=0;i<fN && !ans;i++){
            memset(vis,0,sizeof(vis));
            ans=dfs(first[i],0);
        }
    }

    if(ans){
        printf("Yes\n");
        //打印路径
        for(int i=0;i<numOfPath;i++)
            printf("%d ",path[i]);
        printf("\n");
    }
    else
        printf("No\n");
    return 0;
}