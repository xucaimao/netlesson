/*
程序设计实习MOOC / 程序设计与算法（一）第三周测验(2017冬季)  
3:点和正方形的关系 
*/

#include<cstdio>

int main(){
	int x,y;
	scanf("%d%d",&x,&y);
	if(x<=1 && x>=-1 && y<=1 && y>=-1)
		printf("yes\n");
	else
		printf("no\n");
			
	return 0;
}

