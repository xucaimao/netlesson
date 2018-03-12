#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10010

int Data[MAXSIZE];
int start,end;

int maxsubsum(int arr[],int num){
    int maxsum=0,cursum=0,i=0;
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
    return maxsum;
}

int main()
{
    int k,i,ans;
    scanf("%d", &k);
    for(i=0;i<k;i++)
        scanf("%d", &Data[i]);
    start=0;
    end=k-1;
    ans=maxsubsum(Data,k);
    printf("%d ",ans );
    //if(ans==0)
    //printf("%d %d\n",Data[0],Data[k-1] );
    //else
    printf("%d %d\n",Data[start],Data[end] );

    return 0;
}