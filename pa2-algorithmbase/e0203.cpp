/*
《算法基础与在线实践》练习题2-3 闰年 POJ2733
*/
#include<cstdio>

int main(){
	int n;
	scanf("%d",&n);
	if( (n%4 ==0 && n%100 !=0) || n%400 ==0 )printf("Y\n");
	else printf("N\n");
	return 0;
}