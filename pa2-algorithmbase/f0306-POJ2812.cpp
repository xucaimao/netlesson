/*
程序设计与算法（二）算法基础 第一周 枚举 例题6 讨厌的青蛙 POJ2812
write by xucaimao,20171119,14:20测试通过

*/
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=5001;
struct Point
{
	int r,c;
};

bool map[maxn][maxn];
Point pos[maxn];
int maxstep=0;
int maxr,maxc;

bool operator < (const Point &a,const Point &b){
	return(a.r<b.r || ( a.r==b.r && a.c<b.c ) );
}

bool outside(int r,int c){
	//r[1..maxr],c[1..maxc],边界开始写成 r<0 c<0,查了半天才发现错误
	if(r<1 || r>maxr || c<1 || c>maxc)return true;
	else return false;
}

bool solve(int a,int b){
	int dr=pos[b].r-pos[a].r;//跳的步幅
	int dc=pos[b].c-pos[a].c;
	//从起点往外跳一步，结果还没有跳出去。说明点a不能作为起点
	if( !outside(pos[a].r-dr,pos[a].c-dc) ) return false;
	//从起点开始跳maxstep步就出界了，说明本次的路径长度比maxstep短，不用计算了
	if( pos[a].r+maxstep*dr<1 || pos[a].r+maxstep*dr>maxr ) return false;
	if( pos[a].c+maxstep*dc<1 || pos[a].c+maxstep*dc>maxc ) return false;
	int s=2;//此时路径已经有了a,b两点
	int pr=pos[b].r+dr,pc=pos[b].c+dc;//指向第三点
	while(!outside(pr,pc) && map[pr][pc]){
		pr+=dr;
		pc+=dc;
		s++; 
	}
	if(outside(pr,pc) && s>maxstep)
		maxstep=s;
	return true;
}

int main(){
	freopen("f0306.in","r",stdin);
	int N;
	scanf("%d%d",&maxr,&maxc);
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		int r,c;
		scanf("%d%d",&r,&c);
		pos[i].r=r;pos[i].c=c;
		map[r][c]=true;
	}
	sort(pos,pos+N);//排序
	//枚举相邻的两个点
	for(int i=0;i<N-1;i++)
		for(int j=i+1;j<N;j++)
			solve(i,j);
	if(maxstep<3)maxstep=0;
	printf("%d\n",maxstep );
	return 0;
}