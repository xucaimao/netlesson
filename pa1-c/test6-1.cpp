/*
程序设计实习MOOC / 程序设计与算法（一）第六周测验(2017冬季)  
1:Pell数列
题目没看清楚就做题，很要命的事情
write by xucaimao,2017-12-12 12:55,AC
*/

#include<cstdio> 
const int maxn=1000000+100;
const int M=32767;
int pell[maxn]={0};

int main(){
	freopen("in.txt","r",stdin);
	pell[1]=1;
	pell[2]=2;
	for(int i=3;i<maxn;i++)
		pell[i]=(2*pell[i-1]+pell[i-2])%M;
	int n,k;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&k);	
		printf("%d\n",pell[k]);
	}
	return 0;
}