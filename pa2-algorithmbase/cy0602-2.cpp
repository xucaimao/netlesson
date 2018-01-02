/*
程序设计与算法（二）第六周测验 2:Zipper
write by xucaimao,2017-12-22 19:40 AC at 2017-12-26 17:49:35
与公共子序列是一类问题
包含大写、小写字母。首先要判断对应的字母数量是否一致。再判断公共子序列
*/

#include<cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxa=210;
const int maxb=410;
char sa[maxa],sb[maxa],str[maxb];
int alpha[70];//用于判断字符出现的次数
int maxLen[maxb][maxb];

int sameSequ(char s1[],char s2[]){
	//求两个字符串的最大公共子序列的长度
	int len1=strlen(s1+1);
	int len2=strlen(s2+1);
	for(int i=0;i<=len1;i++)
		maxLen[i][0]=0;
	for(int i=0;i<=len2;i++)
		maxLen[0][i]=0;
	for(int i=1;i<=len1;i++)
		for(int j=1;j<=len2;j++){
			if(s1[i]==s2[j])
				maxLen[i][j]=maxLen[i-1][j-1]+1;
			else
				maxLen[i][j]=max( maxLen[i-1][j],maxLen[i][j-1] );
		}
	return maxLen[len1][len2];
}

int solve(char s1[],char s2[],char ss[]){
	//先判断字符能否完全对应
	int len1=strlen(s1+1);
	int len2=strlen(s2+1);
	int lens=strlen(ss+1);
	for (int i = 1; i <= len1; ++i)
		alpha[s1[i]-'A']++;
	for (int i = 1; i <= len2; ++i)
		alpha[s2[i]-'A']++;
	for (int i = 1; i <= lens; ++i)
		alpha[ss[i]-'A']--;
	for (int i = 0; i < 70; ++i)
		if(alpha[i]) return 0;
	
	//再判断最大公共子序列长度
	if(sameSequ(s1,ss)==len1 && sameSequ(s2,ss)==len2)return 1;
	else return 0;
}

int main(){
	freopen("in.txt","r",stdin);
	int n,ans=0;
	scanf("%d",&n);
	getchar();

	for(int i=1;i<=n;i++){
		memset(alpha,0,sizeof(alpha));
		scanf("%s%s%s",sa+1,sb+1,str+1);
		int ans=solve(sa,sb,str);
		printf("Data set %d: ", i);
		if(ans)printf("yes\n");
		else printf("no\n");
	}
	return 0;
}
	