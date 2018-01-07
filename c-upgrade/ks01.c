/*中国大学MOOC《C语言程序设计进阶》期末考试编程题 
1最小包围矩形
write by xucaimao at 2018-01-03-16:20
*/
#include <stdio.h>

int main(){
	freopen("in.txt","r",stdin);
	int n,x,y;
	int maxx,maxy,minx,miny;
	scanf("%d",&n);
	scanf("%d%d",&x,&y);
	minx=x;
	maxx=x;
	miny=y;
	maxy=y;
	for(int i=2;i<=n;i++){
		scanf("%d%d",&x,&y);
		if(x>maxx)maxx=x;
		if(x<minx)minx=x;
		if(y>maxy)maxy=y;
		if(y<miny)miny=y;
	}
	printf("%d %d %d %d\n",minx,miny,maxx,maxy );
	return 0;
}