/*
《算法基础与在线实践》例题2-4 装箱问题 POJ1017
*/
#include<cstdio>
int left[]={0,5,3,1};//3x3盒取余数，剩余空间可以放2x2盒子的数量


int main(){
	int k1,k2,k3,k4,k5,k6;
	while( 1 ){
		scanf("%d%d%d%d%d%d",&k1,&k2,&k3,&k4,&k5,&k6);
		if(k1+k2+k3+k4+k5+k6 ==0)break;
		int sum=k6+k5+k4;//这三种产品，每一个都需要一个箱子
		sum+=(k3+3)/4;//1个箱子可以放4个3x3，但1个3x3也要一个箱子
		int left2=k4*5+left[k3%4];//4x4和3x3需要的箱子，空余的2x2的数量
		if(k2>left2)
			sum+=(k2-left2+8)/9;//剩余2x2的数量不够，则需增加箱子数量
		//计算剩余的1x1的数量
		//把所有的产品占用空间，全部转换成1x1
		int x1=sum*36-k6*36-k5*25-k4*16-k3*9-k2*4;
		if(k1>x1)
			sum+=(k1-x1+35)/36;

		printf("%d\n",sum );
	}
	return 0;
}