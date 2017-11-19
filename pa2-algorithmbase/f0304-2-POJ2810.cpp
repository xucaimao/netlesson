/*
《算法基础与在线实践》例题3-4 完美立方 POJ2810
write by xucaimao,20171118,23:45测试通过
四重循环简化为三重，同时对三次方的计算一次到位
内存:196kB    时间:60ms
此方法，在数据量小的时候没有优势
*/
const int maxn=101;
#include<cstdio>
#include <cmath>
using namespace std;
int cube[maxn];
int main() {
	for(int i=1;i<maxn;i++)
		cube[i]=i*i*i;
	int n;
	scanf("%d",&n);
	for(int a=6;a<=n;a++)
		for(int b=2;b<=a-3;b++)
			for(int c=b+1;c<=a-2;c++){
				int t=cube[a]-cube[b]-cube[c];
				double dd=pow(t,1.0/3);
				int d=(int)(dd+0.5);//四舍五入
				if( abs(dd-d) < 1e-6 && d>c && c>b)
					printf("Cube = %d, Triple = (%d,%d,%d)\n",a,b,c,(int)d);
			}
	return 0;
}
