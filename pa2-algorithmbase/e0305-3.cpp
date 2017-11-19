/*
《算法基础与在线实践》练习题3-5 垃圾炸弹 POJ4133
write by xucaimao,20171117 18:40
重新整理思路
本程序TLE 内存:3080kB   时间:11ms
*/
#include<cstdio>

struct Rubbish
{
	int x,y,i;
};
const int maxn=1025;
int res[maxn][maxn]={0};//记录在该点引爆炸弹可以清理的垃圾数量，用于最终统计数量
Rubbish rub[21];//记录实际的垃圾点坐标

int main(){
	freopen("e0305.txt","r",stdin);
	int d,n;
	scanf("%d%d",&d,&n);
	
	for(int k=0;k<n;k++){
		int x,y,i;
		scanf("%d%d%d",&x,&y,&i);
		rub[k].x=x;
		rub[k].y=y;
		rub[k].i=i;
	}

	int maxsum=0;//垃圾总量
	for(int k=0;k<n;k++){//在n个垃圾点的周围d范围内枚举
		int sx=rub[k].x-d,ex=rub[k].x+d;
		int sy=rub[k].y-d,ey=rub[k].y+d;
		for(int x=sx;x<=ex;x++)//在本范围内的所有点引爆，都可有获得此垃圾点的垃圾
			if(x>=0 && x<maxn){//保证不越界
				for(int y=sy;y<=ey;y++)
					if(y>=0 && y<maxn){//保证不越界
						//此点引爆可以获得的垃圾数量，增加本垃圾点的垃圾重量
						//此点引爆可以获得多个垃圾点的垃圾
						res[x][y]+=rub[k].i;//注意是增加，不是直接赋值
						if(res[x][y]>maxsum)maxsum=res[x][y];
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