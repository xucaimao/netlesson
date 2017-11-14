//中国大学MOOC-陈越、何钦铭-数据结构-起步能力自测题-1 打印沙漏
//write by xucaimao ;20171107-13:00

#include<cstdio>

int caculine(int * n){
	//给定n个符号，返回可以打印的图形总行数
	//同时将剩余的字符通过*n返回
	int sum=1;
	int line=1;//start at 1 lines

	while(1){
		if( (sum+(line+2)*2) <= *n){
			line+=2;
			sum+=line*2;
		}
		else break;	
	}
	*n-=sum;
	return line;
}

int main(){
	int N,l,n;
	char c;
	scanf("%d",&N);
	n=N;
	getchar();
	c=getchar();
	l=caculine(&n);//总行数也就是最长一行的字符数
	for(int i=l;i>0;i-=2){//打印上面一半及中间行
		for(int j=0;j<(l-i)/2;j++)
			printf(" ");
		for(int j=0;j<i;j++)
			printf("%c",c);
		printf("\n");
	}
	for(int i=3;i<=l;i+=2){//打印下面一半
		for(int j=0;j<(l-i)/2;j++)
			printf(" ");
		for(int j=0;j<i;j++)
			printf("%c",c);
		printf("\n");
	}
	printf("%d\n",n);
	return 0;
}