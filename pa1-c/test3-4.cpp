/*
程序设计实习MOOC / 程序设计与算法（一）第三周测验(2017冬季)  
4:苹果和虫子2
*/

#include<cstdio>

int main(){
	int n,x,y;
	scanf("%d%d%d",&n,&x,&y);
	int left=n-(y+x-1)/x;//此处是重点
	if(left<0)left=0;//此处的判断必须有
	printf("%d\n",left);
			
	return 0;
}

