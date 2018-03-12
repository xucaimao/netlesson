/*
程序设计与算法（二）第八周测验 1:鸣人和佐助 POJ4115
write by xucaimao,2018-01-11 20:30 AC at 2018-01-14 11:16:19,用时22ms
bfs方法，重点是状态三维数组的运用。走到某一点，所经历的路径有多种，遇到敌人的数量不一样，
花费也不一样。所以不能只用一个表示坐标的二维数组来表示访问状态。
*/

#include<cstdio>
#include <cstring>
#include <queue>
using namespace std;
struct Node{
	int r,c;
	int time,money;
	//下面的构造函数是重点1
	Node(int rr,int cc,int t,int m):r(rr),c(cc),time(t),money(m){}
};
const int maxn=210;
char G[maxn][maxn];
int vis[maxn][maxn][15];//重点2
queue<Node> q;
int dir[4][2]={ {0,-1},{1,0},{-1,0},{0,1} };//定义上右下左四个方向
int M,N,T;
long long int  steps=0;//检测运算次数

int bfs(int sr,int sc,int tr,int tc){
	q.push(Node(sr,sc,0,T));//在出发点，时间为0，金钱为T
	vis[sr][sc][T]=-1;
	while(!q.empty()){
		Node e=q.front();
		steps++;
		//printf("( %d , %d )\n",e.r,e.c );
		if(e.r==tr && e.c==tc){
			return e.time;	
		}

		for(int i=0;i<4;i++){
			int nextr=e.r+dir[i][0];
			int nextc=e.c+dir[i][1];
			char nch=G[nextr][nextc];
			if(nch=='#' && e.money>0 && !vis[nextr][nextc][e.money-1]){//遇到手下
				q.push(Node(nextr,nextc,e.time+1,e.money-1));
				vis[nextr][nextc][e.money-1]=-1;
			}
			if( (nch=='*' || nch=='+') && !vis[nextr][nextc][e.money]){//遇到大路或者佐助，直接走
				vis[nextr][nextc][e.money]=-1;
				q.push(Node(nextr,nextc,e.time+1,e.money));
			}
		}
		q.pop();//元素出队列
	}
	return -1;
}

int main(){
	freopen("cy0901.in","r",stdin);
	int sr,sc,tr,tc;//起始点的坐标
	scanf("%d%d%d",&M,&N,&T);
	getchar();//忽略行尾
	memset(vis,-1,sizeof(vis));
	for(int r=1;r<=M;r++){
		for(int c=1;c<=N;c++){
			scanf("%c",&G[r][c]);
			if(G[r][c]=='@'){
				sr=r;
				sc=c;
			}
			if(G[r][c]=='+'){
				tr=r;
				tc=c;
			}
			for(int t=0;t<15;t++)
				vis[r][c][t]=0;
		}
		getchar();//忽略行尾
	}
	int ans=bfs(sr,sc,tr,tc);
	printf("%d\n",ans );
	//printf("%lld\n",steps );
	return 0;
}
	