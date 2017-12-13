/*
程序设计实习MOOC / 程序设计与算法（一）第五周测验(2017冬季)  
2:陶陶摘苹果

write by xucaimao,2017-12-05-18:54
*/

#include<cstdio>
#include <cstring>
int main(){
	int d[15];
	int h,num=0;
	for(int i=0;i<10;i++)
		scanf("%d",&d[i]);
	scanf("%d",&h);
	for(int i=0;i<10;i++)
		if(d[i]<=h+30)num++;
	printf("%d\n",num);
	return 0;
}

