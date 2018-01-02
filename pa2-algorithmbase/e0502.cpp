/*
《算法基础与在线实践》练习题5-2 二分法求函数的零点 POJ4142
write by xucaimao,2017-12-15 23:35开始编程，AC 2017-12-15 20:24:48
*/
#include<cstdio>

double f(double x){
	return x*x*x*x*x-15*x*x*x*x+85*x*x*x-225*x*x+274*x-121;
}

int main(){
	//printf("f(1.5)= %.6lf\n",f(1.5) );
	//printf("f(2.4)= %.6lf\n",f(2.4) );
	double l=1.5,r=2.4;
	while(r-l>1e-10){
		double mid=l+(r-l)/2.0;
		if(f(mid)>0)
			l=mid;
		else
			r=mid;
	}
	printf("%.6lf\n",r );
	return 0;
}