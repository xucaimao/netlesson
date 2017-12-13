/*
程序设计与算法（二）第五周测验 1:输出前k大的数 
采用库函数sort进行排序，学习sort的用法(边界、逆序、自定义比较函数)
write by xucaimao,2017-12-13
*/
#include<cstdio>
#include <ctime>
#include <iostream>
#include <algorithm>
using namespace std;

const int maxn=100000+10;
int data[maxn];
int k=0;

bool comp(int a,int b){
	return a>b;
}

int main(){
	freopen("cy0501.in","r",stdin);
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&data[i]);
	scanf("%d",&k);
	//注意后面是加n
	sort(data,data+n,comp);
	for(int i=0;i<k;i++)
		printf("%d\n",data[i] );
	return 0;
}