/*
程序设计与算法（二）第六周测验 2:Zipper
write by xucaimao,2017-12-22 19:40 AC at 
与公共子序列是一类问题
包含大写、小写字母。首先要判断对应的字母数量是否一致。在判断公共子序列
*/

#include<cstdio>
#include <cstring>
const int maxa=210;
const int maxb=410;
char sa[maxa],sb[maxa],str[maxb];
int 


int solve(char s1[],char s2[],char ss[]){
	int len1=strlen(s1);
	int len2=strlen(s2);
	int lens=strlen(ss);
	int ok=1,allend=0;
	int p1=0,p2=0,ps=0;
	while(!allend){
		
		if(p1<len1 && ss[ps]==s1[p1]){ps++;p1++;}
		else if(p2<len2 && ss[ps]==s2[p2]){ps++;p2++;}
		else {ok=0;break;}
		if(p1==len1 && p2==len2 && ps==lens)allend=1;
	}
	if(ok && allend)return 1;
	else return 0;
}

int main(){
	freopen("in.txt","r",stdin);
	int n,ans=0;
	scanf("%d",&n);
	getchar();

	while(n--){
		scanf("%s%s%s",sa,sb,str);
		int ans=solve(sa,sb,str);
		if(ans)printf("yes\n");
		else printf("no\n");
	}
	return 0;
}
	