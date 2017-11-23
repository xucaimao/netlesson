/*
《算法基础与在线实践》练习题4-1 菲波那契数列 POJ2753
write by xucaimao,20171122 17:40测试通过
*/
#include<cstdio>

int fab(int n){
	if(n==1 || n==2)return 1;
	else return fab(n-1)+fab(n-2);
}

int main(){
	int n;
	scanf("%d",&n);
	int t=n;
	while(t--){
		int a;
		scanf("%d",&a);
		printf("%d\n",fab(a) );
	}
	
	return 0;
}