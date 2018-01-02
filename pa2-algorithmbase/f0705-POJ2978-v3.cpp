/*
程序设计与算法（二）算法基础 第六周 动态规划 例题5 POJ2978:Help Jimmy
write by xucaimao,2017-12-26 21:30,AC at 2017-12-26 16:59:13
递推方法

*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=1000+10;
const int BIG=999999;
struct Board{
	int l,r,height;//左右端点坐标及高度
	bool operator <(const Board &b)const{
		//把板子从大到小排列
		return height>b.height;
	}
};

Board b[maxn];
int N,jx,jy,jmax;
//记录从第i块板子左端和右端跳下的最短时间
int leftMinTime[maxn],rightMinTime[maxn];

int haveBottom(int k,int dir){
	//dir=0左端点,dir=1右端点
	//第k块板的左右端点下方有没有别的板子，有则返回板子的编号，没有则返回-1
	int x,ans=-1;
	if(dir==0)
		x=b[k].l;
	else x=b[k].r;
	int m=k+1;
	while(m<=N){
		if(x>=b[m].l && x<=b[m].r){
			ans=m;
			break;
		}
		m++;
	}
	return ans;
}

void jumpLeft(int k){
	//从第k块板左边往下跳所需的最小时间
	int m=haveBottom(k,0);
	if(m==-1){//左端下方没有板
		if(b[k].height>jmax)
			leftMinTime[k]=BIG;
		else
			leftMinTime[k]=b[k].height;

	}
	else{
		int tv=b[k].height-b[m].height;//k到m的垂直时间
		int tl=b[k].l-b[m].l;//往左走到m的左端
		int tr=b[m].r-b[k].l;//往右走到m的右端
		leftMinTime[k]=tv+min( leftMinTime[m]+tl , rightMinTime[m]+tr );
	}
		
}

void jumpRight(int k){
	//从第k块板右边往下跳所需的最小时间
	int m=haveBottom(k,1);
	if(m==-1){//右端下方没有板
		if(b[k].height>jmax)
			rightMinTime[k]=BIG;
		else
			rightMinTime[k]=b[k].height;
	}
	else{
		int tv=b[k].height-b[m].height;//k到m的垂直时间
		int tl=b[k].r-b[m].l;//往左走到m的左端
		int tr=b[m].r-b[k].r;//往右走到m的右端
		rightMinTime[k]=tv+min( leftMinTime[m]+tl , rightMinTime[m]+tr );
	}		
}

int solve(){
	for(int i=N;i>=0;i--){
		jumpLeft(i);
		jumpRight(i);
	}
	//printf("%d : %d \n",leftMinTime[0],rightMinTime[0] );
	return min( leftMinTime[0] , rightMinTime[0]);
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
		sort(b+1,b+1+N );//排序
		int ans=solve();
		printf("%d\n",ans );
	}
	return 0;
}