/*
程序设计与算法（二）第十周测验 1:迷宫问题 POJ4127
write by xucaimao,2018-01-18 17:10 AC at 2018-01-19 22:26:26
重点是考察路径的记录与输出
*/

#include<cstdio>
#include<vector>
#include <cstring>
using namespace std;
struct Node{
	int r,c;
	int f;//记录父节点在队列中的下标，-1说明结束
	Node(int rr,int cc,int ff):r(rr),c(cc),f(ff){};
	Node(){};
};
const int maxn=10;
int G[maxn][maxn];
int vis[maxn][maxn];
//定义走动的四个方向，{行的改变量,列的改变量}，按行序排列。
int dir[4][2]={ {-1,0},{1,0},{0,-1},{0,1} };
Node q[30];
int pfront=0,pend=0;//定义队头队尾,二者重合时队为空

void bfs(){
	q[pend++]=Node(1,1,-1);//-1表示没有前驱节点了

	while( pfront!=pend ){
		Node e=q[pfront];//取队首元素
		if(e.r==5 && e.c==5)break;

		for(int i=0;i<4;i++){
			int nextr=e.r+dir[i][0];
			int nextc=e.c+dir[i][1];
			if(G[nextr][nextc]==0 && !vis[nextr][nextc]){
				q[pend++]=Node(nextr,nextc,pfront);
				vis[nextr][nextc]=1;
			}
		}
		pfront++;//出队
	}

	vector<int> ans;//保存各个节点在队列中的下标
	int p=pfront;
	while(p!=-1){
		ans.push_back(p);
		//printf("add: %d\n",p);
		p=q[p].f;//找到父节点
	}
	int len=ans.size();
	for(int i=len-1;i>=0;i--)
		printf("(%d, %d)\n",q[ ans[i] ] .r-1,q[ ans[i] ].c-1 );

}

int main(){
	freopen("in.txt","r",stdin);
	for(int i=0;i<maxn;i++)
		for(int j=0;j<maxn;j++)
			G[i][j]=1;//外侧加一圈城墙，简化程序

	for(int i=1;i<=5;i++)
		for(int j=1;j<=5;j++)
			scanf("%d",&G[i][j]);
	bfs();
	
	return 0;
}
	