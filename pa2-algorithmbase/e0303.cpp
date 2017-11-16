/*
《算法基础与在线实践》练习题3-3 不定方程求解 POJ4139
write by xucaimao,20171116 22:30
根据方程的非负性，求出x和y的取值范围，再进行枚举
*/
#include<cstdio>
#include<cmath>

int main(){
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	int maxx=c/a;
	int maxy=c/b;
	int sum=0;
	for(int x=0;x<=maxx;x++)
		for(int y=0;y<=maxy;y++)
			if( (a*x+b*y)==c )sum++;		
	printf("%d\n",sum );
	return 0;
}