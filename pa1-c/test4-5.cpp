/*
程序设计实习MOOC / 程序设计与算法（一）第四周测验(2017冬季)  
5:雇佣兵
题目好久才看明白，老了！！居然折腾了一个小时！
write by xucaimao,2017-11-28-21:12
*/

#include<cstdio>
#include <cstring>
int main(){
	int M,N,X,m=0;
	scanf("%d%d%d",&M,&N,&X);
	while(X>0){
		while(m<M && X>0){//把体力增加到M
			X--;//能量块减一
			m+=N;//体力增加了战斗力的值
		}
		if(m>M)m=M;//体力值的增加是有限的
		if(m==M){//体力值为M时，才可以参加战斗
			N=N+M/N;//当连续战斗天数大于等于N时，才会让战斗力增加
			m=0;	
		}
	}
	printf("%d\n",N );
	return 0;
}

