/*
程序设计与算法（二）第八周测验 1:鸣人和佐助 POJ4115
write by xucaimao,2018-01-11 20:30 AC at 2018-01-14 11:10:10。用时100ms
dfs回溯方法，重点是如何剪枝
*/

#include<cstdio>
#include <cstring>
const int maxn=210;
int BIG=99999999;
char G[maxn][maxn];
//minTime[r][c][k]表示走到(r,c)时还有k个查克拉时的最短时间大小
int minTime[maxn][maxn][15];
int vis[maxn][maxn][15];//必须要采用三维数组
int dir[4][2]={ {0,-1},{1,0},{-1,0},{0,1} };//定义上右下左四个方向
int minTIME=BIG;
long long int  steps=0;//检测运算次数
int M,N,T;
int sr,sc,tr,tc;//起始点的坐标

void dfs(int r,int c,int curTime,int curCk){
	//到达点(r,c)用时curTime，查克拉有curCk
	//剪枝的时候有没有这个等号，差距巨大。有1593次，没有48839次，直接导致超时
	if(curTime>=minTIME)return;//最优性剪枝1
	if(curTime>=minTime[r][c][curCk])return;//最优性剪枝2,关键步骤
	else minTime[r][c][curCk]=curTime;
	if(r==tr && c==tc){//追上佐助
		if(curTime<minTIME)
			minTIME=curTime;
	}
	else{
		//printf("( %3d , %3d ), curTime = %3d ,curCk = %2d \n",r,c,curTime,curCk );
		steps++;//统计运算次数
		for(int i=0;i<4;i++){
			int nextr=r+dir[i][0];
			int nextc=c+dir[i][1];
			char nch=G[nextr][nextc];

			if(nch=='#' && curCk>0 && !vis[nextr][nextc][curCk-1]){//遇到手下
					vis[nextr][nextc][curCk-1]=-1;
					dfs(nextr,nextc,curTime+1,curCk-1);
					vis[nextr][nextc][curCk-1]=0;
			}
			if( (nch=='*' || nch=='+') && !vis[nextr][nextc][curCk]){//遇到大路或者佐助，直接走
				vis[nextr][nextc][curCk]=-1;
				dfs(nextr,nextc,curTime+1,curCk);
				vis[nextr][nextc][curCk]=0;
			}
		}
	}	
}

int main(){
	//freopen("cy0901.in","r",stdin);
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
			for(int m=0;m<15;m++){
				vis[r][c][m]=0;
				minTime[r][c][m]=BIG;
			}
		}
		getchar();//忽略行尾
	}
	vis[sr][sc][T]=-1;
	dfs(sr,sc,0,T);
	printf("%d\n",minTIME==BIG ? -1 :minTIME );
	//printf("%lld\n",steps );
	return 0;
}
	