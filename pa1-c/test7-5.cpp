/*
程序设计实习MOOC / 程序设计与算法（一）第七周测验(2017冬季)  
5:密码翻译
write by xucaimao,2017-12-18 18:10,AC 
*/

#include<cstdio>

int main(){
	freopen("in.txt","r",stdin);
	char ch;

	while( (ch=getchar())!=EOF ){
		//读入的时候同时统计最长与最短单词
		if(ch=='\n')break;
		if(ch=='z')ch='a';
		else if(ch=='Z') ch='A';
		else if( (ch>='a' && ch<'z')||(ch>='A' && ch<'Z') ) ch=ch+1;
		printf("%c",ch );		
	}
	printf("\n");

	return 0;
}