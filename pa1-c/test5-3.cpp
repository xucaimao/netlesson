/*
程序设计实习MOOC / 程序设计与算法（一）第五周测验(2017冬季)  
3:年龄与疾病
打印%
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

	for(int i=0;i<4;i++)
		printf("%.2lf%%\n",(double)d[i]*100.0/num);
	return 0;
}

