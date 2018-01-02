/*
程序设计与算法（二）算法基础 第六周 动态规划 例题2 
《算法基础与在线实践》例题7.3 最长上升子序列 POJ2533
write by xucaimao,2017-12-20 12:50,

*/
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=1000+10;
int data[maxn],lenMax[maxn];

int main(){
	freopen("in.txt","r",stdin);
	int n=0,ans=-1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&data[i]);
		lenMax[i]=1;
	}
	
	for(int k=2;k<=n;k++){
		//求以data[k]为终点的最长子序列的长度
		for(int i=1;i<k;i++){
			if(data[k]>data[i]){
				//以data[i]为终点的上升子序列,在data[k]的前方
				//加上data[k]就构成了一个更长的上升子序列
				//所以,以data[k]为终点的上升子序列,其长度的最小值就是lenMax[i]+1
				//但要考虑到lenMax[k]可能通过其他渠道被赋值了，此时就应该保留二者的大值
				lenMax[k]=max( lenMax[k],lenMax[i]+1 );
				if(lenMax[k]>ans)ans=lenMax[k];
			}
		}
	}

	printf("%d\n",ans);
	return 0;
}