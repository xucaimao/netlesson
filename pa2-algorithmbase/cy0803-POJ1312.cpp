/*
程序设计与算法（二）第八周测验 3:棋盘问题 POJ1312
write by xucaimao,2018-01-05 14:00 AC at 2018-01-05 16:12:15
在一个给定形状的棋盘（形状可能是不规则的）上面摆放棋子，棋子没有区别。要求摆放时任意的两个棋子
不能放在棋盘中的同一行或者同一列，请编程求解对于给定形状和大小的棋盘，摆放k个棋子的所有可行的
摆放方案C。
这道题目类似N皇后问题，与之不同的是每一行不一定有棋盘，所以dfs里要注意不一定是当前行。
思路很简单，只需从第一行第一个开始搜索，如果该位置该列没被标记且为棋盘，那么在这里放上棋子，并标
记。因为每行每列不能冲突，所以搜索下一行，比并且棋子数加1。每次搜索之前先要判断是否棋子已经用完，
如果用完，记录方案数加1，然后直接返回。直到所有搜索全部完成，此时已得到全部方案数。
此题还需注意标记数组仅仅标记某一列上是否有棋子，因为每次递归下一行，所以每一行不会有冲突，只需判
断这一列上是否有其他棋子。还要注意修改标记后递归回来要及时复原。

*/

#include<cstdio>
#include <cstring>
const int maxn=10;
char G[maxn][maxn];
int vis[maxn];//用于判断第i列是否右棋子
int N,K;
int ans=0;

void dfs(int row,int num){
	//求第num个棋子在第row行的摆放位置
	if(num==K)ans++;
	else{
		//每一行不一定有棋盘，所以要从当前行开始向后遍历
		for(int r=row;r<=N;r++)
			for(int c=1;c<=N;c++)
				if(G[r][c]=='#' && !vis[c] ){
					vis[c]=1;
					dfs(r+1,num+1);
					vis[c]=0;
				}
	}
}

int main(){
	freopen("cy0803.in","r",stdin);
	while(1){
		memset(vis,0,sizeof(vis));
		memset(G,0,sizeof(G));
		scanf("%d%d",&N,&K);
		if(N==-1)break;
		getchar();//忽略行尾
		for(int r=1;r<=N;r++){
			for(int c=1;c<=N;c++)
				scanf("%c",&G[r][c]);
			getchar();//忽略行尾
		}
		ans=0;
		dfs(1,0);//从第一行开始放
		printf("%d\n",ans );
	}
	return 0;
}
	