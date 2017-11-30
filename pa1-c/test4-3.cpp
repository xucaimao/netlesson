/*
程序设计实习MOOC / 程序设计与算法（一）第四周测验(2017冬季)  
3:数字反转
write by xucaimao,2017-11-28-19:45
*/

#include<cstdio>
#include <cstring>
int main(){
	char s[15];
	scanf("%s",s);
	int len=strlen(s);
	int start=0;
	int end=len-1;
	if(s[0]=='-'){
		printf("-");
		start++;
	}
	while(s[end]=='0')end--;
	for(int i=end;i>=start;i--)
		printf("%c",s[i] );
	printf("\n");
	return 0;
}

