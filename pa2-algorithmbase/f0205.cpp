/*
《算法基础与在线实践》例题2-5 约瑟夫问题 POJ2746
do while用法掌握不清晰
*/
#include<cstdio>

const int maxn=301;
int monkey[maxn];

int main(){
	int n,m,left;
	while( 1 ){
		scanf("%d%d",&n,&m);
		if(n+m ==0)break;
		left=n;					//剩余猴子数量
		for(int i=1;i<=n;i++)
			monkey[i]=1;
		int p=1;				//指向猴子的指针
		while(left>1){
			int count=1;		//从1开始报数
			while(count<m){		//找第m个猴子
				do{				//找下一个猴子
					if(p+1>n)p=1;
					else p++;
				}while(monkey[p]==0);
				count++;
			}
			monkey[p]=0;		//第m个猴子出队
			left--;				//剩余猴子数减一

			do{				//找下一个猴子
				if(p+1>n)p=1;
				else p++;
			}while(monkey[p]==0);
		}
		for(int i=1;i<=n;i++)
			if(monkey[i]){
				printf("%d\n",i );
				break;
			}
	}
	return 0;
}