#include<cstdio>
#include<cmath>
#include<cstring>
const int maxn=100010;
int prime[maxn];

int main(){
  for(int i=2;i<maxn;i++)
    prime[i]=1;
  int sq=sqrt(maxn)+1;
  bool ok=true;
  prime[0]=0;
  prime[1]=0;
  for(int i=2;i<sq;i++){
    for(int j=i*i;j<maxn;j+=i){ 
     prime[j]=0;
    }
  }
  //for(int i=2;i<maxn;i++)
    //if(prime[i]) printf("%d ",i);

  int N,tot=0,n=2,n1=3;
  scanf("%d",&N);
  while(n1<=N){
    if( (n1-n) ==2 )tot++;
    n=n1;
    n1++;
    while(!prime[n1])
      n1++;
    //printf("%d ",n1); 
  }
  printf("%d\n",tot);
  return 0;
}