/*
程序设计与算法（二）算法基础 第六周 动态规划 例题2 
《算法基础与在线实践》例题7.3 最长上升子序列 POJ2533
write by xucaimao,2017-12-21 12:50,
扩展打印求得的序列,如有多个相同长度的,一起打印
采用vector,便于序列的复制、增加元素第操作
*/
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn=1000+10;
int data[maxn],maxLen[maxn];
vector<int> ans[maxn];//ans[k]存放的是以data[k]为终点的最长子序列

int main(){
	freopen("in.txt","r",stdin);
	int n=0,res=-1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&data[i]);
		maxLen[i]=1;
		ans[i].push_back(data[i]);//初始化以data[i]为终点的最长子序列
	}
	
	for(int k=2;k<=n;k++){
		//求以data[k]为终点的最长子序列的长度
		vector<int> ansleft;//存放data[k]之前的,以data[i]为终点的上升子序列,
		int maxleft=0;//存放该上升子序列的最大长度
		
		for(int i=1;i<k;i++)
			if(data[k]>data[i]){
				//以data[i]为终点的上升子序列,在data[k]的前方
				//加上data[k]就构成了一个更长的上升子序列
				//所以,以data[k]为终点的上升子序列,其长度的最小值就是maxLen[i]+1
				//但要考虑到maxLen[k]可能通过其他渠道被赋值了，此时就应该保留二者的大值
				if(maxLen[i]>maxleft){
					maxleft=maxLen[i];
					ansleft=ans[i];
				}
			}
		maxLen[k]=maxleft+1;
		ans[k]=ansleft;
		ans[k].push_back(data[k]);//把自己加入vector

		if(maxLen[k]>res)res=maxLen[k];//记录最大值
	}

	printf("The max length is : %d\n",res);
	printf("The sequence is :\n");
	for(int i=1;i<=n;i++)
		if(maxLen[i]==res){
			vector<int> resvec=ans[i];
			for(int j=0;j<res;j++)
				printf(" %d",resvec[j] );
			printf("\n");
		}	
	
	return 0;
}