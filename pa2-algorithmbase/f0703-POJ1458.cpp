/*
程序设计与算法（二）算法基础 第六周 动态规划 例题3
《算法基础与在线实践》例题7.4 最长公共子序列 POJ1458
write by xucaimao,2017-12-23 21:30,
重点是字符串在数组中编号1开始
增加了打印序列的功能,memset()用法熟悉
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn=200+10;
char str1[maxn],str2[maxn];
int maxLen[maxn][maxn];
int vis1[maxn],vis2[maxn];
vector<char> ans;//ans存放公共子序列

int main(){
	freopen("in.txt","r",stdin);
	while(scanf("%s%s",str1+1,str2+1)>0){
		ans.clear();
		memset(maxLen,0,sizeof(maxLen));
		memset(vis1,0,sizeof(vis1));
		memset(vis2,0,sizeof(vis2));

		int len1=strlen(str1+1);
		int len2=strlen(str2+1);
		for(int i=1;i<=len1;i++){
			for(int j=1;j<=len2;j++){
				if(str1[i]==str2[j]){
					//printf("%c: i= %d j= %d \n",str1[i],i,j );
					if(!vis1[i] && !vis2[j]){
						ans.push_back(str1[i]);
						vis1[i]=1;
						vis2[j]=1;
					}
					maxLen[i][j]=maxLen[i-1][j-1]+1;	
				}
				else
					maxLen[i][j]=max( maxLen[i-1][j],maxLen[i][j-1] );
			}
		}
		printf("%d\n",maxLen[len1][len2] );
		// int anslen=ans.size();
		// for(int i=0;i<anslen;i++)
		// 	printf("%c",ans[i] );
		// printf("\n");
	}
	return 0;
}