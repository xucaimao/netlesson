//中国大学MOOC-陈越、何钦铭-数据结构-起步能力自测题-2 素数对猜想
//write by xucaimao ;20171107-20:00

#include<cstdio>
#include<cmath>
const int maxn=100010;
int prime[maxn];

int main(){
  for(int i=2;i<maxn;i++)
    prime[i]=1;
  int sq=sqrt(maxn)+1;
  prime[0]=0;
  prime[1]=0;
  for(int i=2;i<sq;i++)
    for(int j=i*i;j<maxn;j+=i)
      prime[j]=0;
    
  
  //for(int i=2;i<maxn;i++)
    //if(prime[i]) printf("%d ",i);

  int N,tot=0,n=2,n1=3;
  scanf("%d",&N);
  while(n1<=N){
    if( (n1-n) ==2 )tot++;
    n=n1;
    n1++;//指向下一个数字
    while(!prime[n1])//指向下一个素数
      n1++;
    //printf("%d ",n1); 
  }
  printf("%d\n",tot);
  return 0;
}