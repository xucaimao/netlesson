/*
程序设计实习MOOC / 程序设计与算法（一）第七周测验(2017冬季)  
2:找第一个只出现一次的字符
write by xucaimao,2017-12-18 16:30,AC 
*/

#include<cstdio>

const int maxn=100000+10;
char str[maxn];
int charnum[26]={0};

int main(){
	char ch;
	int n=0;
	while(1){
		//读入的时候同时统计每个字母出现的次数
		ch=getchar();
		if(ch=='\n')break;
		str[n++]=ch;
		charnum[ch-'a']++;
	}
	//str[n]='\0';
	bool haveans=0;
	for(int i=0;i<n;i++)
		if(charnum[str[i]-'a']==1){
			haveans=1;
			printf("%c\n",str[i]);
			break;
		}
	if(!haveans)printf("no\n");
	return 0;
}