/*
程序设计与算法（二）算法基础 第六周 动态规划 例题6 POJ4131:Charm Bracelet
write by xucaimao,2017-12-30 22:30,AC at 
f[i][j]表示,在前i件物品里面选择若干件,使得体积不超过j时,物品总价值最高的方法
f[i][j]= f[i-1][j]								不选择第i件物品,在前i-1件物品里面选
		 f[i-1][j-obj[i].volume]+obj[i].price	选择第i件物品
		 obj[i].price							i=1且obj[i].volume<=M
		 0										i=1且obj[i].volume>M
滚动数组方式表示
实现了记录具体选择的功能
本程序，其实可以只用ans数组记录，最后统计重量
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

const int maxn=3500;
const int maxm=13000;

Obj obj[maxn];
int N,M;//物品数量及背包容积
int f[maxm];
vector<int> ans[maxn];//记录具体答案的滚动数组

int main(){
	freopen("in.txt","r",stdin);
	scanf("%d%d",&N,&M);
	for(int i=1;i<=N;i++){
		scanf("%d%d",&obj[i].volume,&obj[i].price);
	}
	for(int j=0;j<=M;j++){
		if(obj[1].volume<=j){
			f[j]=obj[1].price;
			ans[j].push_back(1);//记录答案
		}
		else
			f[j]=0;
	}
	// for(int k=0;k<=M;k++)
	// 	printf("%2d ",f[k] );
	// printf("\n");

	for(int i=2;i<=N;i++){
		for(int j=M;j>=0;j--){
			int a=f[j];//在前面选，不要记录答案
			int b=0;
			if(obj[i].volume<=j)
				b=f[ j-obj[i].volume ]+obj[i].price;
			f[j]=max(a,b);
			//这里隐含了当a<b时，ans[i][j]=ans[i-1][j]
			if(b>a){//选择第i个物体
				//对于非滚动数组ans[i][j]=ans[i-1][j-obj[i].volume]
				ans[j]=ans[j-obj[i].volume];//继承前面的选择
				ans[j].push_back(i);//增加新的物体
			}
			
		}
	// 	for(int k=0;k<=M;k++)
	// 		printf("%2d ",f[k] );
	// 	printf("\n");
	}
	printf("%d\n",f[M] );
	vector<int> t=ans[M];
	int len=t.size();
	for(int k=0;k<len;k++)
		printf("%d", t[k]);
	printf("\n");
	return 0;
}