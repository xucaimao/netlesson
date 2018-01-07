/*
程序设计与算法（二）第八周测验 1:红与黑 POJ2816
write by xucaimao,2018-01-01 23:15 AC at 2018-01-02 23:46:12
需要处理好数据输入时的换行
*/

#include<cstdio>
#include <cstring>
const int maxn=25;
char G[maxn][maxn];
int vis[maxn][maxn];
int dir[4][2]={ {1,0},{0,1},{-1,0},{0,-1} };//定义上右下左四个方向
int ans=0;

void dfs(int r,int c){
	ans++;
	vis[r][c]=1;
	for(int i=0;i<4;i++){
		int nextr=r+dir[i][0];
		int nextc=c+dir[i][1];
		if(!vis[nextr][nextc] && G[nextr][nextc]=='.')
			dfs(nextr,nextc);
	}
}

int main(){
	freopen("in.txt","r",stdin);
	int w,h,sr,sc;
	while(1){
		memset(G,0,sizeof(G));
		memset(vis,0,sizeof(vis));
		ans=0;
		scanf("%d%d",&w,&h);
		getchar();//忽略换行
		if(w==0)break;
		for(int r=1;r<=h;r++){
			for(int c=1;c<=w;c++){
				char ch;
				scanf("%c",&ch);
				if(ch=='@'){
					ch='.';
					sr=r;
					sc=c;//记录出发点
				}
				G[r][c]=ch;
			}
			getchar();//忽略换行
		}	
		dfs(sr,sc);
		printf("%d\n",ans );
	}
	return 0;
}
	