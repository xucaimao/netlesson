/*
程序设计与算法（二）算法基础 第六周 动态规划 例题5 POJ2978:Help Jimmy
write by xucaimao,2017-12-26 21:30,AC at 2017-12-26 16:59:13
记忆化递归第二版

*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn=6;
const int BIG=999999999;
struct Board{
	int l,r,height;//左右端点坐标及高度
	bool operator <(const Board &b)const{
		//把板子从大到小排列
		return height>b.height;
	}
};

Board b[maxn];
int N,jx,jy,jmax;
//定义第n块板子左右端点下方的第一块板的序号，如果没有，则值为-1
int BU[maxn][2];//boardUnderLeft,boardUnderRight
//记录从第i块板子左端和右端跳下的最短时间
int MinTime[maxn][2];

void init(){
	//初始化第n块板子左右端点下方的第一块板的序号，如果没有，则值为-1
	//同时初始化最小时间数组为-1
	memset(BUL,-1,sizeof(BUL));
	memset(BUR,-1,sizeof(BUR));
	memset(leftMinTime,-1,sizeof(leftMinTime));
	memset(rightMinTime,-1,sizeof(rightMinTime));
	for(int i=0;i<N;i++)
		for(int j=i+1;j<=N;j++){
			if(BU[i][0]<0 && b[i].l>b[j].l && b[i].l<b[j].r)
				BU[i][0]=j;
			if(BU[i][1]<0 && b[i].r>b[j].l && b[i].r<b[j].r)
				BU[i][1]=j;
		}
}

int jump(int k,int x,int){
	//记忆化的递归
	//从第k块板端点(x,y)往下跳所需的最小时间

	if(MinTime[k][dir]<0){
		if(BU[k][dir]<0){//端点下方没有板,直接落地
			if(b[k].height>jmax)
				MinTime[k][dir]=BIG;
			else
				MinTime[k][dir]=b[k].height;

		}
		else{//下方有板,需要考虑下跳后,左走还是右走这两种情况
			int m=BUL[k][dir];//端点下方板子的编号
			int tv=b[k].height-b[m].height;//k到m的垂直时间
			int tl=b[k].l-b[m].l;//往左走到m的左端
			int jl=jumpLeft(m,0,BU[m][0]);//
			int tr=b[m].r-b[k].l;//往右走到m的右端
			int jr=jumpRight(m);
			leftMinTime[k]=tv+min( jl+tl , jr+tr );
		}
	}	
	return leftMinTime[k];
}

int jumpRight(int k){
	//记忆化的递归
	//从第k块板右边往下跳所需的最小时间
	if(rightMinTime[k]<0){
		if(BUR[k]<0){//右端下方没有板
			if(b[k].height>jmax)
				rightMinTime[k]=BIG;
			else
				rightMinTime[k]=b[k].height;

		}
		else{
			int m=BUR[k];//k右端下方板子的编号
			int tv=b[k].height-b[m].height;//k到m的垂直时间
			int tl=b[k].r-b[m].l;//往左走到m的左端
			int tr=b[m].r-b[k].r;//往右走到m的右端
			int jl=jumpLeft(m);
			int jr=jumpRight(m);
			rightMinTime[k]=tv+min( jl+tl , jr+tr );
		}
	}	
	return rightMinTime[k];
}

int solve(){
	int lt=jumpLeft(0);
	int rt=jumpRight(0);
	return min(lt,rt);
}

int main(){
	freopen("in.txt","r",stdin);
	int t;
	Board bd;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&N);
		scanf("%d%d%d",&jx,&jy,&jmax);
		for(int i=1;i<=N;i++){
			//从下标1开始存储数据
			scanf("%d%d%d",&bd.l,&bd.r,&bd.height);
			b[i]=bd;
		}
		bd.l=jx;
		bd.r=jx;
		bd.height=jy;
		b[0]=bd;
		sort(b+1,b+N+1 );//排序
		init();
		int ans=solve();
		printf("%d\n",ans );
	}
	return 0;
}