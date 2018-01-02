/*
程序设计与算法（二）算法基础 第六周 动态规划 例题1 The Triangle POJ1163
write by xucaimao,2017-12-20 15:50,
扩展打印记录,采用备份数组的形式,浪费空间但编程简单
*/
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=110;
int data[maxn][maxn];
int back[maxn][maxn];
int path[maxn];


int main(){
	freopen("in.txt","r",stdin);
	int n=0;
	scanf("%d",&n);
	for(int r=1;r<=n;r++)
		for(int c=1;c<=r;c++){
			scanf("%d",&data[r][c]);
			back[r][c]=data[r][c];
		}

	for (int r = n-1; r>=1; r--){
		//从倒数第二行开始
		int rmax=-1;//用于记录每行的最大值
		for(int c=1;c<=r;c++){
			int dc=0;
			if(data[r+1][c]<data[r+1][c+1])
				dc=1;
			data[r][c]+=data[r+1][c+dc];
			if(data[r][c]>rmax){
				rmax=data[r][c];
				path[r+1]=back[r+1][c+dc];//记录下一行
			}
		}
	}
	path[1]=back[1][1];//记录第一行

	printf("%d= ",data[1][1]);
	for(int i=1;i<=n;i++){
		printf("%d",path[i]);
		if(i<n)printf(" + " );
	}
	printf("\n");

	return 0;
}