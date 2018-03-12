/*中国大学MOOC-陈越、何钦铭-数据结构-2018春
 * 01-复杂度1 最大子列和问题
 * write by xucaimao,2018-03-12
 * 
 * */
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10010

int Data[MAXSIZE];
int start,end;

int maxsubsum(int arr[],int num){
    int maxsum=-1,cursum=0,i=0;
    int curstart=0;
    for(i=0;i<num;i++){
        cursum+=arr[i];
        if(cursum<0){
            cursum=0;
            curstart=i+1;
        }
        else if(cursum>maxsum){
            maxsum=cursum;
            start=curstart;
            end=i;
        }
    }
    if(maxsum<0)maxsum=0;
    return maxsum;
}

int main()
{
    int k,i,ans;
    //freopen("f:\\xcmprogram\\clion\\maxsubsq\\in.txt","r",stdin);
    scanf("%d", &k);
    for(i=0;i<k;i++)
        scanf("%d", &Data[i]);
    start=0;
    end=k-1;
    ans=maxsubsum(Data,k);
    //printf("start= %d end= %d\n",start,end );
    printf("%d ",ans );
    printf("%d %d\n",Data[start],Data[end] );
    return 0;
}