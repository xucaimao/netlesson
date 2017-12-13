/*
程序设计与算法（二）算法基础 第四周 二分 例题1
《算法基础与在线实践》例题5.2 方程求解 POJ4140 
write by xucaimao,20171206,AC 
由题知:f(0)=-80,f(10)=520.所以对应f(x)=0,
x的值一定在0与10之间,可以采用二分法求值

*/
#include <cstdio>

double f(double x){
	return x*x*x-5*x*x+10*x-80;
}

double myabs(int x){
	if(x<0)x*=-1;
	return x;
}

int main(){
	double left=0,right=10;
	double mid;
	double fx;
	while(right-left > 1e-11){
		//重点是这里的精度控制，不能直接控制fx的精度
		mid=left+(right-left)/2;
		fx=f(mid);
		if(fx>0)right=mid;
		else if(fx<0) left=mid;
	}
	printf("%.9lf\n", mid);
	return 0;
}