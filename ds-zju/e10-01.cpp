/*中国大学MOOC-陈越、何钦铭-数据结构-2018秋
 * 10-排序4 统计工龄
 * wirte by xucaimao,2018-11-04
 * */
#include <iostream>
using namespace std;
const int maxN=51;
int data[maxN];
int main(){
    int n,age;
    freopen("/Users/xcm/xcmprogram/netlesson/ds-zju/in.txt","r",stdin);
    cin>>n;
    while(n--){
        cin>>age;
        data[age]++;
    }
    for(int i=0;i<=50;i++){
        if(data[i]!=0)
            cout<<i<<":"<<data[i]<<endl;
    }
    return 0;
}