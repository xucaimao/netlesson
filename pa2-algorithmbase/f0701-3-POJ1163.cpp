/*
程序设计与算法（二）算法基础 第六周 动态规划 例题1 The Triangle POJ1163
write by xucaimao,2017-12-20 15:50,
扩展打印记录,采用滚动数组的形式,节约了空间,同时不破坏原始数据
*/
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=110;
int data[maxn][maxn];
int temp[maxn];//滚动数组
int path[maxn];


int main(){
	freopen("in.txt","r",stdin);
	int n=0;
	scanf("%d",&n);
	for(int r=1;r<=n;r++)
		for(int c=1;c<=r;c++){
			scanf("%d",&data[r][c]);
		}
	for(int i=0;i<=n;i++)
		temp[i]=data[n][i];//初始化滚动数组为最后一行的数据

	for (int r = n-1; r>=1; r--){
		//从倒数第二行开始
		int rmax=-1;//用于记录每行的最大值
		for(int c=1;c<=r;c++){
			int dc=c;
			if(temp[c]<temp[c+1])
				dc=c+1;
			temp[c]=temp[dc]+data[r][c];
			if(temp[c]>rmax){
				rmax=temp[c];
				path[r+1]=data[r+1][dc];//记录下一行
			}
		}
	}
	path[1]=data[1][1];//记录第一行

	printf("%d = ",temp[1]);
	for(int i=1;i<=n;i++){
		printf("%d",path[i]);
		if(i<n)printf(" + " );
	}
	printf("\n");

	return 0;
}