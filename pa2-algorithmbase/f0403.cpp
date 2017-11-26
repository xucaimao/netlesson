/*
程序设计与算法（二）算法基础 第二周 递归 例题1
《算法基础与在线实践》第四章 例题3
 小游戏(类似于连连看) POJ2802
write by xucaimao,20171123 21:30开始编程，20171124 13:00AC
扩展了打印最短路径的功能
*/

#include <cstdio>
#include <cstring>
const int maxn=75+2;
const int maxv=77*77;
const int MaxStep=100000;
int gameBoard[maxn][maxn];
int vis[maxn][maxn];
int mvdir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};//右上左下四个方向
//用于记录路径
int way[maxv][2],minway[maxv][2];
int minstep=MaxStep;
int w,h;//dfs内部需要用到这两个数据用于越界判断

bool isOnBoard(int x,int y){
	return x>=0 && x<=w+1 && y>=0 && y<=h+1;
}

void dfs(int currentx,int currenty,int endx,int endy,int step,int direction){
	//从(currentx,currenty)到(endx,endy)，第step步，方向为dir
	if(step>minstep)return;//此处是一个优化
	if(currenty==endy && currentx==endx){
		//找到一条路径
		if(step<minstep){//路径必上一次小，记录步数及具体路径
			minstep=step;
			memcpy(minway,way,sizeof(way));
		}
	}
	else
		for(int dir=0;dir<4;dir++){//四个方向遍历
			int nextx=currentx+mvdir[dir][0];
			int nexty=currenty+mvdir[dir][1];
			//开始判断是否越界、是否遇到障碍、是否已经走过
			//在棋盘内 且 没有走过 且 （是空白格子 或者 格子非空但此格子就是目的地）
			if( isOnBoard(nextx,nexty) && !vis[nextx][nexty] && ( !gameBoard[nextx][nexty] || 
				(gameBoard[nextx][nexty] && nextx==endx && nexty==endy) ) ){
				way[step+1][0]=nextx;way[step+1][1]=nexty;//记录路径点
				int nstep=step;
				if(dir!=direction)nstep++;//方向更改了，步数增加
				vis[nextx][nexty]=1;
				dfs(nextx,nexty,endx,endy,nstep,dir);
				vis[nextx][nexty]=0;
			}		
		}
}

int main(){
	freopen("f0403.in","r",stdin);
	int startx,starty,endx,endy;
	int boardnum=0;
	while(1){
		memset(gameBoard,0,sizeof(gameBoard));
		scanf("%d%d",&w,&h);
		if(w+h ==0)break;
		printf("Board #%d:\n", ++boardnum);
		getchar();//忽略行尾
		for(int i=1;i<=h;i++){//读入游戏板数据,从1,1开始存
			for(int j=1;j<=w;j++){
				char ch=getchar();
				if(ch=='X')//
					gameBoard[j][i]=1;//此处是坑，注意w是列坐标，h是行坐标
			}
			getchar();//忽略行尾
		}
		int pairnum=0;
		while(1){
			memset(way,0,sizeof(way));
			memset(minway,0,sizeof(minway));
			memset(vis,0,sizeof(vis));
			minstep=MaxStep;
			scanf("%d%d%d%d",&startx,&starty,&endx,&endy);
			if(startx+starty+endx+endy ==0)break;
			way[0][0]=startx;
			way[0][1]=starty;
			dfs(startx,starty,endx,endy,0,-1);//从第一步开始
			printf("Pair %d: ", ++pairnum);
			if(minstep==MaxStep)
				printf("impossible.\n");
			else {
				printf("%d segments.\n", minstep);
				//开始打印路径
				//for(int i=0;i<minstep+1;i++)
					//printf("(%d,%d) ",minway[i][0],minway[i][1] );
				//printf("\n");
			}
		}
		printf("\n");//每组数据之后一个空行,没有导致PE	
	}
	return 0;
}