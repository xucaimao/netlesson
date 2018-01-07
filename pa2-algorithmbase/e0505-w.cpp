#include<stdio.h>  
#include<math.h>  
#include<iostream>  
using namespace std;  
struct obj  
{  
    long long left,top,w,h;  
    long long rx;  
    long long s;  
};  
long long sigema(struct obj a[],int n,int mid){
    //求左右两半面积的差值  
    int i;  
    long long sum1,sum2;  
    sum1=sum2=0;  
    for(i=0;i<n;i++)  
    {  
        if(a[i].rx<=mid) sum1+=a[i].s;  
        else if(a[i].left>=mid) sum2+=a[i].s;  
        else  
        {  
            sum1+=a[i].h*(mid-a[i].left);  
            sum2+=a[i].h*(a[i].rx-mid);  
        }  
    }  
    return sum1-sum2;  
}  
int main()  
{
    freopen("e0505.in","r",stdin);  
    long long r,n,i;  
    struct obj a[10005];  
    long long left,right,mid,ans,MAXx;  
    long long temp,temp1,temp2;  
    int T;
    scanf("%d",&T);
    while(T--){
       scanf("%lld%lld",&r,&n);
        for(i=0;i<n;i++)  
        {  
            scanf("%lld%lld%lld%lld",&a[i].left,&a[i].top,&a[i].w,&a[i].h);  
            a[i].s=a[i].w*a[i].h;  
            a[i].rx=a[i].left+a[i].w;  
            if(i==0)  MAXx=a[i].rx;  
            else  
            {  
                if(a[i].rx>MAXx) MAXx=a[i].rx;  
            }  
        }  
        left=0;  
        right=r;  
        while(left+1<right)  
        {  
            mid=(left+right)/2;  
            temp=sigema(a,n,mid);
            printf("l=%lld mid=%lld r= %lld ",left,mid,right);
            printf("areadiff = %lld \n",temp);  
            if(temp>0) right=mid;  
            else if(temp<=0) left=mid;  
        } 
        printf("End: l=%lld r= %lld \n",left,right); 
        temp1=sigema(a,n,left);  
        temp2=sigema(a,n,right);  
        if( temp1<temp2)  
        {  
            if(temp1>=0) ans=left;  
            else ans=right;  
        }  
        else if(temp1>temp2)  
        {  
            if(temp2>=0) ans=right;  
            else ans=left;  
        }  
        else ans=right;  
        if(ans==MAXx) ans=r;  
        printf("%lld\n",ans); 
    }  
    return 0;  
}  
