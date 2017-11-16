/*
《算法基础与在线实践》练习题3-4 砝码称重 POJ4141
write by xucaimao,20171116 22:40

*/
#include<cstdio>
const int maxn=1001;
bool value[maxn]={0};

int main(){
	int a1,a2,a3,a4,a5,a6;
	scanf("%d%d%d%d%d%d",&a1,&a2,&a3,&a4,&a5,&a6);
	for(int n1=0;n1<=a1;n1++)
		for(int n2=0;n2<=a2;n2++)
			for(int n3=0;n3<=a3;n3++)
				for(int n4=0;n4<=a4;n4++)
					for(int n5=0;n5<=a5;n5++)
						for(int n6=0;n6<=a6;n6++){
							int t=n1+n2*2+n3*3+n4*5+n5*10+n6*20;
							value[t]=1;
						}
	int sum=0;
	for(int i=1;i<maxn;i++)
		if(value[i])sum++;	
	printf("Total=%d\n",sum );
	return 0;
}