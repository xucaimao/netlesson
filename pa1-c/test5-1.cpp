/*
程序设计实习MOOC / 程序设计与算法（一）第五周测验(2017冬季)  
1:与指定数字相同的数的个数

write by xucaimao,2017-12-05-18:50
*/

#include<cstdio>
#include <cstring>
int main(){
	int d[110];
	int n,m,num=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&d[i]);
	scanf("%d",&m);
	for(int i=0;i<n;i++)
		if(d[i]==m)num++;
	printf("%d\n",num);
	return 0;
}

