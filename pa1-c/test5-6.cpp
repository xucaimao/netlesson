/*
程序设计实习MOOC / 程序设计与算法（一）第五周测验(2017冬季)  
6:图像模糊处理
四舍五入的处理
write by xucaimao,2017-12-05-20:40,AC 2017-12-05 20:50:23
*/

#include<cstdio>
#include <cstring>
const int maxn=100+10;
int d[maxn][maxn];
int ans[maxn][maxn];

int main(){
	freopen("in.txt","r",stdin);
	int n,m;
	scanf("%d%d",&n,&m);
	//读入矩阵
	for(int r=0;r<n;r++)
		for(int c=0;c<m;c++)
			scanf("%d",&d[r][c]);
	memcpy(ans,d,sizeof(d));
		
	for(int r=1;r<n-1;r++)
		for(int c=1;c<m-1;c++){
			int s=d[r][c]+d[r-1][c]+d[r+1][c]
				+d[r][c-1]+d[r][c+1];
			//求平均值并做四舍五入处理
			ans[r][c]=int((float)s/5.0+0.5);
			}
	for(int r=0;r<n;r++)
		for(int c=0;c<m;c++){
			if(c>0)printf(" ");
			printf("%d",ans[r][c]);
			if(c==m-1)printf("\n");
		}
	return 0;
}

