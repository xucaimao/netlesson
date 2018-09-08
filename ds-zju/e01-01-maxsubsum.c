/*
中国大学MOOC-陈越、何钦铭-数据结构-2018春
编程题 01-复杂度1 最大子列和问题
write by xucaimao,2018-03-09 20:30
*/

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100010

int Data[MAXSIZE];

int maxsubsum(int arr[],int num){
	int maxsum=0,cursum=0,i=0;
	for(i=0;i<num;i++){
		cursum+=arr[i];
		if(cursum<0)
			cursum=0;
		else if(cursum>maxsum)
			maxsum=cursum;
	}
	return maxsum;
}

int main()
{
	int k,i,ans;
    scanf("%d", &k);
    for(i=0;i<k;i++)
    	scanf("%d", &Data[i]);
   	ans=maxsubsum(Data,k);
   	printf("%d\n",ans );

    return 0;
}


