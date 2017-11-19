/*
《算法基础与在线实践》例题3-3 生理周期 POJ4148
write by xucaimao,20171118,23:45测试通过
三重循环,内存:136kB  时间:1ms
*/
#include<cstdio>
const int maxn=21252;

int main() {
	freopen("f0301.in","r",stdin);
	int p,e,i,d;
	int T=0;
	while(1){
		scanf("%d%d%d%d",&p,&e,&i,&d);
		if(p==-1)break;
		T++;
		int k=d+1;
		for(;(k-p)%23 && k<=maxn;k++)//先找到体力周期
		for(;(k-e)%28 && k<=maxn;k+=23);//再找情感和体力的共同日期
		for(;(k-i)%33 && k<=maxn;k+=23*28);//再找三个的共同周期
		printf("Case %d: the next triple peak occurs in %d days.\n",T,k-d);
	}
	
}
