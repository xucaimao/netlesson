/*
程序设计与算法（二）第一周测验 特殊密码锁 POJ8469
write by xucaimao,20171115,23:00测试通过
每个按钮只有两种状态，凹或者凸，一旦第一个按钮的状态确定，后面的按钮状态也随之确定，就类似于蝴蝶效应，
所以一共只有两种情况，只需判别这两种情况是否成立，然后取其最小的次数。如果从第三位，第四位等等开始看也一样。

每一个按钮都是靠后一个按钮来确定状态的，如果符合密码，则后一个按钮不动，若不符合，则后一个按钮翻转。
我们所需做的就是让当前按钮之前的按钮都符合目的密码，当运行到最后一个按钮时，如果最后一个按钮如果符合
目的密码，此种方法即成立，否则不成立。

例如 011 000

第一位不动的情况：
①第一位符合，第二位不翻转；
②第二位不符合，第三位翻转，此时为000
③第三位符合，成立，输出次数。

第一位动：101
①第一位不符合，第二位翻转 010
②第二位不符合，第三位翻转001
③第三位不符合，不成立

*/
#include<cstdio>
#include<cstring>

void pressKey(char key[],int len,int n){
	//长度位len的密码锁key,按下第n个按钮
	if(n>=0 and n<len){
		if(key[n]=='0')key[n]='1';
		else key[n]='0';
		if(n>0){
			if(key[n-1]=='0')key[n-1]='1';
			else key[n-1]='0';
		}
		if(n<len-1){
			if(key[n+1]=='0')key[n+1]='1';
			else key[n+1]='0';
		}
	}
}

int main(){
	char sr[32],tr[32];//储存密码锁的初始与目标状态
	char tmp[32];//在此数组上进行实际操作
	freopen("in-2.txt","r",stdin);
	scanf("%s",sr);
	scanf("%s",tr);
	int len=strlen(sr);

	strcmp(tmp,sr);
	int sum1=0;
	for(int i=0;i<len-1;i++){
		if(tmp[i]!=tr[i]){
			pressKey(tmp,len,i+1);
			sum1++;
		}
	}
	if(tmp[len-1]!=tr[len-1])
		sum1=-1;
	
	strcmp(tmp,sr);
	pressKey(tmp,len,0);//首先按下第一个按钮
	int sum2=1;
	for(int i=0;i<len-1;i++){
		if(tmp[i]!=tr[i]){
			pressKey(tmp,len,i+1);
			sum2++;
		}
	}
	if(tmp[len-1]!=tr[len-1])
		sum2=-1;

	if(sum1==-1 && sum2==-1)
		printf("impossible\n");
	else{
		printf("%d\n",sum1<sum2 ? sum1:sum2);
	}
	return 0;
}