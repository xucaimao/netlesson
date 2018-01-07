/*中国大学MOOC《C语言程序设计进阶》期末考试编程题 
2分数比较
write by xucaimao at 2018-01-03-16:30
采用插入排序
*/
#include <stdio.h>
const double eps=1e-8;

int main(){
	//freopen("in.txt","r",stdin);
	int a,b,c,d;
	double f1,f2;
	scanf("%d",&a);
	getchar();//忽略除号
	scanf("%d",&b);
	f1=a*1.0/b;

	scanf("%d",&c);
	getchar();//忽略除号
	scanf("%d",&d);
	f2=c*1.0/d;
	double delt=f1-f2;
	//printf("%lf\n",delt );
	printf("%d/%d ",a,b );
	if( delt > eps)
		printf(">");
	else if( delt < eps*-1)
		printf("<" );
	else
		printf("=" );
	printf(" %d/%d\n",c,d );
	return 0;
}