/*
《算法基础与在线实践》练习题3-2 质数的和与积 POJ4138
write by xucaimao,20171116 22:15
*/
#include<cstdio>
#include<cmath>
const int maxn=10000+10;
bool isprime[maxn]={0};

void initprime(){
	for(int i=2;i<maxn;i++)
		isprime[i]=1;
	int sq=sqrt(maxn)+1;
	for(int i=2;i<sq;i++)
		for(int j=i*i;j<maxn;j+=i)
			isprime[j]=0;
}

int main(){
	initprime();
	int s;
	scanf("%d",&s);
	int maxa1=0,maxa2=0;
	long int maxsum=0;
	for(int a1=2;a1<=(s/2+1);a1++)
		for(int a2=2;a2<=(s-a1);a2++)
			if( isprime[a1] && isprime[a2] && (a1+a2)==s ){
				long int t=(long int)a1*a2;
				if (t>maxsum)maxsum=t;
			}
			
	printf("%ld\n",maxsum );
	return 0;
}