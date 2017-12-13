/*
程序设计与算法（二）第四周测验 2:派 
write by xucaimao,2017-12-13
*/
#include<cstdio>
#include <ctime>
#include <iostream>
using namespace std;

const int maxn=10000+10;
const double pi=3.141592654;
const double eps=1e-8;
double pie[maxn];//记录每个派的底面积
int n=0,f=0;

bool judge(double area){
	//如果每个人分得area大小的派，能否够分
	int sum=0;
	for(int i=0;i<n;i++)
		sum+=(int)pie[i]/area;//每块派能分成几份(取整)
	if(sum>=f+1)return true;
	else return false;
}

double solve(double left,double right){
	//二分法查找
	double mid=0;
	while(right-left >eps){
		mid=left+(right-left)/2.0;
		if(judge(mid))//够分，应该加大
			left=mid;
		else//不够分，应该减小
			right=mid;
	}
	return mid;
}

int main(){
	int r;
	double maxarea=0;
	scanf("%d%d",&n,&f);
	for(int i=0;i<n;i++){
		//读入派的半径，转换成面积储存，同时记录最大面积
		scanf("%d",&r);
		pie[i]=pi*r*r;
		if(pie[i]>maxarea)
			maxarea=pie[i];
	}
	printf("%.3lf\n", solve(0.0,maxarea) );
	return 0;
}