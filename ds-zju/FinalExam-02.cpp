/* 期末考试
 * 下列代码的功能是将一列元素{ r[1] … r[n] }按非递减顺序排序。普通选择排序是每次仅将一个待排序列的最小元放到正确的位置上，
 * 而这个另类的选择排序是每次从待排序列中同时找到最小元和最大元，把它们放到最终的正确位置上。
 * 样例 5 8 7 6 4 2 3 0 1 9
 * */
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=11;
int r[maxn];
void  mysort( int r[], int n )
{
    int i, j, mini, maxi;

    for (i=1; i<n-i+1; i++) {
        mini = maxi = i;
        for( j=i+1; j<=n-i+1; ++j ){
            //在r[j..n-i+1]查找最大和最小值，并记录下标
            if(r[j]<r[mini]) mini = j;
            else if(r[j] > r[maxi]) maxi = j;
        }
        //mini !=i 说明有元素值比r[i]小，mini值发生了改变
        if( mini !=i )
            swap(r[mini], r[i]);
        //最大值不在本次区间的最后一位，才执行下面的交换操作。否则不执行交换。
        if( maxi != n-i+1 ){
            if( maxi==i )
                // 说明最大值为r[i]
                // 1.r[i]在前面已经与r[mini]发生了交换，最大值变成了r[mini]，所以要执行下面的语句
                // 2.前面mini==i，没有执行swap(r[mini], r[i])，加上maxi==i，说明三者值一样，
                // 此时执行下面的交换也不会导致程序错误
                swap(r[mini], r[n-i+1]);
            else
                swap(r[maxi], r[n-i+1]);
        }
    }
}

int main(){
    freopen("in.txt","r",stdin);
    for(int i=1;i<=10;i++)
        cin>>r[i];
    for(int i=1;i<=10;i++)
        cout<<r[i]<<" ";
    cout<<endl;
    mysort(r,10);
    for(int i=1;i<=10;i++)
        cout<<r[i]<<" ";
    cout<<endl;

}