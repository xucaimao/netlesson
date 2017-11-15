/*
《算法基础与在线实践》例题2-1 鸡兔同笼 POJ3237
*/
#include<cstdio>

int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		int legs;
		scanf("%d",&legs);
		if(legs%4==0)
			printf("%d %d\n",legs/4,legs/2 );
		else if(legs%2==0)
			printf("%d %d\n",legs/4+1,legs/2 );
		else
			printf("0 0\n");
	}
	return 0;
}