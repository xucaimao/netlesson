/*
程序设计实习MOOC / 程序设计与算法（一）第七周测验(2017冬季)  
1:统计数字字符个数
write by xucaimao,2017-12-18 16:30,AC 
*/

#include<cstdio>

bool isdigt(char ch){
	return ch>='0' && ch<='9';
}
int main(){
	char ch;
	int sum=0;
	while( (ch=getchar())!='\n' ){
		if(isdigt(ch))sum++;
	}
	printf("%d\n",sum );
	return 0;
}