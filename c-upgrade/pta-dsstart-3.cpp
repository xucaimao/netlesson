//中国大学MOOC-陈越、何钦铭-数据结构-起步能力自测题-3 数组元素循环右移
//write by xucaimao ;20171107-23:00
/*
在纸上推导了很多次，发现有两种情况：
一种一次循环就可以交换完毕。比如7 2,1 2 3 4 5 6 7的情况，6>t,4>6,2>4,0>2,5>0,3>5,
1>3,t>1;
一种需要两次循环才能交换完毕。比如6 2，1 2 3 4 5 6的情况，第一次5>t,3>5,1>3,t>1；
第二次4>t,2>4,0>2,t>0;
两种情况下，每一次循环元素交换的次数减一，再累加，总数和数组的元素数量是相等的，可以根据
这个作为交换结束的标志。
*/
#include<cstdio>
 const int maxn=100+10;
 int A[maxn];
 
 int main(){
   int N,M,swaptime=0;
   scanf("%d%d",&N,&M);
   for(int i=0;i<N;i++)
    scanf("%d",&A[i]);
    M=M%N;
    
    for(int i=1;i<=2;i++){//最多循环两次
      int p=N-i,pre;
      if(p>=M)pre=p-M;
      else pre=N+(p-M)%N ;
      int t=A[p];//此次交换不计入swaptime，后面的每次交换都计入
      while(pre!=p){
        A[p]=A[pre];//后移
        swaptime++;
        p=pre;
        if(pre>=M)pre-=M;
        else pre=N+(pre-M)%N;
        if(pre==(N-i)){
          A[p]=t;
          swaptime++;
          break;
        }
      }
      if(swaptime==N)break;
    }
    
    for(int i=0;i<N;i++){
      if(i>0)printf(" %d",A[i]);
      else printf("%d",A[i]);
    }
    printf("\n");
    return 0;
 }