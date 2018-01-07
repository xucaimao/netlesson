/*
程序设计与算法（二）算法基础 第六周 动态规划 
例题7 滑雪 POJ1088
write by xucaimao,2018-01-06 10:30,AC at 2018-01-06 16:00:51

*/
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Point{
	int r,c,h;
	bool operator <(const Point &b)const{
		return h<b.h;
	}
};

const int maxn=10000+100;

Point p[maxn];
int areaH[110][110];
int length[110][110];
int dir[4][2]={ {-1,0},{1,0},{0,-1},{0,1} };
vector<int> ans[maxn];//记录具体路径

int main(){
	freopen("in.txt","r",stdin);
	int R,C;
	scanf("%d%d",&R,&C);
	for(int r=1;r<=R;r++)
		for(int c=1;c<=C;c++){
			scanf("%d",&areaH[r][c]);
			length[r][c]=1;
			//注意这里的二维索引与一维索引的转换，是乘以C。开始错搞错R，坑了我半天时间
			p[(r-1)*C+(c-1)].r=r;
			p[(r-1)*C+(c-1)].c=c;
			p[(r-1)*C+(c-1)].h=areaH[r][c];
		}
	sort(p,p+R*C);//把所有点按从低到高的顺序排序
	for(int i=0;i<R*C;i++){//按从低到高顺序遍历各个点
		int r=p[i].r;
		int c=p[i].c;
		for(int d=0;d<4;d++){//与每个点周围的四个点进行比较
			int nr=r+dir[d][0];
			int nc=c+dir[d][1];
			if(nr>=1 && nr<=R && nc>=1 && nc<=C && areaH[nr][nc]<p[i].h)//找到比当前点低的相邻的点
				length[r][c]=max(length[r][c],length[nr][nc]+1);
		}
	}
	int ans=0;
	for(int r=1;r<=R;r++)
		for(int c=1;c<=C;c++)
			if(length[r][c]>ans)ans=length[r][c];
	printf("%d\n",ans );
	return 0;
}