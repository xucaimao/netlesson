/*
《算法基础与在线实践》练习题3-5 垃圾炸弹 POJ4133
write by xucaimao,20171116 23:00
如果数据很分散，本程序所用的缩小范围的方法，作用就很有限
本程序TLE 内存:5524kB 时间:1158ms
*/
#include<cstdio>
const int maxn=1025;
int net[maxn][maxn]={0};//记录垃圾数据
int res[maxn][maxn]={0};//记录在该点引爆炸弹可以清理的垃圾数量，用于最终统计数量
int rubbish[21][2]={0};//记录实际的垃圾点坐标

int solve(int x,int y,int d){
	//计算在点 (x,y) 引爆范围为d的炸弹，所能清理的垃圾的数量
	int s=0;
	int sx=x-d,ex=x+d;
	int sy=y-d,ey=y+d;
	for(int xx=sx;xx<=ex;xx++)
		for(int yy=sy;yy<=ey;yy++){
			if(xx<0 || xx>1024 ||yy<0 || yy>1024)
				continue;//忽略越界的点
			else s+=net[xx][yy];
		}
	return s;
}

int main(){
	freopen("e0305.txt","r",stdin);
	int d,n;
	scanf("%d%d",&d,&n);
	
	for(int k=0;k<n;k++){
		int x,y,i;
		scanf("%d%d%d",&x,&y,&i);
		net[x][y]=i;//记录垃圾数据网格
		rubbish[k][0]=x;
		rubbish[k][1]=y;
	}

	int maxsum=0;//垃圾总量
	for(int k=0;k<n;k++){//在n个垃圾点的周围d范围内枚举
		int sx=rubbish[k][0]-d,ex=rubbish[k][0]+d;
		int sy=rubbish[k][1]-d,ey=rubbish[k][1]+d;
		for(int x=sx;x<=ex;x++)
			for(int y=sy;y<=ey;y++){
				if(x<0 || x>1024 ||y<0 || y>1024 || res[x][y]>0)
					continue;
				else{
					int t=solve(x,y,d);
					res[x][y]=t;//记录
					if(t>maxsum)maxsum=t;
				}
			}
	}

	int num=0;
	for(int x=0;x<maxn;x++)//在有效范围内枚举，
		for(int y=0;y<maxn;y++)
			if(res[x][y]==maxsum)num++;

	printf("%d %d\n",num,maxsum );
	return 0;
}