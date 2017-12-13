/*
程序设计与算法（二）算法基础 第四周 二分 例题2
《算法基础与在线实践》例题5.3 在线翻译 POJ2503
write by xucaimao,2017-12-09 21:30,AC 2017-12-09 22:11:04

extern int strcmp(const char *s1,const char *s2);
若str1==str2，则返回零；
若str1<str2，则返回负数；
若str1>str2，则返回正数。

重点是结构体元素的大小比较，可以采用两种形式：
1.重载<运算符。需要注意在结构体内、外重载时，函数的区别(friend友元)
2.自定义大小比较函数，在sort()中作为参数调入

*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=100000+10;

struct Dict
{
	char english[11];
	char foreign[11];

	friend bool operator<(const Dict &a,const Dict &b){
		return strcmp(a.foreign,b.foreign)<0;
	}
}dict[maxn];



bool dictcmp(Dict &a,Dict &b){
	return strcmp(a.foreign,b.foreign)<0;
}

int main(){
	freopen("f0503.in","r",stdin);
	int num=0;
	char fword[11];
	while(1){
		//读入字典数据
		scanf("%s%s",dict[num].english,dict[num].foreign);
		num++;
		getchar();//忽略行尾
		if(cin.peek()=='\n'){getchar();break;}
	}

	sort(dict,dict+num);//排序
	//下面为采用自定义比较函数的方法
	//sort(dict,dict+num,dictcmp);
	while(scanf("%s",fword) != EOF){
		//在dict[left...right]中查找
		int left=0,right=num-1;
		int cmp=0;
		while(left<=right){
			int mid=left+(right-left)/2;
			cmp=strcmp(dict[mid].foreign,fword);
			if( cmp<0 )left=mid+1;
			else if(cmp>0)right=mid-1;
			else {printf("%s\n",dict[mid].english );break;}
		}
		if(cmp!=0)printf("eh\n");
	}
	return 0;
}