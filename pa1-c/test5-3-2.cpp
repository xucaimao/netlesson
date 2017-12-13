/*
程序设计实习MOOC / 程序设计与算法（一）第五周测验(2017冬季)  
3:年龄与疾病
打印%;四个值相加应该等于100%
write by xucaimao,2017-12-05-18:56
*/

#include<cstdio>
#include <cstring>
int main(){
	freopen("in.txt","r",stdin);
	int d[4];
	int year,num=0,n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&year);
		if(year>=0 && year<=18){d[0]++;num++;}
		else if(year>=19 && year<=35){d[1]++;num++;}
		else if(year>=36 && year<=60){d[2]++;num++;}
		else if(year>=61){d[3]++;num++;}
	}
	int p=10000;
	for(int i=0;i<3;i++){
		int s=(int)(d[i]*10000.0/num+0.5);
		p-=s;
		printf("%.2f%%\n",s/100.0);
	}
	printf("%.2f%%\n",p/100.0);
	return 0;
}

