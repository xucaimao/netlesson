/*
程序设计与算法（二）算法基础 第六周 动态规划 例题6 POJ4131:Charm Bracelet
write by xucaimao,2017-12-30 22:30,AC at 
f[i][j]表示,在前i件物品里面选择若干件,使得体积不超过j时,物品总价值最高的方法
f[i][j]= f[i-1][j]								不选择第i件物品,在前i-1件物品里面选
		 f[i-1][j-obj[i].volume]+obj[i].price	选择第i件物品
		 obj[i].price							i=1且obj[i].volume<=M
		 0										i=1且obj[i].volume>M
二维数组方式表示
实现了记录具体选择的功能
*/
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Obj{
	int volume,price;
};

const int maxn=10;
const int maxm=10;

Obj obj[maxn];
int N,M;//物品数量及背包容积
int f[maxn][maxm];
vector<int> ans[maxn][maxm];

int main(){
	freopen("in.txt","r",stdin);
	scanf("%d%d",&N,&M);
	for(int i=1;i<=N;i++){
		scanf("%d%d",&obj[i].volume,&obj[i].price);
	}
	for(int j=0;j<=M;j++){
		if(obj[1].volume<=j){
			f[1][j]=obj[1].price;
			ans[1][j].push_back(1);
		}
		else
			f[1][j]=0;
	}
	// for(int k=0;k<=M;k++)
	// 	printf("%2d ",f[1][k] );
	// printf("\n");

	for(int i=2;i<=N;i++){
		for(int j=0;j<=M;j++){
			int a=f[i-1][j];
			//下面两句是重点，刚开始怎么都搞不定
			int b=0;
			if(obj[i].volume<=j)
				b=f[i-1][j-obj[i].volume]+obj[i].price;
			f[i][j]=max(a,b);

			if(a>b)ans[i][j]=ans[i-1][j];
			if(a<b){
				ans[i][j]=ans[i-1][j-obj[i].volume];
				ans[i][j].push_back(i);
			}
		}
		// for(int k=0;k<=M;k++)
		// 	printf("%2d ",f[i][k] );
		// printf("\n");
	}
	printf("%d\n",f[N][M] );
	vector<int> t=ans[N][M];
	int len=t.size();
	for(int k=0;k<len;k++)
		printf("%d", t[k]);
	printf("\n");
	return 0;
}