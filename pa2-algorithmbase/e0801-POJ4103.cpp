/*
《算法基础与在线实践》练习题8-1 踩方格 POJ4103
write by xucaimao,2018-01-07 23:41,AC at 2018-01-07 23:53:28
*/
#include<cstdio>
#include <cstring>
const int maxn=50;
int G[maxn][maxn];
//可以走动的三个方向，{行的改变量,列的改变量}。
int dir[3][2]={ {-1,0},{0,1}, {0,-1}};
int N,ans=0;

void dfs(int x,int y,int steps){
	if(steps==N)ans++;
	else{
		for(int i=0;i<3;i++){
			int nx=x+dir[i][0];
			int ny=y+dir[i][1];
			if(!G[nx][ny]){
				G[x][y]=1;
				dfs(nx,ny,steps+1);
				G[x][y]=0;
			}	
		}
	}
}

int main(){
	scanf("%d",&N);
	G[25][25]=1;
	dfs(25,25,0);
	printf("%d\n",ans );
	
	return 0;
}