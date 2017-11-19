/*
《算法基础与在线实践》例题3-4 完美立方 POJ2810
write by xucaimao,20171118,23:45测试通过
这么水的题，提交居然一次WA,一次PE,第三次才过 
四重循环,内存:196kB  时间:18ms
*/

#include<cstdio>

int main() {
	int n;
	scanf("%d",&n);
	for(int a=2;a<=n;a++)
		for(int b=2;b<=a-3;b++)
			for(int c=b+1;c<=a-2;c++)
				for(int d=c+1;d<=a-1;d++)
					if(a*a*a==b*b*b+c*c*c+d*d*d)
						printf("Cube = %d, Triple = (%d,%d,%d)\n",a,b,c,d);
	return 0;
}
