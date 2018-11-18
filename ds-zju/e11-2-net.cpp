/*中国大学MOOC-陈越、何钦铭-数据结构-2018秋
 * 11-散列2 Hashing （25 分）
 * 网络程序
 * */
#include <stdio.h>
#include <vector>
#include <string.h>
#include <math.h>
#include <iostream>
using namespace std;
int NextPrime ( int N ) {
    if ( N == 1 ) //1既不是素数，也不是合数； 2是素数
        return 2;
    int i, p = ( N % 2 ) ? N + 2 : N + 1;
    while (1) {
        double q = p;
        for ( i = sqrt(q); i > 2; i-- )
            if ( !( p % i ) ) break;
        if ( i == 2 ) return p;
        else p += 2;
    }
}
int IsPrime ( int n ) {
    if ( n == 1 )
        return 0;
    else if ( n == 2 )
        return 1;
    else {
        int k = sqrt(n);
        for ( int i = 2; i <= k; i++ )
            if ( n % i == 0 )
                return 0;
        return 1;
    }
}
int tables[10009];
int main () {
    freopen("/Users/xcm/xcmprogram/netlesson/ds-zju/in.txt","r",stdin);
    //freopen("/Users/xcm/xcmprogram/netlesson/ds-zju/out-net.txt","w",stdin);
    int size,n,m,key,pos,k,tmp;
    cin>>n>>m;
    if(IsPrime(n))
    {
        size=n;
    }else
    {
        size=NextPrime(n);
    }
    for(int i=0;i<size;i++)
        tables[i]=0;
    for ( int i = 0; i < m; i++ ) {
        cin >> key;
        pos = key % size;
        k = 0; tmp = pos;
        while ( k < size ) {
            if ( tables[pos] == 0 ) {
                tables[pos] = key;
                cout << pos;
                break;
            }
            else {
                k++;
                pos = ( tmp + k * k ) % size;
            }
        }
        if ( k == size ) //没找到
            cout <<"-";
        if ( i != m - 1 )
        {
            cout <<" ";
        }//最后一个元素后面不要空格
    }
    return 0;
}
