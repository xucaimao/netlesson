/*
程序设计实习MOOC / 程序设计与算法（一）第五周测验(2017冬季)  
7:矩阵转置
四舍五入的处理
write by xucaimao,2017-12-05-20:55,AC 2017-12-05 20:56:36
*/

#include<cstdio>
#include <cstring>
const int maxn=100+10;
int d[maxn][maxn];

int main(){
	freopen("in.txt","r",stdin);
	int n,m;
	scanf("%d%d",&n,&m);
	//读入矩阵
	for(int r=0;r<n;r++)
		for(int c=0;c<m;c++)
			scanf("%d",&d[r][c]);
		
	for(int c=0;c<m;c++)
		for(int r=0;r<n;r++){
			if(r>0)printf(" ");
			printf("%d",d[r][c]);
			if(r==n-1)printf("\n");
		}
	return 0;
}

