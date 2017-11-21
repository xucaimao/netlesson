/*
程序设计实习MOOC / 程序设计与算法（一）第三周测验(2017冬季)  
5:简单计算器
复习了switch的用法
*/

#include<cstdio>

int main(){
	int x,y;
	char c;
	scanf("%d%d",&x,&y);
	getchar();
	c=getchar();
	switch(c){
		case'+':
			printf("%d\n",x+y );
			break;
		case'-':
			printf("%d\n",x-y );
			break;
		case'*':
			printf("%d\n",x*y );
			break;
		case'/':
			if(y==0)
				printf("Divided by zero!\n");
			else
				printf("%d\n",x/y );
			break;
		default:
			printf("Invalid operator!\n");
	}
			
	return 0;
}

