/*
程序设计实习MOOC / 程序设计与算法（一）第三周测验(2017冬季)  
8:奥运奖牌计数

*/

#include<cstdio>

int main(){
	int n,gold=0,silver=0,copper=0;
	scanf("%d",&n);
	int t=n;
	while(t--){
		int g,s,c;
		scanf("%d%d%d",&g,&s,&c);
		gold+=g;
		silver+=s;
		copper+=c;
	}
	printf("%d %d %d %d\n",gold,silver,copper,gold+silver+copper );	
	return 0;
}

