/*
《算法基础与在线实践》练习题3-1 数字三元组 POJ4146
write by xucaimao,20171116 22:00
*/
#include<cstdio>

int main(){
	int n;
	scanf("%d",&n);
	int maxa1=0,maxa2=0,maxa3=0;
	int maxsum=0;
	for(int a1=0;a1<=n;a1++)
		for(int a2=0;a2<=n;a2++)
			for(int a3=0;a3<=n;a3++)
				if( (a1+a2)%2==0 && (a2+a3)%3==0 &&(a1+a2+a3)%5==0 ){
					int t=a1+a2+a3;
					if( t>maxsum){
						maxsum=t;
						maxa1=a1;maxa2=a2;maxa3=a3;
					}
					
				}
	printf("%d\n",maxsum );
	return 0;
}