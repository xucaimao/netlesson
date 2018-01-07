/*
《算法基础与在线实践》练习题8-3 马走日 POJ4123
write by xucaimao,2018-01-07 23:15,AC at 2018-01-07 23:37:23
*/
#include<cstdio>
#include <cstring>
const int maxn=10;
int G[maxn][maxn];
//定义马可以走动的八个方向，{行的改变量,列的改变量}，按行序排列。
int dir[8][2]={ {-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1} };
int ans,N,M,steps;

void dfs(int x,int y){
	if(G[x][y])return;
	if(x<0 || x>=N || y<0 || y>=M)return;
	G[x][y]=1;
	steps++;
	if(steps==N*M)ans++;
	else{
		for(int i=0;i<8;i++){
			int nx=x+dir[i][0];
			int ny=y+dir[i][1];
			dfs(nx,ny);
		}
	}
	G[x][y]=0;
	steps--;
}


int main(){
	freopen("in.txt","r",stdin);
	int T,x,y;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d",&N,&M,&x,&y);
		memset(G,0,sizeof(G));
		ans=0;steps=0;
		dfs(x,y);
		printf("%d\n",ans );
	}
	return 0;
}