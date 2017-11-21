/*
程序设计与算法（二）算法基础 第二周 递归 例题2
《算法基础与在线实践》第四章 例题5
 n皇后问题 
write by xucaimao,20171121
*/

#include <cstdio>

void hannoi(int n,char src,char mid,char tag){
	//把n个盘子，从src借助mid移动到tag
	if(n==1){
		printf("%c -> %c \n",src,tag );
		return;
	}
	hannoi(n-1,src,tag,mid);//把n-1个盘子从src借助tag移动到mid
	printf("%c -> %c \n",src,tag );//把最后一个盘子从src移动到tag
	hannoi(n-1,mid,src,tag);//把n-1个盘子从mid借助src移动到tag
}

int main(){
	int n;
	scanf("%d",&n);
	hannoi(n,'A','B','C');
	return 0;
}