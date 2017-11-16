/*
《算法基础与在线实践》练习题3-5 垃圾炸弹 POJ4133
write by xucaimao,20171116 23:00
本程序TLE 内存:5524kB 时间:1158ms
*/
#include<cstdio>
const int maxn=1024+10;
int net[maxn][maxn]={0};//记录垃圾数据
int res[maxn][maxn]={0};//记录在该点引爆炸弹可以清理的垃圾数量，用于最终统计数量

int solve(int x,int y,int d){
	//计算在点 (x,y) 引爆范围为d的炸弹，所能清理的垃圾的数量
	int s=0;
	//计算起始点，防止越界
	int sx=(x-d)>0?x-d:0;
	int sy=(y-d)>0?y-d:0;
	int ex=(x+d)>1024?1024:x+d;
	int ey=(y+d)>1024?1024:y+d;
	for(int xx=sx;xx<=ex;xx++)
		for(int yy=sy;yy<=ey;yy++)
			s+=net[xx][yy];
	return s;
}

int main(){
	freopen("e0305.txt","r",stdin);
	int d,n;
	scanf("%d%d",&d,&n);
	int maxx=0,maxy=0;//记录有效的垃圾坐标范围，缩小枚举量，注意初始值的设置
	int minx=2000,miny=2000;
	for(int k=0;k<n;k++){
		int x,y,i;
		scanf("%d%d%d",&x,&y,&i);
		net[x][y]=i;//记录垃圾数据
		if(x<minx)minx=x;
		if(x>maxx)maxx=x;
		if(y<miny)miny=y;
		if(y>maxy)maxy=y;
	}
	int maxsum=0;//垃圾总量
	for(int x=minx;x<=maxx;x++)//在有效范围内枚举，
		for(int y=miny;y<=maxy;y++){
			int t=solve(x,y,d);
			res[x][y]=t;//记录
			if(t>maxsum)maxsum=t;
		}
	int num=0;
	for(int x=minx;x<=maxx;x++)//在有效范围内枚举，
		for(int y=miny;y<=maxy;y++)
			if(res[x][y]==maxsum)num++;

	printf("%d %d\n",num,maxsum );
	return 0;
}