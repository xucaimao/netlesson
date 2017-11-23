/*
《算法基础与在线实践》练习题4-3 分解因数 POJ2749
write by xucaimao,20171122 20:40测试通过
*/
#include<cstdio>
#include <cstring>
const int maxn=10000;
int ans[maxn];//保存具体的解，如果不需要打印解，这个数组可以不要
int num=0;//具体解的数量

void factor(int m,int p){
	//找到第p个因数，存放在数组ans[p]
	if(m==1){
		//找到一种解
		num++;
		for(int i=0;i<p;i++){
			if(i>0)printf("*");
			printf("%d",ans[i]);
		}
		printf("\n");
	}
	else
		for(int i=2;i<=m;i++){//尝试所有可能的数
			if(m%i ==0 && (!p || i>=ans[p-1] ) ){
			//i是m的因数,还必须>=前一个因数
			// !p 是为了防止p=0时，p-1越界
				ans[p]=i;
				factor(m/i,p+1);
			}
	}
}

int main(){
	int m,n;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&m);
		memset(ans,0,sizeof(ans));
		num=0;
		factor(m,0);
		printf("%d\n",num);
	}
	return 0;
}