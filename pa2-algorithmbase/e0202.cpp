/*
《算法基础与在线实践》练习题2-2 细菌繁殖 POJ2712
*/
#include<cstdio>
#include<cmath>
int dayOfMonth[]={0,31,28,31,30,31,30,31,31,30,31,30,31};

int getDays(int m1,int d1,int m2,int d2){
	//求同一年内(不是闰年)两个日期之间的间隔天数
	if(m1==m2)return d2-d1;
	int day=d2;
	while(m2-1 > m1){
		day+=dayOfMonth[m2-1];
		m2--;
	}
	day += dayOfMonth[m1]-d1;
	return day;
}

long mypow(int m,int n){
	long res=m;
	while(n>1){
		res*=m;
		n--;
	}
	return res;
}

int main(){
	int n;
	int m1,d1,sum,m2,d2;
	scanf("%d",&n);
	while(n--){
		scanf("%d%d%d%d%d",&m1,&d1,&sum,&m2,&d2);
		int days=getDays(m1,d1,m2,d2);
		//printf("days is %d \n",days);
		//printf("power is %ld\n",mypow(2,days));
		long res=sum*mypow(2,days);
		printf("%ld\n",res);
	}
	return 0;
}