/*
程序设计与算法（二）算法基础 第六周 动态规划 例题1
《算法基础与在线实践》例题8.2 城堡问题
write by xucaimao,2018-01-07 21:00,AC at 2018-01-07 21:37:35
求连通块的问题，关键是题目中用数字的二进制位来表示不同方向能不能走通
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=55;
int G[maxn][maxn]={0};
int vis[maxn][maxn]={0};

int roomnum=0;
int maxRoomSize=0;
int roomSize=0;

void dfs(int r,int c,int rnum){
	if(vis[r][c])return;//开始时这一句丢了
	vis[r][c]=rnum;
	roomSize++;
	if( (G[r][c] & 1) ==0)dfs(r,c-1,rnum);
	if( (G[r][c] & 2) ==0)dfs(r-1,c,rnum);
	if( (G[r][c] & 4) ==0)dfs(r,c+1,rnum);
	if( (G[r][c] & 8) ==0)dfs(r+1,c,rnum);
}

int main(){
	freopen("in.txt","r",stdin);
	int R,C;
	scanf("%d%d",&R,&C);
	for(int r=0;r<R;r++)
		for(int c=0;c<C;c++)
			scanf("%d",&G[r][c]);

	for(int r=0;r<R;r++)
		for(int c=0;c<C;c++){
			if(!vis[r][c]){//该点没有被访问，也就是说不属于任何一个房间
				roomSize=0;
				dfs(r,c,++roomnum);
				maxRoomSize=max( maxRoomSize,roomSize );
			}
		}
	printf("%d\n",roomnum );
	printf("%d\n",maxRoomSize );
	return 0;
}