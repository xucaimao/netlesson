/*
程序设计与算法（二）算法基础 第四周 二分 例题3
《算法基础与在线实践》例题5.4 Values whose Sum is 0 POJ3441
write by xucaimao,2017-12-09 22:30,AC 

*/
#include <cstdio>
#include <algorithm>
const int maxn=4005;
const int maxnn=16000010;
int a[maxn],b[maxn],c[maxn],d[maxn];
int sum1[maxnn],sum2[maxnn];

int main(){
	freopen("f0504.in","r",stdin);
	int n=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
	int sn=0;
	//计算可能的和
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			sum1[sn]=a[i]+b[j];
			sum2[sn]=c[i]+d[j];
			sn++;
		}
		
	sort(sum1,sum1+sn);
	sort(sum2,sum2+sn);

	return 0;
}