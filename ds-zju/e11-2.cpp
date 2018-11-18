/*中国大学MOOC-陈越、何钦铭-数据结构-2018秋
 * 11-散列2 Hashing （25 分）
 * wirte by xucaimao,2018-11-13
 哈希函数采用二次探测法，同时明确只采用正增加
 输入的TableSize不一定是素数，如果不是，则需要根据数据量重新选择，大于数据量的最小素数
 对于二次探测，有可能会出现找不到插入位置的情况，这也是本题考查的重点

 对于平方探测，如果散列表长度是4k+3形式的素数，平方探测法可以探查到整个散列空间，但是这里
 的题目给出的是素数，因此存在散列表内即使有空间，也不能放进去的情况，我想的时候主要是在考虑
 什么情况下才能判断这个元素即使增量一直增大也不能放进去呢？

这一道题的难点在于对于那些永远无法插入的数字，何时可以断定它无法插入。
冲突解决方法是平方探测，且只有正数，那么每次冲突后的增量便是：1^2, 2^2, 3^2, 4^2, … ,
 tableSize^2,(tableSize+1)^2, (tableSize+2)^2, …
当达到（tableSize + i）^2 = tableSize*tableSize + 2*tableSize*i + i^2 时，我们就
 发现 ，它展开之后对tableSize取余，有影响的只有i，而i已经算过了。所以一旦增量达到tableSize^2，
 我们便可以断定该数字无法插入哈希表中了
采用下面的样例，很容易找到问题
11 11
10 6 4 15 7 5 3 2 1 11 18
正确答案:10 6 4 5 7 9 3 2 1 0 8
 * */

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

bool isPrime(int n){
    //判断2之后，就可以判断从3到sqrt(n)之间的奇数了，无需再判断之间的偶数
    if(n<=1)return false;
    if(n==2)return true;
    if(n%2==0)
        return false;
    int sn=sqrt(n);
    for(int i=3;i<sn;i+=2)
        if(n%i ==0)return false;
    return true;
}
//返回比n大的最小素数
int nextPrime(int n){
    while(!isPrime(n)){
        n++;
    }
    return n;
}

int myHash(int hashTable[],int tableSize,int n){
    //采用二次探测法，如果找不到合适位置，返回-1
    //当i >= tableSize 时开始从与i = 0重复，故仅需判断i <= tableSize即可；
    //开始时，没有完全理解下标移动的方式，导致错误
    int Pos=n%tableSize;
    int prePos=Pos;     //记录初始位置
    int step=0;
    while(step<=tableSize){
        if(hashTable[Pos]==-1 || hashTable[Pos]==n){
            hashTable[Pos]=n;
            break;
        }
        else{
            step++;
            Pos=(prePos+step*step)%tableSize;
        }
    }
    if(step>tableSize)return -1;
    else return Pos;
}

int main(){
    freopen("/Users/xcm/xcmprogram/netlesson/ds-zju/in.txt","r",stdin);
    //freopen("/Users/xcm/xcmprogram/netlesson/ds-zju/out-my.txt","w",stdin);
    int M,N,n;
    cin>>M>>N;
    if(!isPrime(M))
        M=nextPrime(M);
    int * hashTable=new int[M];
    for(int i=0;i<M;i++)
        hashTable[i]=-1;
    for(int i=0;i<N;i++){
        cin>>n;
        if(i>0) cout<<" ";
        int ans=myHash(hashTable,M,n);
        if(ans==-1)cout<<"-";
        else cout<<ans;
    }
    cout<<endl;
    return 0;
}