/*
程序设计与算法（二）第八周测验 2:A Knight's Journey POJ2488
write by xucaimao,2018-01-05 10:50 AC at 2018-01-05 13:03:56
	问题本质是图的遍历。重点是，题目要求输出第一个词典序的路径。此时可以考虑把出发点就放在A1
	同时在遍历时按词典序进行搜索相邻位置，即按列号大小顺序搜索，再按行号大小顺序搜索。同时，
	为简化编程，可以考虑在棋盘的外圈加一圈围墙(空位置设置成已访问)
	注意输入顺序，后面的q是行
*/

#include<cstdio>
#include <cstring>
const int maxn=10;
char G[maxn][maxn];
int vis[maxn][maxn];
//定义马可以走动的八个方向，{行的改变量,列的改变量}，按行序排列。
int dir[8][2]={ {-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1} };
int ans[100][2];//用于记录所在的具体位置
int netnum=0;//棋盘总的格子数量
int R,C;
bool haveans=0;

void dfs(int r,int c,int steps){
	if(haveans)return;
	//printf(">%c%d",r-1+'A',c);
	ans[steps][0]=r;//记录路径
	ans[steps][1]=c;
	vis[r][c]=1;
	if(steps==netnum){//找到第一个解
		haveans=1;
	}
	else{
		for(int i=0;i<8;i++){
			int nextr=r+dir[i][0];
			int nextc=c+dir[i][1];
			if(vis[nextr][nextc]==0 && nextr>=1 && nextr<=R && nextc>=1 && nextc<=C)
				dfs(nextr,nextc,steps+1);
		}
	}
	vis[r][c]=0;
}

int main(){
	freopen("cy0802.in","r",stdin);
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		scanf("%d%d",&C,&R);//注意输入顺序，此处是坑
		memset(vis,0,sizeof(vis));
		netnum=R*C;
		haveans=0;
		dfs(1,1,1);//从A1开始遍历
		printf("Scenario #%d:\n", t);
		if(haveans){
			for(int i=1;i<=netnum;i++)
				printf("%c%d",ans[i][0]-1+'A',ans[i][1]);
			printf("\n");
		}
		else
			printf("impossible\n");
		if(t<T)printf("\n");
	}
	return 0;
}
	