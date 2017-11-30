/*
程序设计实习MOOC / 程序设计与算法（一）第四周测验(2017冬季)  
2:正常血压
write by xucaimao,2017-11-28-19:30
t=0 是重点
*/

#include<cstdio>

int main(){
	freopen("test4-2.in","r",stdin);
	int timemax=0,t=0;
	int in,out;
	int n;
	scanf("%d",&n);
	while(n--){
		scanf("%d%d",&in,&out);
		if(in>=90 && in<=140 && out>=60 && out<=90){
			t++;
			if (t>timemax) timemax=t;
		}
		else
			t=0;
	}
	printf("%d\n",timemax);
	return 0;
}

