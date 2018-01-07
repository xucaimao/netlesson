/*
程序设计与算法（二）算法基础 第六周 动态规划 例题8 测验3 分蛋糕
write by xucaimao,2018-01-04 21:30,AC at 2018-01-04 22:59:41
有一块矩形大蛋糕，长和宽分别是整数w 、h。现要将其切成m块小蛋糕，每个小蛋糕都必须是矩形、
且长和宽均为整数。切蛋糕时，每次切一块蛋糕，将其分成两个矩形蛋糕。请计算：最后得到的m块小
蛋糕中，最大的那块蛋糕的面积下限。
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn=25;
const int BIG=99999999;//定义无穷大
int f[maxn][maxn][maxn];

/*[长宽为wxh的蛋糕，切m刀后最大块的面积的最小值]
1.m=0，即一刀都不切，值就是wxh
2.对于wxh的蛋糕，由题，切开后每块的长宽高都是整数，即每块最小是1x1x1。也就是说最多分成
  wxh块，m<=wxh-1。所以当m>wxh-1时，没有合理的切法。由于题目是求面积的最小值，所以此
  时可以把值设为无穷大。


*/
int solve(int w,int h,int m){
	//记忆化的递归
	if(f[w][h][m]==0){
		int wh=w*h;
		if(m==0)f[w][h][m]=wh;//边界条件
		else if(m>wh)f[w][h][m]=BIG;//边界条件
		else{
			int SV=BIG,SH=BIG;//竖切和横切
			//开始求竖切的最优解
			for(int i=1;i<=w-1;i++){//第一刀左边宽度为i
				int SVi=BIG;
				for(int k=0;k<=m-1;k++){
					//左边再被切成k块,右边被切成剩下的m-1-k块
					int SVik=max( solve(i,h,k),solve(w-i,h,m-1-k) );
					if(SVik<SVi)
						SVi=SVik;
				}
				if(SVi<SV)
					SV=SVi;
			}
			//开始求横切的最优解
			for(int i=1;i<=h-1;i++){//第一刀上边宽度为i
				int SHi=BIG;
				for(int k=0;k<=m-1;k++){
					//上边再被切成k块,下边再被切成剩下的m-1-k块
					int SHik=max( solve(w,i,k),solve(w,h-i,m-1-k) );
					if(SHik<SHi)
						SHi=SHik;
				}
				if(SHi<SH)
					SH=SHi;
			}
			f[w][h][m]=min(SV,SH);	
		}
	}
	return f[w][h][m];
}

int main(){
	freopen("in.txt","r",stdin);
	int W,H,M;//蛋糕的长宽及最后分成的块数
	while(1){
		scanf("%d%d%d",&W,&H,&M);
		if(W==0)break;
		int ans=solve(W,H,M-1);
		printf("%d\n",ans );
	}
	return 0;
}